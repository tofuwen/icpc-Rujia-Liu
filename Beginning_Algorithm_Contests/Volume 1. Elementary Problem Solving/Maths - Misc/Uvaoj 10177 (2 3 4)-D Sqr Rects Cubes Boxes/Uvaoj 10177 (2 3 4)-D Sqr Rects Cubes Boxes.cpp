#include <cstdio>
using namespace std;

int main()
{
	//freopen("data.txt","r",stdin);
	long long n;
	while(scanf("%lld",&n)!=EOF)
	{
		long long s2 = 0,s3 = 0,s4 = 0;
		for(int i=1;i<=n;i++){
			s2 += i*i;
			s3 += i*i*i;
			s4 += i*i*i*i;
		}
		long long r2 = n*n*(n+1)*(n+1)/4 - s2;
		long long r3 = n*n*n*(n+1)*(n+1)*(n+1)/8 - s3;
		long long r4 = n*n*n*n*(n+1)*(n+1)*(n+1)*(n+1)/16 - s4;
		printf("%lld %lld %lld %lld %lld %lld\n",s2,r2,s3,r3,s4,r4);
	}
	return 0;
}