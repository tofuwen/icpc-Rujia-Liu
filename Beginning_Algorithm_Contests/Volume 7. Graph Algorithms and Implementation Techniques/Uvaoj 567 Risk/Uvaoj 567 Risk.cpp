#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 25;
const int n = 20;
const int INF = 1<<30;

int a[maxn];
int d[maxn][maxn];

void floyd()
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(d[i][k]<INF && d[k][j]<INF)
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
}

int main()
{
	//freopen("data.txt","r",stdin);
	int kase = 0;
	while(scanf("%d",&a[0])!=EOF)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				d[i][j] = INF;
		for(int i=0;i<a[0];i++)
		{
			int h;
			scanf("%d",&h);
			h--;
			d[0][h] = d[h][0] = 1;
		}
		for(int i=1;i<n-1;i++)
		{
			scanf("%d",&a[i]);
			for(int j=0;j<a[i];j++)
			{
				int h;
				scanf("%d",&h);
				h--;
				d[i][h] = d[h][i] = 1;
			}
		}
		floyd();
		int test;
		scanf("%d",&test);
		printf("Test Set #%d\n",++kase);
		for(int i=0;i<test;i++)
		{
			int sta,des;
			scanf("%d%d",&sta,&des);
			printf("%2d to %2d: %d\n",sta,des,d[sta-1][des-1]);
		}
		printf("\n");
	}
	return 0;
}