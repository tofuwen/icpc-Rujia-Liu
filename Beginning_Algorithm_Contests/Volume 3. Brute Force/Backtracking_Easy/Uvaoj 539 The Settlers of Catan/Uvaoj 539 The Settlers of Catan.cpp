#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

int n,m;
int M;

struct edge
{
    int s;
    int e;
};

edge e[30];
vector<int> v[30];
bool visited[30];

int get(int nEdge, int sV)
{
    if(e[nEdge].s==sV)
        return e[nEdge].e;
    return e[nEdge].s;
}

void dfs(int degree, int sV)
{
    if(degree>M)
        M = degree;
    for(int i=0;i<v[sV].size();i++)
    {
        if(!visited[v[sV][i]])
        {
            visited[v[sV][i]] = true;
            dfs(degree+1,get(v[sV][i],sV));
            visited[v[sV][i]] = false;
        }
    }
}

int main()
{
    //freopen("data.txt","r",stdin);
    while(scanf("%d%d",&n,&m)&&n)
    {
        M = 0;
        for(int i=0;i<30;i++)
            v[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&e[i].s,&e[i].e);
            v[e[i].s].push_back(i);
            v[e[i].e].push_back(i);
        }
        memset(visited,0,sizeof(visited));
        for(int i=0;i<n;i++)
            dfs(0,i);
        printf("%d\n",M);
    }
    return 0;
}
