/*
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 55;
const int INF = 1<<30;

int l,n;
int c[maxn];
int dp[maxn][maxn][maxn][maxn];

int DP(int lowIndex, int highIndex, int low, int high)
{
	if(highIndex==lowIndex)
		return 0;
	if(dp[lowIndex][highIndex][low][high]!=-1)
		return dp[lowIndex][highIndex][low][high];
	int ans = INF;
	for(int i=lowIndex;i<highIndex;i++)
	{
		ans = min(ans,DP(lowIndex,i,low,i)+DP(i+1,highIndex,i,high));
	}
	return dp[lowIndex][highIndex][low][high] = ans+c[high]-c[low];
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d",&l)&&l)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&c[i]);
		c[0] = 0;
		c[n+1] = l;
		printf("The minimum cutting is %d.\n",DP(1,n+1,0,n+1));
	}
	return 0;
}
*/


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 55;
const int INF = 1<<30;

int l,n;
int c[maxn];
int dp[maxn][maxn];

int DP(int lowIndex, int highIndex, int low, int high)
{
	//low = lowIndex-1
	//high = highIndex
	if(highIndex==lowIndex)
		return 0;
	if(dp[lowIndex][highIndex]!=-1)
		return dp[lowIndex][highIndex];
	int ans = INF;
	for(int i=lowIndex;i<highIndex;i++)
	{
		ans = min(ans,DP(lowIndex,i,low,i)+DP(i+1,highIndex,i,high));
	}
	return dp[lowIndex][highIndex] = ans+c[highIndex]-c[lowIndex-1];
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d",&l)&&l)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&c[i]);
		c[0] = 0;
		c[n+1] = l;
		printf("The minimum cutting is %d.\n",DP(1,n+1,0,n+1));
	}
	return 0;
}