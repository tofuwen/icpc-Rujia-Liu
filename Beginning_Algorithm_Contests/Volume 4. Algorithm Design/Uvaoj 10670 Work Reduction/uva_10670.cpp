#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct agency {
	int A, B;
	char name[100];
	int cost;
	friend bool operator < (const agency & a, const agency & b) {
		if (a.cost == b.cost)
			return strcmp(a.name, b.name) < 0;
		return a.cost < b.cost;
	}
};

char best_option(int A, int B, int init, int want) {
	if (init / 2 < want)
		return 'A';
	int costA = A * min((init - want), (init - init/2));
	if (costA < B)
		return 'A';
	return 'B';
}

int cal(int A, int B, int init, int want) {
	int ans = 0;
	while(init > want) {
		if (best_option(A, B, init, want) == 'A') {
			ans += A;
			init--;
		} else {
			init /= 2;
			ans += B;
		}
	}
	return ans;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int cc = 0; cc < T; cc++) {
		vector<agency> v;
		int N, M, L;
		scanf("%d%d%d", &N, &M, &L);
		for (int i=0;i<L;i++) {
			agency cur;
			char hold[100];
			scanf("%s", hold);
			char * ptr = strchr(hold, ':');
			*ptr = 0;
			sscanf(hold, "%s", cur.name);
			ptr++;
			sscanf(ptr, "%d,%d", &cur.A, &cur.B);
			cur.cost = cal(cur.A, cur.B, N, M);
			v.push_back(cur);
		}
		sort(v.begin(), v.end());
		printf("Case %d\n", cc+1);
		for (int i=0; i < v.size(); i++) {
			printf("%s %d\n", v[i].name, v[i].cost);
		}
	}
	return 0;
}