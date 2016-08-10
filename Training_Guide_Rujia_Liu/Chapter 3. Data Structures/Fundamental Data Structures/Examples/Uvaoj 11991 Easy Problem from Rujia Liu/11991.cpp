#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct block {
	int idx, v;
	block(int idx, int v):idx(idx), v(v){}
	friend bool operator < (const block & a, const block & b) {
		if(a.v == b.v)
			return a.idx < b.idx;
		return a.v < b.v;
	}
};

vector<block> v;

int solve(int k, int va) {
	auto iter = lower_bound(v.begin(), v.end(), block(0, va));
	if(iter != v.end() && (*iter).v == va) {
		if(k-1 >= v.end() - iter)
			return 0;
		auto iter2 = iter + (k-1);
		if(iter2 != v.end() && (*iter2).v == va)
			return (*iter2).idx;
	}
	return 0;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	// freopen("tofu_out.txt", "w", stdout);
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		v.clear();
		v.reserve(n);
		for(int i=1;i<=n;i++) {
			int data;
			scanf("%d", &data);
			v.push_back(block(i, data));
		}
		sort(v.begin(), v.end());
		for(int i=0;i<m;i++) {
			int k, va;
			scanf("%d%d", &k, &va);
			printf("%d\n", solve(k, va));
		}
	}
	return 0;
}