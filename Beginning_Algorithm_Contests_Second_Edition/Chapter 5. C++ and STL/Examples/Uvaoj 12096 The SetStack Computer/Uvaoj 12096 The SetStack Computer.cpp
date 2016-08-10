#include <cstdio>
#include <map>
#include <algorithm>
#include <iterator>
#include <set>
#include <vector>
#include <stack>
using namespace std;

typedef set<int> Set;

int n;
char h[100];

map<Set, int> m;//the bijection of set and id
vector<Set> v;
Set empty;
stack<int> s;

int ID(Set x)
{
	map<Set, int>::iterator iter = m.find(x);
	if(iter==m.end())
	{
		v.push_back(x);
		return m[x] = v.size()-1;
	}
	return iter->second;
}

void f(char c)
{
	if(c=='P')
	{
		s.push(ID(empty));
		printf("%d\n",v[s.top()].size());
		return;
	}
	if(c=='D')
	{
		s.push(s.top());
		printf("%d\n",v[s.top()].size());
		return;
	}
	Set x;
	Set x1;
	Set x2;
	x1 = v[s.top()];
	s.pop();
	x2 = v[s.top()];
	s.pop();
	if(c=='U')
		set_union(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));
	if(c=='I')
		set_intersection(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));
	if(c=='A')
	{
		x = x2;
		x.insert(m[x1]);
	}
	s.push(ID(x));
	printf("%d\n",v[s.top()].size());
}

int main()
{
	//freopen("data.txt","r",stdin);
	int cases;
	scanf("%d",&cases);
	for(int cc=0;cc<cases;cc++)
	{
		v.clear();
		m.clear();
		while(!s.empty())
			s.pop();
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",h);
			f(h[0]);
		}
		printf("***\n");
	}
	return 0;
}