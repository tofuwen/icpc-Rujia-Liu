#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

typedef struct block
{
    int l;
    int w;
    int h;
}Block;
int n;
Block b[200];
int dp[200];
vector<int> v[200];

int DP(int s);

int main()
{
    int cases = 0;
    //freopen("data.in","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        if(!n)
            break;
        for(int i=0;i<200;i++)
            v[i].clear();
        memset(dp,-1,sizeof(dp));
        int N = 3*n;
        for(int i=0;i<n;i++)
        {
            int a1,a2,a3;
            cin>>a1>>a2>>a3;
            b[3*i].l = max(a1,a2);
            b[3*i].w = min(a1,a2);
            b[3*i].h = a3;
            b[3*i+1].l = max(a1,a3);
            b[3*i+1].w = min(a1,a3);
            b[3*i+1].h = a2;
            b[3*i+2].l = max(a2,a3);
            b[3*i+2].w = min(a2,a3);
            b[3*i+2].h = a1;
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                if(b[i].l<b[j].l&&b[i].w<b[j].w)
                    v[j].push_back(i);
        }
        int M = 0;
        for(int i=0;i<N;i++)
        {
            M = max(M,DP(i));
        }
        printf("Case %d: maximum height = %d\n",++cases,M);
    }
    return 0;
}

int DP(int s)
{
    if(dp[s]!=-1)
        return dp[s];
    int hold = b[s].h;
    int M = 0;
    for(int i=0;i<v[s].size();i++)
    {
        M = max(M,DP(v[s][i]));
    }
    return dp[s] = hold + M;
}








