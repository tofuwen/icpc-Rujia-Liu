#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	//freopen("data.txt","r",stdin);
	int length, width;
	char hold[100];
	int kase = 0;
	while(scanf("%d%s%d",&length,hold,&width)==3){
		//printf("l:%d w:%d\n",length, width);
		double r = sqrt(length*length+width*width)/2;
		double cita = 2*asin(width/2.0/r);
		double h = 2.0*length + 2.0*cita*r;
		double ratio = 400.0 / h;
		printf("Case %d: %.10f %.10f\n",++kase,ratio*length,ratio*width);
	}
	return 0;
}