#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;


int m,n;
int g[110][110];
void dfs(int ms, int ns);
int count;

int main()
{
    //freopen("data.in","r",stdin);
    while(1)
    {
        count = 0;
        cin>>m>>n;
        if(!m) break;
        memset(g,0,sizeof(g));
        getchar();
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                char c = getchar();
                if(c=='@')
                    g[i][j] = 1;
            }
            getchar();
        }
       // for(int i=1;i<=m;i++)
       // {
       //     for(int j=1;j<=n;j++)
       //     {
      //          cout<<g[i][j]<<' ';
       //     }
       //     cout<<endl;
       // }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(g[i][j]==1)
                {
                    dfs(i,j);
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}

void dfs(int ms, int ns)
{
    if(g[ms][ns]==0)
        return;
    g[ms][ns] = 0;
    int a[8] = {-1,-1,-1,0,0,1,1,1};
    int b[8] = {-1,0,1,-1,1,-1,0,1};
    for(int i=0;i<8;i++)
    {
        int mn = ms+a[i];
        int nn = ns+b[i];
        if(g[mn][nn]==1)
        {
            dfs(mn,nn);
        }
    }
}







