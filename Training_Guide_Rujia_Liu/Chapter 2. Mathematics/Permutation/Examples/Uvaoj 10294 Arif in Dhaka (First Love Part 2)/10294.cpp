#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 55;

typedef long long ll;

ll power[maxn];

int main() 
{
	// freopen("data.txt", "r", stdin);
	int n, t;
	while(scanf("%d%d", &n, &t) != EOF) {
		power[0] = 1;
		for(int i=1;i<maxn;i++)
			power[i] = power[i-1] * t;
		ll a = 0;
		for(int i=0;i<n;i++)
			a += power[__gcd(i, n)];
		ll b = 0;
		if(n & 1) {
			b = n * power[n/2+1];
		}
		else {
			b = n/2*(power[n/2+1] + power[n/2]);
		}
		printf("%lld %lld\n", a/n, (a+b)/2/n);
	}
	return 0;
}