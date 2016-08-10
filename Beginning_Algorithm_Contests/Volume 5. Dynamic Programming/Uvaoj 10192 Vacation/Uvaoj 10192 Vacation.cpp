#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 110;

char s1[maxn];
char s2[maxn];
int dp[maxn][maxn];

int DP(int i, int j)
{
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(s1[i-1]==s2[j-1])
		return dp[i][j] = 1+DP(i-1,j-1);
	return dp[i][j] = max(DP(i-1,j),DP(i,j-1));
}

int main()
{
	//freopen("data.txt","r",stdin);
	int kase = 0;
	while(gets(s1))
	{
		if(s1[0]=='#')
			break;
		gets(s2);
		int l1 = strlen(s1);
		int l2 = strlen(s2);
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<maxn;i++)
			dp[i][0] = dp[0][i] = 0;
		printf("Case #%d: you can visit at most %d cities.\n",++kase,DP(l1,l2));
	}
	return 0;
}