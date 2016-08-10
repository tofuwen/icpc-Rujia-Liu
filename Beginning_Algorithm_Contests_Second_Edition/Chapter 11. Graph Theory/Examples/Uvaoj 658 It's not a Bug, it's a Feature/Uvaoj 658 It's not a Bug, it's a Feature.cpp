#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 25;
const int maxm = 110;
const int maxid = (1<<20)+5;
const int INF = 1<<30;

struct patch
{
	char bug[maxn];
	char fix[maxn];
	int time;
};

struct state
{
	bool s[maxn];
	int id;
	int time;
	friend bool operator < (const state& a, const state& b)
	{
		return a.time > b.time;
	}
};

patch p[maxm];
priority_queue<state> q;
int d[maxid];
int n,m;

bool isOkay(state s, patch p)
{
	for(int i=0;i<n;i++)
	{
		if(p.bug[i]=='+' && !s.s[i])
			return false;
		if(p.bug[i]=='-' && s.s[i])
			return false;
	}
	return true;
}

state makeState(state pre, patch p)
{
	state ans;
	for(int i=0;i<n;i++)
		ans.s[i] = pre.s[i];
	for(int i=0;i<n;i++)
	{
		if(p.fix[i]=='+')
			ans.s[i] = true;
		if(p.fix[i]=='-')
			ans.s[i] = false;
	}
	ans.time = pre.time + p.time;
	int id = 0;
	for(int i=0;i<n;i++)
	{
		id = id<<1;
		if(ans.s[i])
			id += 1;
	}
	ans.id = id;
	return ans;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int kase = 0;
	while(scanf("%d%d",&n,&m)&&n)
	{
		bool ok = false;
		for(int i=0;i<m;i++)
			scanf("%d%s%s",&p[i].time,p[i].bug,p[i].fix);
		while(!q.empty())
			q.pop();
		for(int i=0;i<(1<<n)+3;i++)
			d[i] = INF;
		state s1;
		for(int i=0;i<n;i++)
			s1.s[i] = true;
		s1.id = (1<<n)-1;
		s1.time = 0;
		d[s1.id] = 0;
		q.push(s1);
		while(!q.empty())
		{
			state now = q.top();
			q.pop();
			if(now.time!=d[now.id])
				continue;
			//printf("%d\n",now.id);
			if(now.id==0)
			{
				printf("Product %d\nFastest sequence takes %d seconds.\n\n",++kase,now.time);
				ok = true;
				break;
			}
			for(int i=0;i<m;i++)
			{
				if(isOkay(now, p[i]))
				{
					//printf("i:%d\n",i);
					state newOne = makeState(now, p[i]);
					if(d[newOne.id]>newOne.time)
					{
						d[newOne.id] = newOne.time;
						q.push(newOne);
					}
				}
			}
		}
		if(!ok)
			printf("Product %d\nBugs cannot be fixed.\n\n",++kase);
	}
	return 0;
}