#include <cstdio>
using namespace std;
typedef long long ll;

int main()
{
	// freopen("data.txt", "r", stdin);
	ll n;
	while(scanf("%lld", &n) && n > 2) {
		printf("%lld\n", n*(n-2)*(2*n-5)/24);
	}
	return 0;
}
