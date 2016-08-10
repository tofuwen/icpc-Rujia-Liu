
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

char graph[55][55];
int g[55][55];
bool visited[55][55];
bool isCounted[55][55];
int n;
int ans[2600];
int w,h;
int a[4] = {0,0,1,-1};
int b[4] = {1,-1,0,0};

void dfs2(int i, int j)
{
    isCounted[i][j] = true;
    for(int k=0;k<4;k++)
    {
        int x = i+a[k];
        int y = j+b[k];
        if(g[x][y]==2&&!isCounted[x][y])
            dfs2(x,y);
    }
}

void dfs(int i, int j)
{
    //cout<<i<<' '<<j<<endl;
    visited[i][j] = true;
    if(g[i][j]==2)
    {
        if(!isCounted[i][j])
        {
            ans[n]++;
            dfs2(i,j);
        }
    }
    for(int k=0;k<4;k++)
    {
        int x = i+a[k];
        int y = j+b[k];
        if(g[x][y]&&!visited[x][y])
            dfs(x,y);
    }
}


int main()
{
   // freopen("data.txt","r",stdin);
    //freopen("data.out","w",stdout);
    int caseNumber = 0;
    while(scanf("%d%d",&w,&h)&&w)
    {
        n = 0;
        for(int i=0;i<h;i++)
            scanf("%s",graph[i]);
        memset(g,0,sizeof(g));
        memset(visited,0,sizeof(visited));
        memset(ans,0,sizeof(ans));
        memset(isCounted,0,sizeof(isCounted));
        for(int i=1;i<=h;i++)
            for(int j=1;j<=w;j++)
            {
                if(graph[i-1][j-1]=='*')
                    g[i][j] = 1;
                if(graph[i-1][j-1]=='X')
                    g[i][j] = 2;
            }
        //cout<<"Kao"<<endl;
        for(int i=1;i<=h;i++)
            for(int j=1;j<=w;j++)
            {
                if(g[i][j]&&!visited[i][j])
                {
                    dfs(i,j);
                    n++;
                }
            }
        sort(ans,ans+n);
        printf("Throw %d\n",++caseNumber);
        bool ok = false;
        for(int i=0;i<n;i++)
        {
          //  if(ans[i]>=1&&ans[i]<=6)
          //  {
                if(ok)
                    putchar(' ');
                ok = true;
                printf("%d",ans[i]);
          //  }
        }
        printf("\n\n");
    }
    return 0;
}









/*


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[60][60],vis0[60][60],vis1[60][60],num[60],n;
char b[60];
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int cmp(const void *_p,const void *_q)
{
    int *p=(int *)_p;
    int *q=(int *)_q;
    return *p-*q;
}
void dfs1(int x,int y)
{
    int i,newx,newy;
    for(i=0;i<4;i++)
    {
        newx=x+dx[i];
        newy=y+dy[i];
        if(!vis1[newx][newy]&&a[newx][newy]==1)
        {
            vis1[newx][newy]=1;
            dfs1(newx,newy);
        }
    }
}
void dfs0(int x,int y)
{
    int i,newx,newy;
    if(a[x][y]==1&&!vis1[x][y])
    {
        vis1[x][y];
        dfs1(x,y);
        num[n]++;
    }
    for(i=0;i<4;i++)
    {
        newx=x+dx[i];
        newy=y+dy[i];
        if(a[newx][newy]!=-1&&!vis0[newx][newy])
        {
            vis0[newx][newy]=1;
            dfs0(newx,newy);
        }
    }
}
int main()
{
   // freopen("data.txt","r",stdin);
    int i,j,k,r,c,t;
    t=0;
    while(1)
    {
        scanf("%d%d",&c,&r);
        if(r==0)
            break;
        memset(a,-1,sizeof(a));
        for(i=1;i<=r;i++)
        {
            scanf("%s",b+1);
            for(j=1;j<=c;j++)
            {
                if(b[j]=='*')
                    a[i][j]=0;
                else if(b[j]=='X')
                    a[i][j]=1;
            }
        }
        n=0;
        memset(num,0,sizeof(num));
        memset(vis0,0,sizeof(vis0));
        memset(vis1,0,sizeof(vis1));
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                if(a[i][j]!=-1&&!vis0[i][j])
                {
                    vis0[i][j]=1;
                    dfs0(i,j);
                    n++;
                }
        qsort(num,n,sizeof(num[0]),cmp);
        printf("Throw %d\n",++t);
        for(i=0;i<n;i++)
        {
            if(i)
                printf(" ");
            printf("%d",num[i]);
        }
        printf("\n\n");
    }
    return 0;
}

*/
