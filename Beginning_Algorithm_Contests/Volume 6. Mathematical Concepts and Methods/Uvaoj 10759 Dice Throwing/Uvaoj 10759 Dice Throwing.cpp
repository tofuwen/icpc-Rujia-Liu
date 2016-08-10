#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 30;
const int maxx = 160;

int n, x;
long long dp[maxn][maxx];

long long power(long long i, long long p){
	if(p == 1)
		return i;
	if(p == 0)
		return 1;
	long long h = power(i,p/2);
	if(p%2 ==1)
		return h*h*i;
	return h*h;

}

long long DP(int i, int j){
	if(j < 0)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	long long ans = 0;
	for(int k=1;k<=6;k++)
		ans += DP(i-1, j-k);
	//printf("i:%d j:%d ans:%lld\n",i,j,ans);
	return dp[i][j] = ans;
}

int main()
{
	//freopen("data.txt","r",stdin);
	//freopen("dataout.txt","w",stdout);
	while(scanf("%d%d",&n, &x) && n){
		long long all = power(6, n);
		memset(dp,-1,sizeof(dp));
		dp[0][0] = 1;
		for(int i=1;i<maxx;i++)
			dp[0][i] = 0;
		long long up = 0;
		for(int i=0;i<x;i++)
			up += DP(n, i);
		//printf("up:%lld\n",up);
		up = all - up;
		long long gcd = __gcd(up, all);
		if(up == all){
			printf("1\n");
			continue;
		}
		if(up == 0){
			printf("0\n");
			continue;
		}
		printf("%lld/%lld\n",up/gcd, all/gcd);
	}
	return 0;
}