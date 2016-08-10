#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int ans[1000];
int num;

void solve(int n, int cur)
{
	if(n==0)
		return;
	if(abs(n)%2==1)
		ans[cur] = 1;
	num++;
	solve((n-ans[cur])/-2,cur+1);
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++)
	{
		memset(ans,0,sizeof(ans));
		num = 0;
		int n;
		scanf("%d",&n);
		if(n==0)
		{
			printf("Case #%d: 0\n",cc+1);
			continue;
		}
		solve(n,0);
		printf("Case #%d: ",cc+1);
		for(int i=num-1;i>=0;i--)
			printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}