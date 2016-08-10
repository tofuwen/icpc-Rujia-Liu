#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 50100;
int phi[maxn];

void euler_phi_table(int n, int *phi)
{
	for(int i=2;i<=n;i++)
		phi[i] = 0;
	phi[1] = 1;
	for(int i=2;i<=n;i++)
		if(!phi[i])
			for(int j=i;j<=n;j+=i)
			{
				if(!phi[j])
					phi[j] = j;
				phi[j] = phi[j]/i*(i-1);
			}
}

int main()
{
	//freopen("data.txt","r",stdin);
	euler_phi_table(maxn-10, phi);
	int n;
	while(scanf("%d",&n)==1&&n)
	{
		long long ans = 0;
		for(int i=1;i<=n;i++)
			ans += phi[i];
		printf("%lld\n",2*ans-1);
	}
	return 0;
}