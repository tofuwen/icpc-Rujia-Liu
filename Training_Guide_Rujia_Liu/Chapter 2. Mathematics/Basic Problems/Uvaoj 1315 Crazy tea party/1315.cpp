#include <cstdio>
using namespace std;

int solve(int n) {
	if(n == 1 || n == 2)
		return 0;
	if(n % 2)
		return ((n-1)/2) * ((n-1)/2);
	return n*(n-2)/4;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++) {
		int n;
		scanf("%d", &n);
		printf("%d\n", solve(n));
	}
	return 0;
}