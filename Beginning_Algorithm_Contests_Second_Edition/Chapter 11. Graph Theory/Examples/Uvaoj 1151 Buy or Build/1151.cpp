#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const long long maxq = 8 + 2;
const long long maxn = 1000 + 10;

long long n, q;

struct combo {
	long long cost;
	vector<long long> v;
};

struct edge {
	long long s, t;
	long long cost;
	friend bool operator < (const edge & a, const edge & b) {
		return a.cost < b.cost;
	}
	edge(long long s, long long t, long long cost):s(s), t(t), cost(cost){}
};

combo com[maxq];
long long x[maxn];
long long y[maxn];

long long fa[maxn];

void init_set(long long n) {
	for(long long i=0;i<n;i++)
		fa[i] = i;
}

long long find_set(long long a) {
	return fa[a] == a ? a : fa[a] = find_set(fa[a]);
}

void union_set(long long a, long long b) {
	long long ar = find_set(a);
	long long br = find_set(b);
	if(ar < br)
		fa[br] = ar;
	else
		fa[ar] = br;
}

long long cal(long long i, long long j) {
	return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

void solve() {
	vector<edge> edges;
	for (long long i = 0; i < n; ++i) {
		for (long long j = i+1; j < n; ++j) {
			edges.push_back(edge(i, j, cal(i, j)));
		}
	}
	sort(edges.begin(), edges.end());
	init_set(n);
	vector<edge> useful;
	for (long long i = 0; i < edges.size(); ++i) {
		if (find_set(edges[i].s) != find_set(edges[i].t)) {
			useful.push_back(edges[i]);
			union_set(edges[i].s, edges[i].t);
			if (useful.size() == n-1)
				break;
		}
	}
	long long ans = 1 << 30;
	for (long long i = 0; i < (1<<q); ++i) {
		init_set(n);
		long long cur = 0;
		for (long long j = 0; j < q; ++j) {
			if ((1<<j) & i) {
				cur += com[j].cost;
				for (long long k = 1; k < com[j].v.size(); ++k) {
					// This is wrong!
					// fa[com[j].v[k]] = com[j].v[0]; 
					union_set(com[j].v[k], com[j].v[0]);
				}
			}
		}
		for (long long j = 0; j < useful.size(); ++j) {
			if (find_set(useful[j].s) != find_set(useful[j].t)) {
				union_set(useful[j].s, useful[j].t);
				cur += useful[j].cost;
			}
		}
		ans = min(ans, cur);
	}
	cout << ans << endl;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	long long T;
	cin >> T;
	for (long long cc = 0; cc < T; ++cc) {
		if (cc)
			cout << endl;
		cin >> n >> q;
		for (long long i = 0; i < q; ++i) {
			long long num;
			cin >> num;
			cin >> com[i].cost;
			com[i].v.clear();
			for (long long j = 0; j < num; ++j) {
				long long h;
				cin >> h;
				com[i].v.push_back(h-1);
			}
			sort(com[i].v.begin(), com[i].v.end());
		}
		for (long long i = 0; i < n; ++i)
			cin >> x[i] >> y[i];
		solve();
	}
	return 0;
}