#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 2010;
const double PI = acos(-1.0);
const double eps = 1e-15;

//bool v[maxn];

int main()
{
	//freopen("data.txt","r",stdin);
	int n, m;
	while(scanf("%d%d",&n,&m) != EOF){
		double ansAngle = 0;
		int sum = n+m;
		double step = 2*PI/sum;
		//memset(v,0,sizeof(v));
		for(int i=1;i<n;i++){
			double angle = 2 * PI / n * i;
			int small = floor(angle / step - eps);
			double smallAngle = small * step;
			int big = small+1;
			double bigAngle = big*step;
			if(bigAngle-angle > angle-smallAngle)
				ansAngle += angle-smallAngle;
			else
				ansAngle += bigAngle - angle;
		}
		printf("%.4f\n",ansAngle*10000 / 2 / PI);
	}
	return 0;
}