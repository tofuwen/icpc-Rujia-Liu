/*
Problem E
Sending email
Time Limit: 3 seconds
"A new internet watchdog is creating a stir in
Springfield. Mr. X, if that is his real name, has
come up with a sensational scoop."
Kent Brockman

There are n SMTP servers connected by network cables. Each of the m cables connects two computers and has a certain latency measured in milliseconds required to send an email message. What is the shortest time required to send a message from server S to server T along a sequence of cables? Assume that there is no delay incurred at any of the servers.

Input
The first line of input gives the number of cases, N. N test cases follow. Each one starts with a line containing n (2<=n<20000), m (0<=m<50000), S (0<=S<n) and T (0<=T<n). S!=T. The next m lines will each contain 3 integers: 2 different servers (in the range [0, n-1]) that are connected by a bidirectional cable and the latency, w, along this cable (0<=w<=10000).

Output
For each test case, output the line "Case #x:" followed by the number of milliseconds required to send a message from S to T. Print "unreachable" if there is no route from S to T.

Sample Input	Sample Output
3
2 1 0 1
0 1 100
3 3 2 0
0 1 100
0 2 200
1 2 50
2 0 0 1
Case #1: 100
Case #2: 150
Case #3: unreachable

*/

#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
#define MAX_N 1000000001

typedef pair<int,int> pii;

int u[100010];
int v[100010];
int w[100010];
int next[100010];
int first[20010];
int d[20010];//从起始位置到各顶点的最短距离
int main()
{
   // freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
    int caseNumber;
    cin>>caseNumber;
    for(int cc=1;cc<=caseNumber;cc++)
    {
        int n,m,S,T;
        cin>>n>>m>>S>>T;
        for(int i=0;i<n;i++)
            first[i] = -1;
        for(int i=0;i<m;i++)
        {
            cin>>u[2*i]>>v[2*i]>>w[2*i];
            u[2*i+1] = v[2*i];
            v[2*i+1] = u[2*i];
            w[2*i+1] = w[2*i];
            next[2*i] = first[u[2*i]];
            first[u[2*i]] = 2*i;
            next[2*i+1] = first[u[2*i+1]];
            first[u[2*i+1]] = 2*i+1;
        }
        for(int i=0;i<n;i++)
        {
            d[i] = (i==S?0:MAX_N);
        }
        priority_queue<pii,vector<pii>, greater<pii> > q;
        q.push(make_pair(d[S],S));
        while(!q.empty())
        {
            pii hold = q.top();
            q.pop();
            int x = hold.second;
            if(hold.first!=d[x])
                continue;
            for(int e=first[x];e!=-1;e=next[e])
            {
                if(d[v[e]]>d[x]+w[e])
                {
                    d[v[e]] = d[x]+w[e];
                    q.push(make_pair(d[v[e]],v[e]));
                }
            }
        }
        if(d[T]!=MAX_N)
            printf("Case #%d: %d\n",cc,d[T]);
        else
            printf("Case #%d: unreachable\n",cc);
        //cout<<d[T]<<endl;
    }
    return 0;
}















