#include <cstdio>
using namespace std;

const int maxn = 30010;

int n;
long long dp[6][maxn];
int a[5] = {1,5,10,25,50};

long long DP(int i, int j)
{
	if(j<0)
		return 0;
	return dp[i][j];
}

void pre()
{
	for(int i=0;i<maxn;i++)
		dp[0][i] = 1;
	for(int i=0;i<5;i++)
		dp[i][0] = 1;
	for(int i=1;i<5;i++)
	{
		for(int j=1;j<maxn;j++)
		{
			dp[i][j] = dp[i-1][j]+DP(i,j-a[i]);
		}
	}
}

int main()
{
	freopen("data.txt","r",stdin);
	pre();
	while(scanf("%d",&n)!=EOF)
	{
		long long ans = dp[4][n];
		// if(n==0)
		// {
		// 	printf("There are 0 ways to produce %d cents change.\n",n);
		// 	continue;
		// }
		if(ans==1)
			printf("There is only 1 way to produce %d cents change.\n",n);
		else
			printf("There are %lld ways to produce %d cents change.\n",ans,n);
	}
	return 0;
}