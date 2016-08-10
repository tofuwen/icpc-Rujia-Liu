#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;

char data[maxn];
int dp[maxn][maxn];
int l;

int DP(int i, int j){
	if(i > j)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	dp[i][j] = DP(i+1, j);
	for(int k=j;k>i;k--){
		if(data[k] == data[i]){
			dp[i][j] = max(dp[i][j], 2 + DP(i+1, k-1));
			break;
		}
	}
	return dp[i][j];
}

int solve(){
	memset(dp, -1, sizeof(dp));
	for(int i=0;i<maxn;i++)
		dp[i][i] = 1;
	return DP(0, l-1);
}

int main()
{
	//freopen("data.txt", "r", stdin);
	//freopen("tofuans.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	getchar();
	for(int cc=0;cc<T;cc++){
		gets(data);
		l = strlen(data);
		printf("%d\n", solve());
	}
	return 0;
}