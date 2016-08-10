#include <cstdio>
using namespace std;

const int maxn = 10010;

long long dp[maxn][30];

long long DP(int i, int j){
	if(i >= 0)
		return dp[i][j];
	return 0;
}

int main(){
	//freopen("data.txt", "r", stdin);
	for(int i=0;i<maxn;i++)
		dp[i][0] = 0;
	for(int i=1;i<22;i++)
		dp[0][i] = 1;
	for(int i=1;i<22;i++){
		for(int j=1;j<maxn;j++){
			dp[j][i] = dp[j][i-1] + DP(j-i*i*i, i);
		}
	}
	int n;
	while(scanf("%d", &n) != EOF)
		printf("%lld\n", dp[n][21]);
	return 0;
}