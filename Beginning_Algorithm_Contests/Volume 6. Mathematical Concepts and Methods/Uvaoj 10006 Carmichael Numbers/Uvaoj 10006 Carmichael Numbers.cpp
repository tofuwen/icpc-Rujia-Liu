#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 65010;

int n;
bool v[maxn];

void pre()
{
	memset(v,0,sizeof(v));
	int m = sqrt(maxn+0.5);
	for(int i=2;i<m;i++)
		if(!v[i])
			for(int j=i*i;j<maxn;j+=i)
				v[j] = true;
}

long long power(int a, int p, int mod)
{
	if(p==0)
		return 1;
	if(p==1)
		return a%mod;
	if(p%2)
		return (power(a,p/2,mod)*power(a,p/2,mod)*a)%mod;
	return (power(a,p/2,mod)*power(a,p/2,mod))%mod;
}

bool check(int k)
{
	if(!v[k])
		return false;
	for(int i=2;i<k;i++)
	{
		long long h = power(i,k,k);
		//printf("k:%d\n",k);
		//printf("h:%lld i:%d\n",h,i);
		if(h!=i)
			return false;
	}
	return true;
}

int main()
{
	//freopen("data.txt","r",stdin);
	pre();
	while(scanf("%d",&n)==1&&n)
	{
		bool ok = check(n);
		if(ok)
			printf("The number %d is a Carmichael number.\n",n);
		else
			printf("%d is normal.\n",n);
	}
	return 0;
}