#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 80;

int dp[maxn];

int DP(int n) {
	if (n <= 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	if (dp[n] != -1)
		return dp[n];
	return dp[n] = DP(n-2) + DP(n-3);
}

int solve(int n) {
	return DP(n) + DP(n-1);
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int n;
	memset(dp, -1, sizeof(dp));
	while (cin >> n) {
		cout << solve(n) << endl;
	}
	return 0;
}