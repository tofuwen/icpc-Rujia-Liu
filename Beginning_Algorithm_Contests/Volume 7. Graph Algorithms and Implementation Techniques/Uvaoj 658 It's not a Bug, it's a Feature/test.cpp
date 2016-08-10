#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define N 25
#define M 110
#define MAX 1048600
int n,m,s,t;
int d[MAX],vis[MAX],a[N];
int bug[N],newbug[N];
struct patches
{
    char b0[N],b[N];
    int t;
};
typedef struct patches patches;
patches p[M];

void get_bug(int x)
{
    //memset(bug,0,sizeof(bug));
    for(int i=n-1; i>=0; i--)
    {
        bug[i]=x%2;
        x/=2;
    }
/*
    printf("get_bug\n");
    for(int i=0; i<n; i++)
        printf("%d",bug[i]);
    printf("\n");
*/
    return ;
}
int can_use(int k)
{
    int OK=1;
    for(int i=0; i<n; i++)
    {
        if(p[k].b0[i]=='+' && bug[i]==0)
        { OK=0; break;}
        else if(p[k].b0[i]=='-' && bug[i]==1)
        { OK=0; break;}
    }
    return OK;
}
int get_newbug(int k)
{
    //memset(newbug,0,sizeof(newbug));
    for(int i=n-1; i>=0; i--)
    {
        if(p[k].b[i]=='0')
            newbug[i]=bug[i];
        else if(p[k].b[i]=='+')
            newbug[i]=1;
        else
            newbug[i]=0;
    }
    int val=0;
    for(int i=n-1,j=0; i>=0; i--,j++)
        val+=newbug[i]*a[j];
/*
    printf("get_newbug\n");
    for(int i=0; i<n; i++)
        printf("%d",newbug[i]);
    printf("\n");
    printf("val=%d\n",val);
*/
    return val;
}
void solve()
{
    queue <int> q;

    s=0; t=0;
    for(int i=0; i<n; i++) s+=a[i];
    //printf("%d %d\n",s,t);
    memset(d,0x3f,(s+10)*sizeof(int));
    memset(vis,0,(s+10)*sizeof(int));
    d[s]=0; q.push(s);  vis[s]=1;
    while(!q.empty())
    {
        int u=q.front(); q.pop(); vis[u]=0;
        get_bug(u);  //将十进制u转化为二进制保存在bug数组中
        for(int i=1; i<=m; i++)  //枚举所有补丁
        {
            if(can_use(i)) //i补丁可以对u产生作用
            {
                int v=get_newbug(i); 
                //得到新状态的bug，已经转化为十进制，二进制保存在newbug数组中
                if(d[u]+p[i].t < d[v])
                {
                    d[v]=d[u]+p[i].t;
                    if(!vis[v])
                    { 
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
        }
    }

    return ;
}
int main()
{
    freopen("data.txt","r",stdin);
    int T=0;
    memset(a,0,sizeof(a)); a[0]=1;
    for(int i=1; i<=21; i++)
        a[i]=a[i-1]*2;
    //把2^i保存下来，以后方便使用不用多次计算
    
    while(scanf("%d%d",&n,&m))
    {
        if(!n &&!m) break;
        T++;
        for(int i=1; i<=m; i++)
        scanf("%d%s%s",&p[i].t,p[i].b0,p[i].b);

        solve();
        printf("Product %d\n",T);
        if(d[0]!=INF)
            printf("Fastest sequence takes %d seconds.\n",d[0]);
        else
            printf("Bugs cannot be fixed.\n");
        printf("\n");
    }
    return 0;
}