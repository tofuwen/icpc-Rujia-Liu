#include <cstdio>
using namespace std;

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(n%k==0)
			printf("%d %d\n",0,k);
		else
		{
			int h = n/k*k;
			int up = n-h;
			printf("%d %d\n",k-up,up);
		}
	}
	return 0;
}