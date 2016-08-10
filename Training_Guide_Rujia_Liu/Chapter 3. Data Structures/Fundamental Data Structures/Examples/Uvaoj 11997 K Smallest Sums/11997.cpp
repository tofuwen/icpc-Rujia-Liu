#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct item {
	int v, idx;
	item(int v, int idx):v(v), idx(idx){}
	friend bool operator < (const item & a, const item & b) {
		return a. v > b.v;
	}
};

const int maxn = 755;

vector<vector<int> > v;

void merge(vector<int> & v1, vector<int> & v2, vector<int> & v3) {
	priority_queue<item> pq;
	int n = v1.size();
	for(int i=0;i<n;i++)
		pq.push(item(v1[i]+v2[0], 0));
	for(int i=0;i<n;i++) {
		item cur = pq.top();
		pq.pop();
		v3[i] = cur.v;
		if(i < n-1)
			pq.push(item(cur.v-v2[cur.idx]+v2[cur.idx+1], cur.idx+1));
	}
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int n;
	while(scanf("%d", &n) != EOF) {
		v.clear();
		v.reserve(n);
		for(int i=0;i<n;i++) {
			v.push_back(vector<int>());
			v[i].reserve(n);
			int d;
			for(int j=0;j<n;j++) {
				scanf("%d", &d);
				v[i].push_back(d);
			}
			sort(v[i].begin(), v[i].end());
		}
		// for(int i=0;i<n;i++)
		// 	for(int j=0;j<n;j++)
		// 		printf("%d\n", v[i][j]);
		for(int i=1;i<n;i++)
			merge(v[0], v[i], v[0]);
		for(int i=0;i<n;i++) {
			if(i)
				printf(" ");
			printf("%d", v[0][i]);
		}
		printf("\n");
	}
	return 0;
}