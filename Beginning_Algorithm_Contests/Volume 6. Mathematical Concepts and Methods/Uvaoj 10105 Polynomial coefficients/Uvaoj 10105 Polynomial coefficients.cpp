#include <cstdio>
using namespace std;

const int maxk = 15;
const int maxn = 15;

int n,k;
int pow[maxk];
long long f[maxn];

void pre()
{
	f[0] = 1;
	for(int i=1;i<maxn;i++)
		f[i] = f[i-1]*i;
}

int main()
{
	//freopen("data.txt","r",stdin);
	pre();
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=0;i<k;i++)
			scanf("%d",&pow[i]);
		long long ans = f[n];
		for(int i=0;i<k;i++)
			ans /= f[pow[i]];
		printf("%lld\n",ans);
	}
	return 0;
}