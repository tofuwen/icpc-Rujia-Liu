#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 5010;
const int maxk = 1010;

const long long INF = (long long)1<<60;

long long dp[maxn][maxk];

int data[maxn];

int N, K;

long long DP(int n, int k){ // k pairs(just consider A and B, ignore C), using first n chopsticks
	if(2*k > n)
		return INF;
	int rn = N - n;
	int rk = K + 8 - k;
	//if(rn < 3*rk + 1)
	//	return INF;
	if(dp[n][k] != -1)
		return dp[n][k];
	long long ans;
	if(rn < 3*rk + 1) // determine we can choose longest third chopstick if we choose use n-1 and n as a pair.
		ans = DP(n-1, k);
	else
		ans = min(DP(n-1, k), DP(n-2, k-1) + (data[n]-data[n-1])*(data[n]-data[n-1]));
	return dp[n][k] = ans;
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++){
		//int K, N;
		scanf("%d%d", &K, &N);
		for(int i=1;i<=N;i++)
			scanf("%d", &data[i]);
		memset(dp, -1, sizeof(dp));
		for(int i=0;i<maxn;i++)
			dp[i][0] = 0;
		printf("%lld\n", DP(N-1,K+8));
	}
	return 0;
}