#include <cstdio>
using namespace std;

const int maxn = 100010;

int fa[maxn];

void init_set(int n) {
	for(int i=0;i<n;i++)
		fa[i] = i;
}

int find_set(int a) {
	return fa[a] == a ? a : fa[a] = find_set(fa[a]);
}

void union_set(int a, int b) {
	int ar = find_set(a);
	int br = find_set(b);
	if(ar < br)
		fa[br] = ar;
	else
		fa[ar] = br;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int a, b;
	while(scanf("%d %d", &a, &b) != EOF) {
		int ans = 0;
		init_set(maxn);
		union_set(a, b);
		while(scanf("%d", &a) && a != -1) {
			scanf("%d", &b);
			int ar = find_set(a);
			int br = find_set(b);
			if(ar == br)
				ans++;
			else
				union_set(a, b);
		}
		printf("%d\n", ans);
	}
	return 0;
}