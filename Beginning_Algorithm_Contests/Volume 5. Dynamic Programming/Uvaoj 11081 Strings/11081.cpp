#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string s1, s2, s3;
const int maxn = 63;
const int mod = 10007;
int dp[maxn][maxn][maxn];

int DP(int l1, int l2, int l3) {
	if (l3 == 0)
		return 1;
	if (dp[l1][l2][l3] != -1)
		return dp[l1][l2][l3];
	char cur = s3[l3-1];
	int ans = 0;
	for (int i = 0; i < l1; i++) {
		if (s1[i] == cur) {
			ans += DP(i, l2, l3-1);
			ans %= mod;
		}
	}
	for (int i = 0; i < l2; i++) {
		if (s2[i] == cur) {
			ans += DP(l1, i, l3-1);
			ans %= mod;
		}
	}
	return dp[l1][l2][l3] = ans;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	cin >> T;
	for (int cc = 0; cc < T; ++cc) {
		cin >> s1 >> s2 >> s3;
		memset(dp, -1, sizeof(dp));
		cout << DP(s1.length(), s2.length(), s3.length()) << endl;
	}
	return 0;
}