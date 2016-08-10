#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int k;
const int maxk = 100;

int dp[10][maxk+10][maxk+10];

void make(int a, vector<int> & v) {
	while(a) {
		v.push_back(a % 10);
		a /= 10;
	}
}

int make_digit(int i, int j, const vector<int> & v) {
	int ans = 0;
	int l = v.size();
	for(int k=l-1;k>i;k--)
		ans += v[k];
	ans += j;
	return ans % k;
}

int make_power(int i, int j, const vector<int> & v) {
	int ans = 0;
	int l = v.size();
	for(int k=l-1;k>i;k--) {
		ans *= 10;
		ans += v[k];
	}
	ans *= 10;
	ans += j;
	for(int k=0;k<i;k++)
		ans *= 10;
	return ans % k;
}

int ipow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result % k;
}

int DP(int num, int digit, int power) {
	if(dp[num][digit][power] != -1)
		return dp[num][digit][power];
	if(num == 0) {
		if(digit == 0 && power == 0)
			return 1;
		return 0;
	}
	int & ans = dp[num][digit][power];
	ans = 0;
	for(int i=0;i<10;i++)
		ans += DP(num-1, ((digit-i)%k+k)%k, ((power-i*ipow(10, num-1))%k+k)%k);
	return ans;
}

int solve(int a) {
	if(k > maxk)
		return 1;
	if(a == 0)
		return 1;
	vector<int> v;
	make(a, v);
	int l = v.size();
	int ans = 0;
	for(int i=l-1;i>=0;i--) {
		int cur = i==0?v[i]:v[i]-1;
		for(int j=0;j<=cur;j++) {
			int digit_sum = make_digit(i, j, v);
			int power_sum = make_power(i, j, v);
			ans += DP(i, (k-digit_sum) % k, (k-power_sum) % k);
		}
	}
	return ans;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++) {
		int a, b;
		scanf("%d%d%d", &a, &b, &k);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", solve(b) - solve(a-1));
	} 
	return 0;
}