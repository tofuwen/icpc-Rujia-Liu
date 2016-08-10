#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 10010;
const int Max = 10010;
int data[100][100];
int num_prime[Max];
int nimmm[100];

const int maxp = 10010;

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


void pre() {
	gen_primes(10005);
	for(int i=2;i<10005;i++) {
		num_prime[i] = 0;
		int cur = i;
		while(cur > 1) {
			for(int j=0;j<prime.size();j++) {
				while(cur % prime[j] == 0) {
					cur /= prime[j];
					num_prime[i] ++;				
				}
			}
		}
	}
}


int main()
{
	// freopen("data.txt", "r", stdin);
	pre();
	int T;
	scanf("%d", &T);
	for(int cc=1;cc<=T;cc++) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d", &data[i][j]);
		memset(nimmm, 0, sizeof(nimmm));
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++)
				nimmm[i] += num_prime[data[i][j]];
		}
		int ans = 0;
		for(int i=0;i<n;i++)
			ans ^= nimmm[i];
		if(ans)
			printf("Case #%d: YES\n", cc);
		else
			printf("Case #%d: NO\n", cc);
	}
	return 0;
}