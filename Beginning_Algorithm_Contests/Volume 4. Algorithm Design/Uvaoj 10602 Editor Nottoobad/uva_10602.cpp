#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 110;
string s[maxn];
bool vis[maxn];

int same_prefix_length(const string & a, const string & b) {
	int l = min(a.length(), b.length());
	for (int i = 0; i < l; i++) {
		if (a[i] != b[i])
			return i;
	}
	return l;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	cin >> T;
	for (int cc = 0; cc < T; cc++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> s[i];
		memset(vis, 0, sizeof(vis));
		vector<int> v;
		v.push_back(0);
		vis[0] = true;
		int ans = s[0].length();
		while(v.size() < n) {
			string last = s[v[v.size()-1]];
			int cur_max = -1;
			int index = 0;
			int final_same = 0;
			for (int i = 0; i < n; i++) {
				if (vis[i])
					continue;
				int same = same_prefix_length(last, s[i]);
				if (same > cur_max) {
					cur_max = same;
					index = i;
					final_same = same;
				}
			}
			vis[index] = true;
			v.push_back(index);
			ans += s[index].length() - final_same;
		}
		cout << ans << endl;
		for (int i = 0; i < n; i++)
			cout << s[v[i]] << endl;
	}
	return 0;
}