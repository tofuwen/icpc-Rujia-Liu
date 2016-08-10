#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 260;
const int INF = 1 << 30;
int data[maxn];
int sum[maxn];

int dp[maxn][maxn];

int DP(int i, int j) {
	if(j < i)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	int ans = INF;
	for(int k=i;k<=j;k++) {
		ans = min(ans, DP(i, k-1) + DP(k+1, j) + sum[j+1]-sum[i]-data[k]);
	}
	return dp[i][j] = ans;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i=0;i<n;i++)
			scanf("%d", &data[i]);
		sum[0] = 0;
		for(int i=1;i<=n;i++)
			sum[i] = sum[i-1] + data[i-1];
		memset(dp, -1, sizeof(dp));
		printf("%d\n", DP(0, n-1));
	}
	return 0;
}