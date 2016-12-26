#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 105;
const int maxm = 33;
const int INF = 1 << 30;

int p[maxm];
int N, M, L;
int dp[maxm][maxn];

bool okay(int n) {
	int ans = 0;
	for (int i = 0; i < M; ++i) {
		ans += p[i] / n;
	}
	return ans >= N;
}

int solve_max() {
	int low = 0, high = 1001;
	while (high - low > 1) {
		int mid = (low + high) / 2;
		if (okay(mid))
			low = mid;
		else
			high = mid;
	}
	return low;
}

int DP(int i, int j) {
	if (L == 0)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (i == 0) {
		if (j <= 0)
			return 0;
		return INF;
	}
	if (j <= 0)
		return 0;
	int cur = p[i-1] / L;
	return dp[i][j] = min(DP(i-1, j), DP(i-1, j-cur) + p[i-1]);
}

int main()
{
	// freopen("data.txt", "r", stdin);
	while(cin >> N >> M && N && M) {
		for (int i = 0; i < M; ++i) {
			cin >> p[i];
		}
		L = solve_max();
		memset(dp, -1, sizeof(dp));
		cout << L << " "<< DP(M, N) << endl;
	}
	return 0;
}