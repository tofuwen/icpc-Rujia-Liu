#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 1000000 + 10;
const int maxp = 700000;

int vis[maxn]; // vis[i]=1, i is composite
vector<int> prime;

bool v[maxn];

double dp[maxn];

void sieve(int n) {
	int m = (int)sqrt(n+0.5);
	memset(vis, 0, sizeof(vis));
	for(int i=2;i<=m;i++)
		if(!vis[i])
			for(int j=i*i;j<=n;j+=i)
				vis[j] = 1;
}

void gen_primes(int n) {
	sieve(n);
	prime.clear();
	prime.reserve(maxp);
	for(int i=2;i<=n;i++)
		if(!vis[i])
			prime.push_back(i);
}

double DP(int n) {
	if(n == 1)
		return 0.0;
	if(v[n])
		return dp[n];
	v[n] = 1;
	int size = prime.size();
	int g=0, p=0;
	double ans = 0;
	for(int i=0;i<size;i++) {
		if(prime[i] > n)
			break;
		p++;
		if(n % prime[i] == 0) {
			g++;
			ans += DP(n / prime[i]);
		}
	}
	dp[n] = (ans+p)/g;
	return dp[n];
}


int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	gen_primes(maxn-5);
	memset(v, 0, sizeof(v));
	for(int cc=1;cc<=T;cc++) {
		int n;
		scanf("%d", &n);
		printf("Case %d: %.8f\n", cc, DP(n));
	}
	return 0;
}