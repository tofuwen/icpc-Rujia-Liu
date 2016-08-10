#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;

char s[maxn];

int dp[maxn][maxn];

int DP(int i, int j){
	if(dp[i][j] != -1)
		return dp[i][j];
	if(i >= j)
		return 0;
	if(s[i] == s[j])
		return dp[i][j] = DP(i+1, j-1);
	return dp[i][j] = 1 + min(min(DP(i,j-1), DP(i+1, j)), DP(i+1, j-1));
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=1;cc<=T;cc++){
		scanf("%s", s);
		memset(dp, -1, sizeof(dp));
		for(int i=0;i<maxn;i++)
			dp[i][i] = 0;
		printf("Case %d: %d\n", cc, DP(0, strlen(s)-1));
	}
	return 0;
}