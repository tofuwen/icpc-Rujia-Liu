/*
// 可AC
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 110;

struct state
{
	int r;
	int e;
	state(int r, int e):r(r),e(e){}
};
vector<int> g[maxn];
int e[maxn];
int n;
queue<state> q;
bool v[maxn];
int maxe[maxn];
bool isFinish[maxn];

bool dfs(int start){
	if(start == n)
		return true;
	v[start] = true;
	for(int i=0;i<g[start].size();i++){
		int next = g[start][i];
		if(!v[next]){
			bool ok = dfs(next);
			if(ok)
				return true;
		}
	}
	return false;
}

void pre(){
	memset(isFinish,0,sizeof(isFinish));
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		isFinish[i] = dfs(i);
	}
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d",&n) && n!=-1){
		//printf("n:%d\n",n);
		for(int i=0;i<maxn;i++)
			g[i].clear();
		while(!q.empty())
			q.pop();
		//memset(v,0,sizeof(v));
		memset(maxe,0,sizeof(maxe));
		for(int i=1;i<=n;i++){
			int num;
			scanf("%d%d",&e[i], &num);
			for(int j=0;j<num;j++){
				int h;
				scanf("%d",&h);
				g[i].push_back(h);
			}
		}
		pre();
		if(!isFinish[1]){
			printf("hopeless\n");
			continue;
		}
		q.push(state(1,100));
		maxe[1] = 100;
		bool ok = false;
		while(!q.empty()){
			state now = q.front();
			q.pop();
			if(now.r == n){
				printf("winnable\n");
				ok = true;
				break;
			}
			int r = now.r;
			for(int i=0;i<g[r].size();i++){
				int nextRoom = g[r][i];
				if(!isFinish[nextRoom])
					continue;
				int value = now.e + e[nextRoom];
				if(value > maxe[nextRoom]){
					maxe[nextRoom] = value;
					q.push(state(nextRoom, value));
				}
			}
		}
		if(!ok)
			printf("hopeless\n");
	}
	return 0;
}
*/

/*
// wrong answer
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 110;

struct state
{
	int r;
	int e;
	state(int r, int e):r(r),e(e){}
};
vector<int> g[maxn];
int e[maxn];
int n;
queue<state> q;
bool v[maxn];
int maxe[maxn];
bool isFinish[maxn];

bool dfs(int start){
	if(start == n)
		return true;
	v[start] = true;
	for(int i=0;i<g[start].size();i++){
		int next = g[start][i];
		if(!v[next]){
			bool ok = dfs(next);
			if(ok)
				return true;
		}
	}
	return false;
}

void pre(){
	memset(isFinish,0,sizeof(isFinish));
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		isFinish[i] = dfs(i);
	}
}

int main()
{
	freopen("data.txt","r",stdin);
	while(scanf("%d",&n) && n!=-1){
		//printf("n:%d\n",n);
		for(int i=0;i<maxn;i++)
			g[i].clear();
		while(!q.empty())
			q.pop();
		//memset(v,0,sizeof(v));
		memset(maxe,0,sizeof(maxe));
		for(int i=1;i<=n;i++){
			int num;
			scanf("%d%d",&e[i], &num);
			for(int j=0;j<num;j++){
				int h;
				scanf("%d",&h);
				g[i].push_back(h);
			}
		}
		pre();
		if(!isFinish[1]){
			printf("hopeless\n");
			continue;
		}
		q.push(state(1,100));
		maxe[1] = 100;
		bool ok = false;
		while(!q.empty()){
			state now = q.front();
			q.pop();
			if(now.r == n){
				ok = true;
				break;
			}
			int r = now.r;
			bool okay = false;
			for(int i=0;i<g[r].size();i++){
				int nextRoom = g[r][i];
				if(!isFinish[nextRoom])
					continue;
				int value = now.e + e[nextRoom];
				if(value > maxe[nextRoom]){
					if(maxe[nextRoom] > 0){ //其实这个想表达它有一个正环。
						okay = true;
						break;
					}
					maxe[nextRoom] = value;
					q.push(state(nextRoom, value));
				}
			}
			if(okay){
				ok = true;
				break;
			}
		}
		if(!ok)
			printf("hopeless\n");
		else
			printf("winnable\n");
	}
	return 0;
}
*/

/*
// 这个算法也是错的···具体看note···
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 110;
const int INF = 1<<30;

struct Edge
{
    int from, to, dist;
    Edge(int u, int v, int d):from(u),to(v),dist(d){}
};

struct Bellman_Ford
{
    int n,m;//n个点 m条边
    vector<Edge> edges;
    vector<int> G[maxn];
    bool inq[maxn];//是否在队列中
    int cnt[maxn];//松弛次数
    int d[maxn];//s到各个点的距离
    int p[maxn];//最短路中的上一条弧（保存的是边的编号）

    void init(int n)
    {
        this->n = n;
        for(int i=0;i<n;i++)
            G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int dist)
    {
        edges.push_back(Edge(from, to, dist));
        m = edges.size();
        G[from].push_back(m-1);
        //保存的是边的编号，此算法有重边的情况仍然正确
    }
	
    //最差O(VE)
    bool bellman_ford(int s)
    {
        queue<int> q;
        memset(inq,0,sizeof(inq));
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
            d[i] = INF;
        d[s] = 0;
        inq[s] = true;
        q.push(s);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for(int i=0;i<G[u].size();i++)
            {
                Edge& e = edges[G[u][i]];
                if(d[u]<INF && d[e.to]>d[u]+e.dist && d[u]+e.dist<100)
                {
                    d[e.to] = d[u]+e.dist;
                    p[e.to] = G[u][i];
                    if(!inq[e.to])
                    {
                        q.push(e.to);
                        inq[e.to] = true;
                        if(++cnt[e.to]>3*n*n)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};

vector<int> g[maxn];
int e[maxn];

int main()
{
    freopen("data.txt","r",stdin);
    int n;
    while(scanf("%d",&n) && n != -1)
    {
        Bellman_Ford f;
        f.init(n);
        for(int i=0;i<maxn;i++)
        	g[i].clear();
        for(int i=0;i<n;i++)
        {
        	int num;
            scanf("%d%d",&e[i],&num);
            for(int j=0;j<num;j++){
            	int h;
            	scanf("%d",&h);
            	g[i].push_back(h-1);
            }
            //f.AddEdge(u,v,w);
            //f.AddEdge(v,u,w);
        }
        for(int i=0;i<n;i++){
        	for(int j=0;j<g[i].size();j++){
        		f.AddEdge(i, g[i][j], -e[g[i][j]]);
        	}
        }
        bool ok = f.bellman_ford(0);
        // printf("%d\n", ok);
        // printf("%d\n", f.d[n-1]);
        // string ans = f.d[n-1]<100?"winnable":"hopeless";
        // cout<<ans<<endl;
        if(f.d[n-1] < 100)
        	printf("winnable\n");
        else
        	printf("hopeless\n");
    }
    return 0;
}
*/