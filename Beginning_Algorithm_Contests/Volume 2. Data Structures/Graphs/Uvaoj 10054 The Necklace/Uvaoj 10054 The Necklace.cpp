#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

const int nColor = 55;
const int maxn = 1010;

struct necklace
{
	int x, y, id;
	necklace(int x, int y, int id):x(x),y(y), id(id){}
};

int n;
int start;
vector<necklace> v;
vector<pair<int, int> > p[nColor];
vector<int> g[nColor];
int inDegree[nColor];
int outDegree[nColor];
bool isColor[nColor];
bool vis[nColor];
bool visPrint[maxn];

void dfs(int start){
	vis[start] = true;
	for(int i=0;i<g[start].size();i++){
		int next = g[start][i];
		if(!vis[next])
			dfs(next);
	}
}

bool isConnected(){
	memset(vis, 0, sizeof(vis));
	dfs(start);
	for(int i=0;i<nColor;i++)
		if(isColor[i] && !vis[i])
			return false;
	return true;
}

bool isOkay(){
	if(!isConnected())
		return false;
	for(int i=0;i<nColor;i++){
		//printf("i:%d in:%d out:%d\n",i, inDegree[i], outDegree[i]);
		if((inDegree[i] + outDegree[i])%2 == 1)
			return false;
	}
	return true;
}

stack<necklace> Stack;

void print(int s){
	for(int i=0;i<p[s].size();i++){
		pair<int, int> now = p[s][i];
		if(!visPrint[now.first]){
			visPrint[now.first] = true;
			print(now.second);
			Stack.push(necklace(s, now.second, now.first));
		}
	}
}

void printEuler(int s){ // 参数必须是道路的起点。
	memset(visPrint, 0, sizeof(visPrint));
	print(s);
	while(!Stack.empty()){
		necklace now = Stack.top();
		Stack.pop();
		printf("%d %d\n", now.x, now.y);
	}
}


int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d", &T);
	for(int cc=1;cc<=T;cc++){
		if(cc > 1)
			printf("\n");
		printf("Case #%d\n",cc);
		v.clear();
		memset(inDegree, 0, sizeof(inDegree));
		memset(outDegree, 0, sizeof(outDegree));
		memset(isColor, 0, sizeof(isColor));
		for(int i=0;i<nColor;i++){
			g[i].clear();
			p[i].clear();
		}
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			int a, b;
			scanf("%d%d",&a,&b);
			inDegree[a]++;
			outDegree[b]++;
			isColor[a] = isColor[b] = true;
			start = b;
			v.push_back(necklace(a,b,i));
			g[a].push_back(b);
			g[b].push_back(a);
			p[a].push_back(make_pair(i, b));
			p[b].push_back(make_pair(i, a));
		}
		bool ans = isOkay();
		//printf("ans:%d\n", ans);
		if(ans)
			printEuler(start);
		else
			printf("some beads may be lost\n");
	}
	return 0;
}

