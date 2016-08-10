#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 20010;

int fa[maxn];
int d[maxn];

void init_set(int n) {
	for(int i=0;i<n;i++)
		fa[i] = i;
}

int find_set(int a) {
	if(fa[a] == a)
		return a;
	int next = find_set(fa[a]);
	d[a] += d[fa[a]];
	return fa[a] = next;
	// return fa[a] == a ? a : fa[a] = find_set(fa[a]);
}

void union_set(int a, int b) {
	int ar = find_set(a);
	int br = find_set(b);
	fa[ar] = br;
}

int intabs(int x) {
	return x < 0 ? -x : x;
}

int D(int x) {
	int cur = fa[x];
	int f = find_set(x);
	return d[x];
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++) {
		int n;
		scanf("%d", &n);
		init_set(n+1);
		memset(d, 0, sizeof(d));
		char s[10];
		while(scanf("%s", s)) {
			if(s[0] == 'O')
				break;
			if(s[0] == 'E') {
				int data;
				scanf("%d", &data);
				printf("%d\n", D(data));
			}
			else {
				int a, b;
				scanf("%d%d", &a, &b);
				d[a] = D(b) + intabs(a-b) % 1000;
				union_set(a, b);
			}
		}
	}
	return 0;
}