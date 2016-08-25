#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct leaf {
	int node, dis;
	leaf(int node, int dis):node(node), dis(dis){}
	friend bool operator < (const leaf & a, const leaf & b) {
		return a.dis > b.dis;
	}
};

typedef leaf bfs_node;

const int maxn = 1010;
vector<int> g[maxn];
int d[maxn];
int fa[maxn];
bool is_finish[maxn];

void bfs(int s) {
	memset(d, -1, sizeof(d));
	d[s] = 0;
	fa[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		for(int i=0;i<g[cur].size();i++) {
			int next = g[cur][i];
			if(d[next] == -1) {
				d[next] = d[cur]+1;
				fa[next] = cur;
				q.push(next);
			}
		}
	}
}

void bfs(int node, int dis) {
	bool is_visit[maxn];
	memset(is_visit, 0, sizeof(is_visit));
	bfs_node first = bfs_node(node, 0);
	queue<bfs_node> q;
	q.push(first);
	while(!q.empty()) {
		bfs_node cur = q.front();
		q.pop();
		if(cur.dis > dis)
			break;
		is_visit[cur.node] = 1;
		is_finish[cur.node] = 1;
		for(int i=0;i<g[cur.node].size();i++) {
			int next = g[cur.node][i];
			if(!is_visit[next]) {
				q.push(bfs_node(next, cur.dis+1));
			}
		}
	}
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int s, k;
		scanf("%d%d", &s, &k);
		for (int i=0;i<n-1;i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		bfs(s);
		vector<leaf> v;
		for(int i=1;i<=n;i++) {
			if(g[i].size()==1)
				v.push_back(leaf(i, d[i]));
		}
		sort(v.begin(), v.end());
		memset(is_finish, 0, sizeof(is_finish));
		int ans = 0;
		for(int i=0;i<v.size();i++) {
			leaf cur_leaf = v[i];
			if(is_finish[cur_leaf.node])
				continue;
			if(cur_leaf.dis <= k)
				break;			
			ans++;
			int next_node = cur_leaf.node;
			int level = k;
			while(level--)
				next_node = fa[next_node];
			bfs(next_node, k);
		}
		printf("%d\n", ans);
		for(int i=0;i<=n;i++)
			g[i].clear();
	}
	return 0;
}