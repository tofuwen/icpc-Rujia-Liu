#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
long long sum;
int setNum;

int main()
{
	//freopen("data.txt","r",stdin);
	int kase = 0;
	while(scanf("%d",&n)&&n)
	{
		int m = n;
		if(n==1)
		{
			printf("Case %d: %d\n",++kase,2);
			continue;
		}
		int upper = floor(sqrt(n));
		sum = 0;
		setNum = 0;
		for(int i=2;i<=upper;i++)
		{
			int counter = 0;
			while(m%i==0)
			{
				counter++;
				m /= i;
			}
			if(counter)
			{
				sum += pow(i,counter);
				setNum++;
			}	
			if(m==1)
				break;
		}
		if(m==n)
			sum = (long long)n+1;
		else{
			if(m!=n&&m!=1)
				sum += m;
			else
				if(setNum==1)
					sum++;
		}
		printf("Case %d: %lld\n",++kase,sum);
		//long long hold = 1<<30;
		//hold = 2*hold-1;
		//printf("%lld\n",hold);
	}
	return 0;
}