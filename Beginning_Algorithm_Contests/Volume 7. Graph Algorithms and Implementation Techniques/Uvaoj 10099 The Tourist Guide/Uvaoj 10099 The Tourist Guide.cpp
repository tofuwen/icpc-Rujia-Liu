#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 110;
const int INF = 1<<30;

int n,m;
int d[maxn][maxn];

void floyd()
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                    d[i][j] = max(d[i][j], min(d[i][k],d[k][j]));
}

int main()
{
	//freopen("data2.txt","r",stdin);
	int kase = 0;
	while(scanf("%d%d",&n,&m)&&n)
	{
		int h1,h2,c;
		memset(d,0,sizeof(d));
		for(int i=0;i<n;i++)
			d[i][i] = INF;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&h1,&h2,&c);
			h1--;
			h2--;
			d[h1][h2] = c;
			d[h2][h1] = c;
		}
		floyd();
		printf("Scenario #%d\n",++kase);
		int s,des,peo;
		scanf("%d%d%d",&s,&des,&peo);
		int ans;
		if(peo % (d[s-1][des-1]-1)==0)
			ans = peo / (d[s-1][des-1]-1);
		else
			ans = peo / (d[s-1][des-1]-1) + 1;
		printf("Minimum Number of Trips = %d\n\n",ans);
	}
	return 0;
}