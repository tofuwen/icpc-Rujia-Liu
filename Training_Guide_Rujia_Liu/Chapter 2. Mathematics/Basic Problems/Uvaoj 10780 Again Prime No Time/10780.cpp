#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 5000 + 10;
const int maxp = 5000;

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

int solve(int m, int n) {
	int size = prime.size();
	int ans = 1<<30;
	for(int i=0;i<size;i++) {
		int cur = 0;
		int c = m;
		while(c % prime[i] == 0) {
			cur++;
			c /= prime[i];
		}
		int all = 0;
		int d = n;
		while(d) {
			all += d / prime[i];
			d /= prime[i];
		}
		if(cur)
			ans = min(ans, all/cur);
	}
	return ans;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	gen_primes(5005);
	int T;
	scanf("%d", &T);
	for(int cc=1;cc<=T;cc++) {
		int m, n;
		scanf("%d%d", &m, &n);
		int ans = solve(m, n);
		if(ans)
			printf("Case %d:\n%d\n", cc, solve(m, n));
		else
			printf("Case %d:\nImpossible to divide\n", cc);
	}
	return 0;
}
