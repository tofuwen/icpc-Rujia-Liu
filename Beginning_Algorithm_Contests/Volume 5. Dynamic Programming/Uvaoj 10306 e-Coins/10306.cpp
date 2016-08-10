#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 310;
const int INF = 1 << 30;

int dp[maxn][maxn];
int m, S;
int coin1[maxn];
int coin2[maxn];

int is_square(int a) {
	int b = (int)(sqrt(a) + 0.5);
	return a == b*b;
}

int square(int a) {
	return (int)(sqrt(a) + 0.5);
}

int DP(int i, int j) {
	if(!i && !j)
		return 0;
	if(i < 0 || j < 0)
		return INF;
	if(dp[i][j] != -1)
		return dp[i][j];
	int ans = INF;
	for(int k=0;k<m;k++) {
		ans = min(1+DP(i-coin1[k], j-coin2[k]), ans);
	}
	return dp[i][j] = ans;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++) {
		scanf("%d%d", &m, &S);
		for(int i=0;i<m;i++)
			scanf("%d%d", &coin1[i], &coin2[i]);
		memset(dp, -1, sizeof(dp));
		int ans = INF;
		for(int i=0;i<=S*S;i++) {
			if(is_square(i) && is_square(S*S-i))
				ans = min(ans, DP(square(i), square(S*S-i)));
		}
		if(ans != INF)
			printf("%d\n", ans);
		else
			printf("not possible\n");
	}
	return 0;
}