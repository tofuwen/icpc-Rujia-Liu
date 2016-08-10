/*
// 此算法可行，但是不太好。
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 10010;

struct edge{
	int des;
	int w;
	edge(int des, int w):des(des),w(w){}
};

vector<edge> g[maxn];
int degree[maxn];
int ans;
int n;
bool v[maxn];

int max(int a, int b, int c){
	return max(max(a,b),c);
}

void dfs(int start, int now){
	if(v[start])
		return;
	v[start] = true;
	ans = max(now, ans);
	for(int i=0;i<g[start].size();i++){
		int nextNode = g[start][i].des;
		if(!v[nextNode])
			dfs(nextNode, now+g[start][i].w);
	}
}

void solve()
{
	for(int i=1;i<=n;i++)
		if(degree[i] == 1){
			memset(v,0,sizeof(v));
			dfs(i,0);
		}
	printf("%d\n",ans);
}

int main()
{
	//freopen("data.txt","r",stdin);
	string line;
	while(getline(cin, line)){
		if(line == ""){
			solve();
			memset(degree, 0 ,sizeof(degree));
			for(int i=0;i<maxn;i++)
				g[i].clear();
			ans = 0;
			n = 0;
			continue;
		}
		stringstream ss(line);
		int s, t, w;
		ss>>s>>t>>w;
		n = max(n, s, t);
		degree[s]++;
		degree[t]++;
		g[s].push_back(edge(t,w));
		g[t].push_back(edge(s,w));
	}
	solve();
	return 0;
}
*/


#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 10010;

struct edge{
	int des;
	int w;
	edge(int des, int w):des(des),w(w){}
};

vector<edge> g[maxn];
int ans;
int hold;
int n;
bool v[maxn];

int max(int a, int b, int c){
	return max(max(a,b),c);
}

void dfs(int start, int now){
	if(v[start])
		return;
	v[start] = true;
	if(ans < now){
		ans = now;
		hold = start;
	}
	for(int i=0;i<g[start].size();i++){
		int nextNode = g[start][i].des;
		if(!v[nextNode])
			dfs(nextNode, now+g[start][i].w);
	}
}

void solve()
{
	memset(v,0,sizeof(v));
	dfs(1, 0);
	memset(v,0,sizeof(v));
	dfs(hold,0);
	printf("%d\n",ans);
}

int main()
{
	//freopen("data.txt","r",stdin);
	string line;
	while(getline(cin, line)){
		if(line == ""){
			solve();
			for(int i=0;i<maxn;i++)
				g[i].clear();
			ans = 0;
			n = 0;
			continue;
		}
		stringstream ss(line);
		int s, t, w;
		ss>>s>>t>>w;
		n = max(n, s, t);
		g[s].push_back(edge(t,w));
		g[t].push_back(edge(s,w));
	}
	solve();
	return 0;
}