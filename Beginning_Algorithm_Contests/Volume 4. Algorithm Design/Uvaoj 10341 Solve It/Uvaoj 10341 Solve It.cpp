#include <cstdio>
#include <cmath>
using namespace std;

int p,q,r,s,t,u;
const int n = 100;

bool isAns(double ans)
{
	if(fabs(ans)<1e-10)
		return true;
	return false;
}

double f(double x)
{
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

double cal(int num, double s, double e)
{
	if(num==0)
		return s;
	double a1 = f(s);
	double a2 = f(e);
	double b = f((s+e)/2);
	if(isAns(a1))
		return s;
	if(isAns(a2))
		return e;
	if(isAns(b))
		return (s+e)/2;
	if(a1*b<0)
		return cal(num-1,s,(s+e)/2);
	return cal(num-1,(s+e)/2,e);
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)!=EOF)
	{
		double a0 = f(0);
		double a1 = f(1);
		double h = a0*a1;
		if(isAns(a0))
		{
			printf("%.4f\n",0.0);
			continue;
		}
		if(isAns(a1))
		{
			printf("%.4f\n",1.0);
			continue;
		}
		//printf("%.4f\n",0.0);
		if(h>0)
		{
			printf("No solution\n");
			continue;
		}
		printf("%.4f\n",cal(n,0,1));
	}
	return 0;
}