#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxn = 40010;
const ll mod = 1000000007;
int n, m;
int s[maxn];
bool isChild[maxn];

vector<int> v[maxn];

int cal(int root) {
	int ans = 1;
	for(auto iter : v[root])
		ans += cal(iter);
	return s[root] = ans;
}

long long exgcd(long long a, long long b, long long &x, long long &y) {  //返回gcd(a,b)
    if (!b) {x = 1; y = 0; return a;}  
    long long d = exgcd(b, a % b, y, x);  
    y -= a / b * x;  
    return d;  
}  

long long inv(long long a, long long n) {  //返回x, s.t. ax=gcd(a,n)(mod n)
    long long x, y;  
    exgcd(a, n, x, y);  
    return (x + n) % n;  
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++) {
		for(int i=0;i<maxn;i++)
			v[i].clear();
		memset(isChild, 0, sizeof(isChild));
		scanf("%d%d", &n, &m);
		int a, b;
		for(int i=0;i<m;i++) {
			scanf("%d%d", &a, &b);
			v[b].push_back(a);
			isChild[a] = true;
		}
		for(int i=1;i<=n;i++)
			if(!isChild[i])
				v[0].push_back(i);
		cal(0);
		ll ans = 1;
		for(int i=2;i<=n;i++) {
			ans *= i;
			ans %= mod;
		}
		for(int i=1;i<=n;i++) {
			ans *= inv(s[i], mod);
			ans %= mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}