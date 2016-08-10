/*
//这个算法都不对啊！即使1有，1,2相连。2也可以有啊！！
//不过显示的是TLE···
//TLE不代表算法正确！WA的算法如果超时，也是TLE···
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
const int maxn = 40;
vector<int> v[maxn];
int ans;

bool isOk(bool vi[])
{
	for(int i=1;i<=n;i++)
		if(!vi[i])
			return 0;
	return 1;
}

void ss(bool vi[], int num, int s)
{
	if(num>=ans)
		return;
	if(isOk(vi))
	{
		ans = min(num,ans);
		return;
	}
	bool vv[maxn];
	for(int i=0;i<maxn;i++)
		vv[i] = vi[i];
	int change[maxn];
	for(int i=s;i<=n;i++)
	{
		if(!vv[i])
		{
			int nn = 0;
			vv[i] = true;
			for(int j=0;j<v[i].size();j++)
			{
				if(!vv[v[i][j]])
				{
					vv[v[i][j]] = true;
					change[nn++] = v[i][j];
				}
			}
			ss(vv,num+1,i+1);
			vv[i] = false;
			for(int j=0;j<nn;j++)
				vv[change[j]] = false;
		}
	}
}

void solve()
{
	ans = maxn;
	bool vv[maxn];
	memset(vv,0,sizeof(vv));
	ss(vv,0,1);
	printf("%d\n",ans);
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d%d",&n,&m)&&n)
	{
		for(int i=0;i<m;i++)
		{
			int h1,h2;
			scanf("%d%d",&h1,&h2);
			v[h1].push_back(h2);
			v[h2].push_back(h1);
		}
		solve();
		for(int i=1;i<=n;i++)
			v[i].clear();
	}
	return 0;
}
*/


//一直是TLE！！！
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
const int maxn = 40;
int data[maxn][maxn];
int nnum[maxn];
int f[maxn];
int ans;

void ss(bool v[], int from, int num, int cover)
{
    for(int i=1;i<from;i++)
        if(!v[i]&&f[i]<from)
            return;
    if(num>=ans)
        return;
    if(cover==n)
    {
        ans = min(ans,num);
        return;
    }
    bool vv[maxn];
    memcpy(vv,v,maxn*sizeof(bool));
    int change[maxn];
    for(int i=from;i<=n;i++)
    {
        int covered = 0;
        int nn = 0;
        for(int j=0;j<nnum[i];j++)
        {
            if(!vv[data[i][j]])
            {
                covered++;
                vv[data[i][j]] = true;
                change[nn++] = data[i][j];
            }
        }
        if(covered)
        {
            ss(vv,i+1,num+1,cover+covered);
            for(int j=0;j<nn;j++)
                vv[change[j]] = false;
        }
    }
}

void solve()
{
    bool v[maxn];
    memset(v,0,sizeof(v));
    ss(v,1,0,0);
    printf("%d\n",ans);
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d%d",&n,&m)&&n)
	{
	    ans = maxn;
	    memset(nnum,0,sizeof(nnum));
	    for(int i=1;i<=n;i++)
        {
            data[i][nnum[i]++] = i;
            f[i] = i;
        }
		for(int i=0;i<m;i++)
		{
			int h1,h2;
			scanf("%d%d",&h1,&h2);
			data[h1][nnum[h1]++] = h2;
			data[h2][nnum[h2]++] = h1;
			f[h1] = max(f[h1],h2);
			f[h2] = max(f[h2],h1);
		}
		solve();
	}
	return 0;
}
















