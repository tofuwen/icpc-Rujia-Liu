#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxnode = 4000 * 100 + 10;
const int sigma_size = 26 + 2;

struct Trie {
  int ch[maxnode][sigma_size];
  int val[maxnode];
  int sz; // 结点总数
  void clear() { sz = 1; memset(ch[0], 0, sizeof(ch[0])); } // 初始时只有一个根结点
  int idx(char c) { return c - 'a'; } // 字符c的编号

  // 插入字符串s，附加信息为v。注意v必须非0，因为0代表“本结点不是单词结点”
  void insert(const char *s, int v) {
    int u = 0, n = strlen(s);
    for(int i = 0; i < n; i++) {
      int c = idx(s[i]);
      if(!ch[u][c]) { // 结点不存在
        memset(ch[sz], 0, sizeof(ch[sz]));
        val[sz] = 0;  // 中间结点的附加信息为0
        ch[u][c] = sz++; // 新建结点
      }
      u = ch[u][c]; // 往下走
    }
    val[u] = v; // 字符串的最后一个字符的附加信息为v
  }
};

const int maxn = 300000 + 10;
const int mod = 20071027;

char s[maxn];
int l;
Trie t;

int dp[maxn];

int DP(int start) {
	if (start == l)
		return 1;
	if (start > l)
		return 0;
	if (dp[start] != -1)
		return dp[start];
	int ans = 0;
	int u = 0;
	for (int i = 0; i < 100 && start + i < l; ++i) {
		int cur = s[start + i] - 'a';
		if (t.ch[u][cur] == 0)
			break;
		u = t.ch[u][cur];
		if (t.val[u] > 0) {
			ans += DP(start + i + 1) % mod;
			ans %= mod;
		}
	}
	return dp[start] = ans;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int kase = 0;
	while (cin >> s) {
		l = strlen(s);
		t.clear();
		int n;
		cin >> n;
		char h[maxn];
		for (int i = 0; i < n; ++i) {
			cin >> h;
			t.insert(h, 1);
		}
		memset(dp, -1, sizeof(dp));
		cout << "Case " << ++kase << ": " << DP(0) << endl;
	}
	return 0;
}