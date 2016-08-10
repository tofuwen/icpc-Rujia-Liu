#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

const int maxn = 110;

int n,m;
int visited[maxn];
int ans[maxn];
int M;
int now[maxn];
vector<int> v[maxn];

void bfs(int degree, int sv, int from)
{
    //printf("sv: %d\n",sv);
    bool isChanged[maxn];
    memset(isChanged,0,sizeof(isChanged));
    visited[sv] = 1;
    now[degree-1] = sv;
  //  for(int i=0;i<degree;i++)
   //     printf("%d ",now[i]);
  //  printf("\n");
    if(degree>M)
    {
        M = degree;
        for(int i=0;i<degree;i++)
            ans[i] = now[i];
    }
    for(int i=0;i<v[sv].size();i++)
    {
        if(!visited[v[sv][i]])
        {
            visited[v[sv][i]] = 2;
            isChanged[v[sv][i]] = true;
        }
    }
    for(int i=from;i<=n;i++)
        if(!visited[i])
            bfs(degree+1,i,i+1);
    visited[sv] = 0;
    for(int i=0;i<v[sv].size();i++)
        if(isChanged[v[sv][i]])
            visited[v[sv][i]] = 0;
    //如果不判断isChanged[v[sv][i]]，这个算法不对！！
}

void solve()
{
    for(int i=1;i<=n;i++)
    {
        bfs(1,i,i+1);
        visited[i] = 2;
    }
    printf("%d\n",M);
    for(int i=0;i<M;i++)
    {
        printf("%d",ans[i]);
        if(i!=M-1)
            putchar(' ');
    }
    putchar('\n');
}

int main()
{
   // freopen("data.txt","r",stdin);
    //freopen("dataout.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cc=0;cc<T;cc++)
    {
        scanf("%d%d",&n,&m);
        memset(visited,0,sizeof(visited));
        M = 0;
        for(int i=0;i<m;i++)
        {
            int h1,h2;
            scanf("%d%d",&h1,&h2);
            v[h1].push_back(h2);
            v[h2].push_back(h1);
        }
       // for(int i=0;i<n;i++)
      //      printf()
        solve();
        for(int i=0;i<n;i++)
            v[i].clear();
    }
    return 0;
}
