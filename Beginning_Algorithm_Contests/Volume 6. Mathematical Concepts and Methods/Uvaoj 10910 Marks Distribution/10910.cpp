#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100;

int dp[maxn][maxn];

int solve(int n, int m) {
	if (n < m)
		return 0;
	if (m == 0)
		return 1;
	if (m == 1)
		return n;
	if (dp[n][m] != -1)
		return dp[n][m];
	return dp[n][m] = solve(n-1, m-1) + solve(n-1, m);
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int kase;
	int N, T, P;
	cin >> kase;
	memset(dp, -1, sizeof(dp));
	while (kase--) {
		cin >> N >> T >> P;
		cout << solve(T-N*P+N-1, N-1) << endl;
	}
	return 0;
}