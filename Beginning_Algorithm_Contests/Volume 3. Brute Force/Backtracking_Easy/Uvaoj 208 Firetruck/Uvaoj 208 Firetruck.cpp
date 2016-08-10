#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 25;
int final;
int num;

vector<int> g[maxn];

bool ok[maxn];

void dfs(int s, bool* is){
	ok[s] = true;
	for(int i=0;i<g[s].size();i++){
		int f = g[s][i];
		if(!ok[f])
			dfs(f, is);
	}
}

void pre(){
	num = 0;
	memset(ok, 0, sizeof(ok));
	dfs(final, ok);
}

bool isOk(int f, vector<int>& v){
	for(int i=0;i<v.size();i++)
		if(v[i] == f)
			return false;
	return true;
}

void solve(vector<int>& v)
{
	int n = v.size();
	int start = v[n-1];
	if(start == final){
		num++;
		for(int i=0;i<v.size();i++)
			if(i != 0)
				printf(" %d", v[i]);
			else
				printf("%d", v[i]);
		printf("\n");
		return;
	}
	for(int i=0;i<g[start].size();i++){
		int f = g[start][i];
		if(ok[f] && isOk(f, v)){
			v.push_back(f);
			solve(v);
			v.resize(n);
		}
	}
}

void solve(){
	pre();
	vector<int> v;
	v.push_back(1);
	solve(v);
	printf("There are %d routes from the firestation to streetcorner %d.\n", num, final);
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int kase = 0;
	while(scanf("%d", &final) != EOF){
		printf("CASE %d:\n", ++kase);
		int s, t;
		for(int i=0;i<maxn;i++)
			g[i].clear();
		while(scanf("%d%d", &s, &t) && s){
			g[s].push_back(t);
			g[t].push_back(s);
		}
		for(int i=0;i<maxn;i++)
			sort(g[i].begin(), g[i].end());
		solve();
	}
	return 0;
}