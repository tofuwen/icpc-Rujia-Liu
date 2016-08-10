#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 105;
const int INF = 1<<30;

int sum[maxn];
int dp[maxn][maxn];

int DP(int i, int j){
	if(i > j)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	int ans = -INF;
	for(int k=i;k<=j;k++)
		ans = max(ans, sum[k]-sum[i-1]-DP(k+1,j));
	for(int k=j;k>=i;k--)
		ans = max(ans, sum[j]-sum[k-1]-DP(i,k-1));
	return dp[i][j] = ans;
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int n;
	while(scanf("%d", &n) && n){
		sum[0] = 0;
		for(int i=0;i<n;i++){
			scanf("%d", &sum[i+1]);
			sum[i+1] += sum[i];
		}
		memset(dp, -1, sizeof(dp));
		for(int i=1;i<=n;i++)
			dp[i][i] = sum[i] - sum[i-1];
		printf("%d\n", DP(1,n));
	}
	return 0;
}