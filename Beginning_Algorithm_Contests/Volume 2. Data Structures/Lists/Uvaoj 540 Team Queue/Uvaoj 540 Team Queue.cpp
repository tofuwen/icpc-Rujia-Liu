#include <cstdio>
#include <map>
#include <queue>
using namespace std;


const int maxn = 1010;
int n;
map<int, int> m;
queue<int> q;
queue<int> qp[maxn];
char ins[100];

int main()
{
	//freopen("data.txt","r",stdin);
	int kase = 0;
	while(scanf("%d",&n)==1&&n)
	{
		printf("Scenario #%d\n",++kase);
		m.clear();
		for(int i=0;i<n;i++)
		{
			int num;
			scanf("%d",&num);
			for(int j=0;j<num;j++)
			{
				int h;
				scanf("%d",&h);
				m[h] = i;
			}
		}
		while(scanf("%s",ins))
		{
			if(ins[0]=='S')
				break;
			if(ins[0]=='E')
			{
				int p;
				scanf("%d",&p);
				int team = m[p];
				if(qp[team].empty())
					q.push(team);
				qp[team].push(p);
			}
			if(ins[0]=='D')
			{
				int t1 = q.front();
				int ans = qp[t1].front();
				qp[t1].pop();
				if(qp[t1].empty())
					q.pop();
				printf("%d\n",ans);
			}
		}
		putchar('\n');
		while(!q.empty())
			q.pop();
		for(int i=0;i<n;i++)
			while(!qp[i].empty())
				qp[i].pop();
	}
	return 0;
}