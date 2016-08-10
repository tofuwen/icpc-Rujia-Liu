// #include <cstdio>
// #include <cstring>
// #include <cassert>
// using namespace std;

// const int maxn = 210;

// char s[maxn];
// int dp[maxn][maxn];
// int l;

// int DP(int i, int j) {
// 	if(i == j) {
// 		if(s[i] == 'X')
// 			return 0;
// 		return 1;
// 	}
// 	if(i > j)
// 		return 0;
// 	if(j - i <= 2) {
// 		int num = 0;
// 		for(int k=i;k<=j;k++)
// 			if(s[k] == 'X')
// 				++num;
// 		assert(num <= 1);
// 		return num ^ 1;
// 	}
// 	if(j - i == 3) {
// 		int num = 0;
// 		for(int k=i;k<=j;k++)
// 			if(s[k] == 'X')
// 				++num;
// 		assert(num <= 2);
// 		if(num == 2)
// 			return 0;
// 		if(s[i+1] == 'X' || s[i+2] == 'X')
// 			return 0;
// 		return 1;
// 	}
// }

// void print() {
// 	bool first = true;
// 	for(int i=0;i<l;i++) {
// 		if(DP(0, i-3) == DP(i+3, l-1)) {
// 			if(!first)
// 				printf(" ");
// 			printf("%d", i);
// 			first = false;
// 		}
// 	}
// 	printf("\n");
// }

// int main()
// {
// 	freopen("data.txt", "r", stdin);
// 	int T;
// 	scanf("%d", &T);
// 	for(int cc=0;cc<T;cc++) {
// 		gets(s);
// 		l = strlen(s);
// 		memset(dp, -1, sizeof(dp));
// 		if(DP(0, l-1)) {
// 			printf("WINNING\n");
// 			print();
// 		}
// 	}
// 	return 0;
// }


#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
using namespace std;

const int maxn = 210;

char s[maxn];
int l;
int sg[maxn];

int pre() {
	sg[0] = 0;
	sg[1] = sg[2] = sg[3] = 1;
	sg[4] = sg[5] = 2;
	for(int i=6;i<maxn;i++) {
		bool vis[maxn];
		memset(vis, 0, sizeof(vis));
		vis[sg[i-3]] = true;
		vis[sg[i-4]] = true;
		vis[sg[i-5]] = true;
		for(int j=1;j<=i-6;j++)
			vis[sg[j] ^ sg[i-5-j]] = true;
		int cur = 0;
		while(vis[cur])
			cur++;
		sg[i] = cur;
	}
}

char ww(int i, char * s) {
	if(i >= 0 && i < l)
		return s[i];
	return 'Y';
}


bool test(char * s) {
	// This is wrong at the first timw! Be more careful!!

	// if(s[0]=='X' && s[1]=='X')
	// 	return true;
	// if(s[l-1]=='X' && s[l-2]=='X')
	// 	return true;
	// for(int i=2;i<l-2;i++) {
	// 	if(s[i] == 'X') {
	// 		if(s[i-2]=='X' || s[i-1]=='X' || s[i+2]=='X' || s[i+1]=='X')
	// 			return true;
	// 	}
	// }
	// return false;

	for(int i=0;i<l;i++) {
		if(s[i] == 'X') {
			if(ww(i-2, s)=='X' || ww(i-1, s)=='X' || ww(i+2, s)=='X' || ww(i+1, s)=='X')
				return true;
		}
	}
	return false;
}

int nextx(int cur, char * s) {
	for(int i=cur;i<l;i++)
		if(s[i] == 'X')
			return i;
	return -1;
}

int w(int i) {
	if(i >= 0 && i < l)
		return s[i];
	return 'Y';
}

bool isLosing(char * ss) {
	if(test(ss))
		return false;
	int cur = 0;
	vector<int> v;
	while(1) {
		int next = nextx(cur, ss);
		if(next == -1) {
			if(l-cur > 0)
				v.push_back(l-cur);
			break;
		}
		int this_l = next - 2 - cur;
		if(this_l > 0)
			v.push_back(this_l);
		cur = next + 3;
	}
	int ans = 0;
	for(int i=0;i<v.size();i++)
		ans ^= sg[v[i]];
	if(ans)
		return false;
	return true;
}

bool ok(int i) {
	char ss[maxn];
	strcpy(ss, s);
	ss[i] = 'X';
	if(isLosing(ss))
		return true;
	return false;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	pre();
	int T;
	scanf("%d\n", &T);
	// for(int i=0;i<10;i++)
	// 	printf("%d ", sg[i]);
	for(int cc=0;cc<T;cc++) {
		scanf("%s", s);
		l = strlen(s);
		if(test(s)) {
			printf("WINNING\n");
			vector<int> ans;
			for(int i=0;i<l;i++) {
				if(w(i) == '.') {
					if(w(i-2)=='X' && w(i-1)=='X') {
						ans.push_back(i);
						continue;
					}
					if(w(i+2)=='X' && w(i+1)=='X') {
						ans.push_back(i);
						continue;
					}
					if(w(i+1)=='X' && w(i-1)=='X') {
						ans.push_back(i);
						continue;
					}
				}
			}
			for(int i=0;i<ans.size();i++) {
				if(i)
					printf(" ");
				printf("%d", ans[i]+1);
			}
			printf("\n");
		}
		else {
			int cur = 0;
			vector<int> v;
			while(1) {
				int next = nextx(cur, s);
				if(next == -1) {
					if(l-cur > 0)
						v.push_back(l-cur);
					break;
				}
				int this_l = next - 2 - cur;
				if(this_l > 0)
					v.push_back(this_l);
				cur = next + 3;
			}
			// for(int i=0;i<v.size();i++)
			// 	printf("%d ", v[i]);
			// printf("\n\n");
			int ans = 0;
			for(int i=0;i<v.size();i++)
				ans ^= sg[v[i]];
			if(ans) {
				printf("WINNING\n");
				vector<int> ans;
				for(int i=0;i<l;i++)
					if(s[i] == '.' && ok(i))
						ans.push_back(i);
				for(int i=0;i<ans.size();i++) {
					if(i)
						printf(" ");
					printf("%d", ans[i]+1);
				}
				printf("\n");
			}
			else
				printf("LOSING\n\n");
		}
	}
	return 0;
}