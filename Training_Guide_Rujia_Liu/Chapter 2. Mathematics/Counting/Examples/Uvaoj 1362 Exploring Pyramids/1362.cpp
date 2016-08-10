#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int maxn = 310;
const ll mod = 1e9;

ll dp[maxn][maxn];
char s[maxn];

ll DP(int i, int j) {
	if(i == j)
		return 1;
	if(s[i] != s[j])
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	ll ans = 0;
	for(int k=i+2;k<=j;k++) {
		if(s[k] == s[i])
			ans += (DP(i+1, k-1) * DP(k, j)) % mod;
	}
	return dp[i][j] = ans % mod;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	while(scanf("%s", s) != EOF) {
		int l = strlen(s);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", DP(0, l-1) % mod);
	}
	return 0;
}