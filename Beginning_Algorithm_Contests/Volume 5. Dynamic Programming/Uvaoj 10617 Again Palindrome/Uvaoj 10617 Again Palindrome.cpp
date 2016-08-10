#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 70;

char s[maxn];
long long dp[maxn][maxn];

long long DP(int i, int j){
	if(dp[i][j] != -1)
		return dp[i][j];
	if(i > j)
		return 0;
	long long ans = 1; // s[j] as a 1-character string is palindrome
	ans += DP(i, j-1);
	for(int k=i;k<j;k++){
		if(s[k] == s[j])
			ans += (DP(k+1, j-1)+1);
	}
	return dp[i][j] = ans;
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++){
		scanf("%s", s);
		//puts(s);
		memset(dp, -1, sizeof(dp));
		for(int i=0;i<maxn;i++)
			dp[i][i] = 1;
		printf("%lld\n", DP(0, strlen(s)-1));
	}
	return 0;
}