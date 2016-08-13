#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 100000;
const int maxp = 100000;

int vis[maxn]; // vis[i]=1, i is composite
vector<int> prime;

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

int solve(int n) {
	int size = prime.size();
	int ans = 1;
	int c = n;
	for(int i=0;i<size;i++) {
		int cur = 0;
		while(c % prime[i] == 0) {
			cur++;
			c /= prime[i];
		}
		if(cur)
			ans *= (2*cur+1);
	}
	if(ans == 1)
		ans = 2;
	else {
		if (c != 1)
			ans *= 3;
		ans = (ans+1)/2;
	}
	if(n == 1)
		ans = 1;
	return ans;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int n;
	gen_primes(maxn-100);
	while(scanf("%d", &n) && n) {
		printf("%d %d\n", n, solve(n));
	}
	return 0;
}