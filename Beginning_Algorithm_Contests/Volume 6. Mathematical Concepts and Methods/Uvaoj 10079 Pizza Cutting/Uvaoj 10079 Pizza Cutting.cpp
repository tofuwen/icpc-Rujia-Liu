#include <cstdio>
using namespace std;

int main()
{
	//freopen("data.txt", "r", stdin);
	long long n;
	while(scanf("%lld",&n))
	{
		if(n<0)
			break;
		printf("%lld\n",n*(n+1)/2+1);
	}
	return 0;
}