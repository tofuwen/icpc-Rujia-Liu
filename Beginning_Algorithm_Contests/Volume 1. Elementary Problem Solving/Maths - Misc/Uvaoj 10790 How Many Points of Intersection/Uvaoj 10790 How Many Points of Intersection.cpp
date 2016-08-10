#include <cstdio>
using namespace std;

int main()
{
	//freopen("data.txt","r",stdin);
	int n,m;
	int kase = 0;;
	while(scanf("%d%d",&n,&m)&&n)
	{
		long long ans = (long long)n*(n-1)*m*(m-1)/4;
		printf("Case %d: %lld\n",++kase,ans);
	}
	return 0;
}