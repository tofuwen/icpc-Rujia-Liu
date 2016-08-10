#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
const int INF = 1<<30;

int n,m,q;
int d[maxn][maxn];

void floyd()
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(d[i][k]<INF && d[k][j]<INF)
                    d[i][j] = min(d[i][j], max(d[i][k],d[k][j]));
}

int main()
{
	//freopen("data.txt","r",stdin);
	int kase = 0;
	while(scanf("%d%d%d",&n,&m,&q)&&n)
	{
		int h1,h2,c;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				d[i][j] = INF;
		for(int i=0;i<n;i++)
			d[i][i] = 0;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&h1,&h2,&c);
			h1--;
			h2--;
			d[h1][h2] = min(d[h1][h2],c);
			d[h2][h1] = min(d[h2][h1],c);
		}
		floyd();
		if(kase)
			printf("\n");
		printf("Case #%d\n",++kase);
		for(int i=0;i<q;i++){
			int s,des;
			scanf("%d%d",&s,&des);
			if(d[s-1][des-1]!=INF)
				printf("%d\n",d[s-1][des-1]);
			else
				printf("no path\n");
		}
	}
	return 0;
}