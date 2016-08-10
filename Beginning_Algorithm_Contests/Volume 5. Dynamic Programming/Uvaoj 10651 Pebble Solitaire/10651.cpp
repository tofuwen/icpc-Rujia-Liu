#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[20];

int dp[1 << 13];

int make(char * s) {
	int ans = 0;
	for(int i=0;i<12;i++) {
		ans = ans << 1;
		if(s[i] == 'o')
			ans++;
	}
	return ans;
}

int cal(int i) {
	int ans = 0;
	for(int k=0;k<12;k++)
		if(i & (1<<k))
			ans++;
	return ans;
}

int DP(int i) {
	if(dp[i] != -1)
		return dp[i];
	int ans = cal(i);
	for(int k=1;k<11;k++) {
		int i0 = i & (1<<(k-1));
		int i1 = i & (1<<k);
		int i2 = i & (1<<(k+1));
		if(i0 && i1 && !i2) {
			ans = min(ans, DP(i-i0-i1+(1<<(k+1))));
		}
		if(!i0 && i1 && i2) {
			// printf("%d %d\n", i1, i2);
			ans = min(ans, DP(i+(1<<(k-1))-i2-i1));
		}
	}
	return dp[i] = ans;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	scanf("%d\n", &T);
	memset(dp, -1, sizeof(dp));
	for(int i=0;i<T;i++) {
		gets(s);
		printf("%d\n", DP(make(s)));
	}
	return 0;
}