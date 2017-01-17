#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int maxn = 30;
ll dp[maxn];

ll DP(int n) {
	if (dp[n] != -1)
		return dp[n];
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return 0;
	ll ans = 0;
	for (int i = 0; i <= n-2; ++i) {
		ans += DP(i) * DP(n-2-i);
	}
	return dp[n] = ans;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	bool is_first = true;
	int n;
	memset(dp, -1, sizeof(dp));
	while (cin >> n) {
		if (!is_first)
			cout << endl;
		is_first = false;
		cout << DP(2*n) << endl;
	}
	return 0;
}