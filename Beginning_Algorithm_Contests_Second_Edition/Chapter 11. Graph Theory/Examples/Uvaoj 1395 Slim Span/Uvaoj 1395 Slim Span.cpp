#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
const int maxm = 10010;
const int INF = 1<<30;

int n,m;
int u[maxm];
int v[maxm];
int w[maxm];
int r[maxm];
int p[maxn];
int ans;

int cmp(const int i, const int j)
{
	return w[i]<w[j];
}

void refresh()
{
	for(int i=0;i<n;i++)
		p[i] = i;
}

int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}

bool isConnected()
{
	int parent = find(0);
	for(int i=1;i<n;i++)
	{
		int y = find(i);
		if(y!=parent)
			return false;
	}
	return true;
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d%d",&n,&m)&&n)
	{
		ans = INF;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&u[i],&v[i],&w[i]);
			u[i]--;
			v[i]--;
		}
		for(int i=0;i<m;i++)
			r[i] = i;
		sort(r,r+m,cmp);
		for(int i=0;i<m;i++)
		{
			refresh();
			for(int j=i;j<m;j++)
			{
				int e = r[j];
				int x = find(u[e]);
				int y = find(v[e]);
				if(x!=y)
					p[x] = y;
				if(isConnected())
				{
					int hold = w[e]-w[r[i]];
					if(ans>hold)
						ans = hold;
					break;
				}	
			}
		}
		int Ans = ans==INF?-1:ans;
		printf("%d\n",Ans);	
	}
	return 0;
}