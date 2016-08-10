#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 510;
const int maxm = 300000;

struct point
{
	int x;
	int y;
};

int n,m;//n: the number of points

int u[maxm];//the index(point) of starting point of the i-th edge
int v[maxm];//the index(point) of terminal point of the i-th edge
double w[maxm];//the weight of the i-th edge
int r[maxm];//the index(edge) of i-th smallest(weight) edge
int p[maxn];//the index of father point of the point with index i
//bool sa[maxn];

point points[maxn];

vector<int> used;
//vector<int> g[maxn];

//bool vis[maxn];

int cmp(const int i, const int j)
{
	return w[i]<w[j];
}

int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}

//time complexity: O(mlogm)
double Kruskal()
{
	double ans = 0;
	for(int i=0;i<n;i++)
		p[i] = i;
	for(int i=0;i<m;i++)
		r[i] = i;
	sort(r,r+m,cmp);
	for(int i=0;i<m;i++)
	{
		int e = r[i];
		int x = find(u[e]);
		int y = find(v[e]);
		if(x!=y)
		{
			ans += w[e];
			used.push_back(e);
			p[x] = y;
		}
	}
	return ans;
}

int s;

double cal(point a, point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}


// bool dfs(int start)
// {
// 	if(sa[start])
// 		return true;
// 	vis[start] = true;
// 	for(int i=0;i<g[start].size();i++)
// 	{
// 		int next = g[start][i];
// 		if(!vis[next])
// 			return dfs(next);
// 	}
// 	return false;
// }

// bool isSatellite(int start, int usedIndex)
// {
// 	for(int i=0;i<n;i++)
// 		g[i].clear();
// 	for(int i=0;i<used.size();i++)
// 		if(i!=usedIndex)
// 		{
// 			int u1 = u[used[i]];
// 			int v1 = v[used[i]];
// 			g[u1].push_back(v1);
// 			g[v1].push_back(u1);
// 		}
// 	memset(vis,0,sizeof(vis));
// 	return dfs(start);
// }

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++)
	{
		scanf("%d%d",&s,&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&points[i].x,&points[i].y);
		m = 0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				u[m] = i;
				v[m] = j;
				w[m++] = cal(points[i],points[j]);
			}
		used.clear();
		Kruskal();
		//memset(sa,0,sizeof(sa));
		int backNum = s==0?0:s-1;
		int iindex = used.size()-1-backNum;
		double ans = w[used[iindex]];
		// for(int i=used.size()-1;i>=0;i--)
		// {
		// 	if(s<0)
		// 		break;
		// 	ans = min(ans,w[used[i]]);
		// 	int u1 = u[used[i]];
		// 	int v1 = v[used[i]];
		// 	if(!isSatellite(u1, i))
		// 	{
		// 		sa[u1] = true;
		// 		s--;
		// 	}
		// 	if(!isSatellite(v1, i))
		// 	{
		// 		sa[v1] = true;
		// 		s--;
		// 	}
		// }
		printf("%.2f\n",ans);
	}
	return 0;
}