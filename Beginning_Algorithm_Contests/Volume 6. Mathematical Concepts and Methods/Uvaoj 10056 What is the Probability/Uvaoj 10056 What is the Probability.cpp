#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	int n,I;
	double p;
	for(int cc=0;cc<T;cc++)
	{
		scanf("%d%lf%d",&n,&p,&I);
		if(fabs(p-1)<1e-10)
		{
			if(I==1)
				printf("%.4lf\n",1.0);
			else
				printf("%.4lf\n",0.0);
			continue;
		}
		if(fabs(p)<1e-10)
		{
			printf("%.4lf\n",0.0);
			continue;
		}
		double p1 = p/(1-pow(1-p,n));
		printf("%.4lf\n",p1*pow(1-p,I-1));
	}
	return 0;
}