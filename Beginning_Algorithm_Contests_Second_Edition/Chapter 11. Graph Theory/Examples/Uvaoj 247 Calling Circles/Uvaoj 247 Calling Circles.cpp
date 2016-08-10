#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>//用min函数
#include <stack>
#include <map>
#define MAXN 50 //最多10000个点
using namespace std;


int n,m;//n：顶点个数 m：边的个数
vector<int> g[MAXN];//计数从0开始
//每个case之前别忘记clear
int dfn[MAXN];//从1开始
int low[MAXN];//从1开始
int iindex;//记录时间，求dfn用的
bool instack[MAXN];
int nSCC;//执行完solve(),存有多少个SCC
int belg[MAXN];//存储强连通分量,其中belg[i]表示顶点i属于第belg[i]个强连通分量，从第0个强连通分量开始
int many[MAXN];//存贮第i个强连通分量有多少个点
stack<int> s;
map<string, int> Map;
string mapID[MAXN];
vector<int> ans[MAXN];

void init()
{
	int id = 0;
    for(int i=0;i<MAXN;i++)
    {
    	g[i].clear();
    	ans[i].clear();
    }
    Map.clear();
    for(int i=0;i<m;i++)
    {
    	string s1,s2;
    	int id1, id2;
    	cin>>s1>>s2;
    	if(!Map.count(s1))
    	{
    		id1 = id;
    		mapID[id] = s1;
    		Map[s1] = id++;
    	}
    	else
    		id1 = Map[s1];
    	if(!Map.count(s2))
    	{
    		id2 = id;
    		mapID[id] = s2;
    		Map[s2] = id++;
    	}
    	else
    		id2 = Map[s2];
        g[id1].push_back(id2);
    }
}

void tarjan(int start)
{
    dfn[start] = low[start] = ++iindex;
    instack[start] = true;
    s.push(start);
    for(int i=0;i<g[start].size();i++)
    {
        int hold = g[start][i];
        if(!dfn[hold])
        {
            tarjan(hold);
            low[start] = min(low[start],low[hold]);
        }
        else
        {
            if(instack[hold])
                low[start] = min(low[start],dfn[hold]);
        }
    }
    if(dfn[start]==low[start])
    {
        int hold;
        do
        {
            hold = s.top();
            s.pop();
            belg[hold] = nSCC;
            ans[nSCC].push_back(hold);
            instack[hold] = false;
            many[nSCC]++;
        }while(hold!=start);
        nSCC++;
    }
}

void solve()
{
    memset(dfn,0,sizeof(dfn));
    memset(many,0,sizeof(many));
    memset(instack,0,sizeof(instack));
    nSCC = iindex = 0;
    while(!s.empty())
        s.pop();
    for(int i=0;i<n;i++)
        if(!dfn[i])
            tarjan(i);
}

int main()
{
    //freopen("data.txt","r",stdin);
    int kase = 0;
    while(scanf("%d%d",&n,&m)&&n)
    {
    	if(kase)
    		printf("\n");
    	printf("Calling circles for data set %d:\n",++kase);
        init();
        solve();
        for(int i=0;i<nSCC;i++)
        {
        	int thisNum = ans[i].size();
        	for(int j=0;j<thisNum;j++)
        	{
        		if(j!=thisNum-1)
        			cout<<mapID[ans[i][j]]<<", ";
        		else
        			cout<<mapID[ans[i][j]]<<endl;
        	}
        }
    }
    return 0;
}