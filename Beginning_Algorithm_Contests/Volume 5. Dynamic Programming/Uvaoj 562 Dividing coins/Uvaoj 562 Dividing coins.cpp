#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 110;
const int maxWant = 25010;

int n;
int coins[maxn];
int dp[maxn][maxWant];

int DP(int m, int want)
{
	if(dp[m][want]!=-1)
		return dp[m][want];
	if(want<coins[m-1])
		return dp[m][want] = DP(m-1,want);
	return dp[m][want] = max(DP(m-1,want),DP(m-1,want-coins[m-1])+coins[m-1]);
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++)
	{
		int sum = 0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&coins[i]);
			sum += coins[i];
		}
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<maxWant;i++)
			dp[0][i] = 0;
		int ans = DP(n,sum/2);
		printf("%d\n",sum-ans*2);	
	}
	return 0;
}