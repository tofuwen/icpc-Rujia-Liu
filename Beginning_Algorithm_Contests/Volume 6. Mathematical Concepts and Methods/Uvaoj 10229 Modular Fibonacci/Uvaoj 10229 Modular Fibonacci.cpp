#include <cstdio>
using namespace std;

const int maxn = (1<<18)*3+10;
const int loop = (1<<18)*3;
const int mod = 1<<19;
int ans[maxn];

void pre()
{
	ans[0] = 0;
	ans[1] = 1;
	for(int i=2;i<maxn;i++)
		ans[i] = (ans[i-1]+ans[i-2])%mod;
}

int main()
{
	//freopen("data.txt","r",stdin);
	pre();
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int MOD = 1<<m;
		int k = n%loop;
		printf("%d\n",ans[k]%MOD);
	}
	return 0;
}