#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

const int maxn = 210;

int n,m;
int start;
int degree[maxn];
bool vis[maxn];
bool is[maxn];
vector<int> v[maxn];

bool dfs(int s){
	vis[s] = true;
	for(int i=0;i<v[s].size();i++){
		int next = v[s][i];
		if(!vis[next])
			dfs(next);
	}
}

bool isConnected(){
	memset(vis, 0, sizeof(vis));
	dfs(start);
	for(int i=0;i<n;i++)
		if(is[i] && !vis[i])
			return false;
	return true;
}

bool solve(){
	if(!isConnected())
		return false;
	for(int i=0;i<n;i++)
		if(degree[i]%2 != 0)
			return false;
	return true;
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d%d", &n, &m) != EOF){
		if(m == 0){
			printf("Not Possible\n");
			continue;
		}
		memset(degree, 0, sizeof(degree));
		memset(is, 0, sizeof(is));
		for(int i=0;i<n;i++)
			v[i].clear();
		for(int i=0;i<m;i++){
			int a, b;
			scanf("%d%d",&a, &b);
			degree[a]++;
			degree[b]++;
			v[a].push_back(b);
			v[b].push_back(a);
			start = a;
			is[a] = is[b] = true;
		}
		bool ok = solve();
		if(ok)
			printf("Possible\n");
		else
			printf("Not Possible\n");
	}
	return 0;
}