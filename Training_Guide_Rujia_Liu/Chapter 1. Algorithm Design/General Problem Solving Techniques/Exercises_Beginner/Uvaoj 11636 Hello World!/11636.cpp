#include <cstdio>
#include <cmath>
using namespace std;

int solve(int n) {
	if(n == 1)
		return 0;
	return ceil(log2(n-0.5));
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int n;
	int kase = 0;
	while(scanf("%d", &n) && n >= 0) {
		printf("Case %d: %d\n", ++kase, solve(n));
	}
	return 0;
}