#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 110;

int n1,n2;
int tower1[maxn];
int tower2[maxn];
int dp[maxn][maxn];

int DP(int i, int j)
{
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(tower1[i-1]==tower2[j-1])
		return dp[i][j] = 1+DP(i-1,j-1);
	return dp[i][j] = max(DP(i-1,j),DP(i,j-1));
}

int main()
{
	//freopen("data.txt","r",stdin);
	int kase = 0;
	while(scanf("%d%d",&n1,&n2))
	{
		if(!n1&&!n2)
			break;
		for(int i=0;i<n1;i++)
			scanf("%d",&tower1[i]);
		for(int i=0;i<n2;i++)
			scanf("%d",&tower2[i]);
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<maxn;i++)
			dp[0][i] = dp[i][0] = 0;
		printf("Twin Towers #%d\n",++kase);
		printf("Number of Tiles : %d\n\n",DP(n1,n2));
	}
	return 0;
}