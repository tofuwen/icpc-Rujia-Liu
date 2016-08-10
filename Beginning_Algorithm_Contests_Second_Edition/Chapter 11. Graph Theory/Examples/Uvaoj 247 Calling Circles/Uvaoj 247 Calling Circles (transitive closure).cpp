#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

const int MAXN = 50;

map<string, int> Map;
string mapID[MAXN];
int n,m;
int d[MAXN][MAXN];
vector<int> ans[MAXN];


void init()
{
    for(int i=0;i<MAXN;i++)
        ans[i].clear();
	int id = 0;
    memset(d,0,sizeof(d));
    for(int i=0;i<MAXN;i++)
        d[i][i] = 1;
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
        d[id1][id2] = 1;
    }
}

void transitive_closure()
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                d[i][j] = d[i][j]||(d[i][k]&&d[k][j]);
}

int solve()
{
    transitive_closure();
    int cur = 0;
    bool v[MAXN];
    memset(v,0,sizeof(v));
    for(int i=0;i<n;i++)
    {
        if(v[i])
            continue;
        v[i] = true;
        ans[cur].push_back(i);
        for(int j=i+1;j<n;j++)
            if(!v[j]&&d[i][j]&&d[j][i])
            {
                ans[cur].push_back(j);
                v[j] = true;
            }
        cur++;
    }
    return cur;
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
        int Num = solve();
        for(int i=0;i<Num;i++)
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