#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	// freopen("data.txt", "r", stdin);
	long long n, m;
	while(scanf("%lld%lld", &n, &m) && n) {
		long long ans = n*m*(n+m-2);
		long long M = max(m, n);
		m = min(m, n);
		long long cur = 0;
		for(long long i=2;i<m;i++)
			cur += 2*i*(i-1);
		int num = M+m-1-2*(m-1);
		cur += (m-1)*m*num;
		ans += 2*cur;
		printf("%lld\n", ans);
	}
	return 0;
}