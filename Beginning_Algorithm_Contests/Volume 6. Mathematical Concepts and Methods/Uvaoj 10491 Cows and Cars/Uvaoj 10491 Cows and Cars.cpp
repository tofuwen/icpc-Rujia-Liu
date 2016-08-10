#include <cstdio>
using namespace std;

int main()
{
	//freopen("data.txt","r",stdin);
	int n1, n2, n3;
	while(scanf("%d%d%d",&n1,&n2,&n3) != EOF){
		int n = n1+n2;
		double ans = (double)(n-1)/n*n2/(n-n3-1);
		printf("%.5f\n",ans);
	}
	return 0;
}