#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

int n,m;
int u[10000];
int v[10000];
vector<int> g[110];
bool visited[110];
int in[110];//´Ó1µ½n

int main()
{
   // freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
    while(1)
    {
        cin>>n>>m;
        if(n==0)
            break;
        for(int i=1;i<=n;i++)
        {
            in[i] = 0;
            g[i].clear();
            visited[i] = false;
        }
        for(int i=0;i<m;i++)
        {
            cin>>u[i]>>v[i];
            g[u[i]].push_back(v[i]);
            in[v[i]]++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++)
        {
            if(in[i]==0)
                q.push(i);
        }
        int count = 0;
        while(!q.empty())
        {
            int now = q.front();
            if(visited[now])
                continue;
            visited[now] = true;
            if(++count<n)
                cout<<now<<' ';
            else
                cout<<now<<endl;
            q.pop();
            for(int i=0;i<g[now].size();i++)
            {
                in[g[now][i]]--;
                if(in[g[now][i]]==0)
                    q.push(g[now][i]);
            }
        }
    }
    return 0;
}












