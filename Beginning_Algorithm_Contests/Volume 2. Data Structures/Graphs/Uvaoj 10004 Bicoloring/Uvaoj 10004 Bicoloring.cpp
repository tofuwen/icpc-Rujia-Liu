#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 210;

int n, m;

vector<int> g[maxn];
int color[maxn];

bool dfs(int index, int c){
	color[index] = c;
	for(int i=0;i<g[index].size();i++){
		int target = g[index][i];
		if(color[target] == c)
			return false;
		if(color[target] == -1){
			bool okay = dfs(target, 1^c);
			if(!okay)
				return false;
		}
	}
	return true;
}

bool solve(){
	memset(color, -1, sizeof(color));
	return dfs(0,0);
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d", &n) && n){
		for(int i=0;i<n;i++)
			g[i].clear();
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int a, b;
			scanf("%d%d",&a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		bool ok = solve();
		// for(int i=0;i<n;i++)
		// 	printf("c:%d\n",color[i]);
		if(ok)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
	}
	return 0;
}