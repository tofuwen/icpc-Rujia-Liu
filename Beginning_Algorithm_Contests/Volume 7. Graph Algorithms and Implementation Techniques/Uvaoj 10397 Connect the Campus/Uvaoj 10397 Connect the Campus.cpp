#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 760;
const int M = 1010;
const int maxm = 320000;

struct point
{
	int x;
	int y;
};

struct edge
{
	int from;
	int to;
	double w;
	edge(int from, int to, double w):from(from),to(to),w(w){}
	edge(){}
	friend bool operator < (const edge& a, const edge& b)
	{
		return a.w<b.w;
	}
};

point p[maxn];
edge edges[maxm];
vector<int> g[maxn];
int fa[maxn];

int n,m;
int num;

int father(int x)
{
	return fa[x]==x?x:fa[x]=father(fa[x]);
}

double cal(point a, point b)
{
	int x = a.x-b.x;
	int y = a.y-b.y;
	return sqrt(x*x+y*y);
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			g[i].clear();
		for(int i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			int h1,h2;
			scanf("%d%d",&h1,&h2);
			g[h1-1].push_back(h2-1);
			g[h2-1].push_back(h1-1);
		}
		for(int i=0;i<n;i++)
			fa[i] = i;
		for(int k=0;k<n+10;k++)
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<g[i].size();j++)
				{
					int ans = min(father(i),father(g[i][j]));
					fa[i] = fa[g[i][j]] = ans;
				}
			}
		num = 0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				edges[num++] = edge(i,j,cal(p[i],p[j]));
		sort(edges,edges+num);
		// for(int i=0;i<num;i++)
		// 	printf("%.1f\n",edges[i].w);
		double ans = 0.0;
		for(int i=0;i<num;i++)
		{
			int x = father(edges[i].from);
			int y = father(edges[i].to);
			if(x!=y)
			{
				ans += edges[i].w;
				fa[x] = y;
			}
		}
		printf("%.2f\n",ans);
	}
	return 0;
}