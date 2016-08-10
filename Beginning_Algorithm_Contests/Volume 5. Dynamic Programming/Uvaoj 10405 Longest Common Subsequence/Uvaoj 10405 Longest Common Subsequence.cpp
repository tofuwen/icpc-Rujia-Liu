#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;

char s1[maxn];
char s2[maxn];

int dp[maxn][maxn];

int MAX(int a, int b, int c)
{
	return max(max(a,b),c);
}

int DP(int i, int j)
{
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(s1[i-1]==s2[j-1])
		return dp[i][j] = MAX(DP(i-1,j),DP(i,j-1),DP(i-1,j-1)+1);
	else
		return dp[i][j] = max(DP(i-1,j),DP(i,j-1));
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(gets(s1))
	{
		gets(s2);
		int l1 = strlen(s1);
		int l2 = strlen(s2);
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<maxn;i++)
			dp[0][i] = dp[i][0] = 0;
		printf("%d\n",DP(l1,l2));
	}
	return 0;
}