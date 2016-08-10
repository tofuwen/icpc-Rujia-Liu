#include<cstdio>
#include<cstring>
using namespace std;

char g[50][100];
bool visited[50][100];
int row;
int a[4] = {0,0,1,-1};
int b[4] = {1,-1,0,0};

bool isWall(int i, int j)
{
    if(i>=row||i<0||j<0)
        return true;
    if(g[i][j]!=' '&&g[i][j]!='*'&&g[i][j]!='_')
        return true;
    return false;
}

void dfs(int i, int j)
{
    visited[i][j] = true;
    g[i][j] = '#';
    for(int k=0;k<4;k++)
    {
        int x = i+a[k];
        int y = j+b[k];
        if(!isWall(x,y))
            dfs(x,y);
    }
}

int main()
{
    //freopen("data.txt","r",stdin);
    int T;
    scanf("%d",&T);
    getchar();
    for(int cc=0;cc<T;cc++)
    {
        memset(visited,0,sizeof(visited));
        row = 0;
        while(gets(g[row]))
        {
            if(g[row][0]=='_')
                break;
            row++;
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<strlen(g[i]);j++)
            {
                if(g[i][j]=='*')
                    dfs(i,j);
            }
        }
        for(int i=0;i<=row;i++)
            puts(g[i]);
    }
    return 0;
}
