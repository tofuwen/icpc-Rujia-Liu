#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;

typedef long long ll;

int other_position(int a, int b) {
	return 6 - a - b;
}

ll move_tower_to_desired(int height, int position, vector<int> desired) {
	assert(desired.size() == height);
	if(height == 1) {
		if(position == desired[0])
			return 0;
		return 1;
	}
	int want = desired[height-1];
	desired.pop_back();
	if(position == want)
		return move_tower_to_desired(height-1, position, desired);
	return (1LL << (height-1)) + move_tower_to_desired(height-1, other_position(position, want), desired);
}

ll move_desired_to_tower(int height, int position, vector<int> desired) {
	return move_tower_to_desired(height, position, desired);
}

ll solve(vector<int> ori, vector<int> want) {
	assert(ori.size() == want.size());
	int h = ori.size();
	int op = ori[h-1];
	int wp = want[h-1];
	ori.pop_back();
	want.pop_back();
	if (h == 1) {
		if(op == wp)
			return 0;
		return 1;
	}
	if (op == wp) {
		return solve(ori, want);
	}
	return move_desired_to_tower(h-1, other_position(op, wp), ori) + 1 + move_tower_to_desired(h-1, other_position(op, wp), want);
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int n;
	int kase = 0;
	while(scanf("%d", &n) && n) {
		vector<int> ori, want;
		for(int i=0;i<n;i++) {
			int a;
			scanf("%d", &a);
			ori.push_back(a);
		}
		for(int i=0;i<n;i++) {
			int a;
			scanf("%d", &a);
			want.push_back(a);
		}
		printf("Case %d: %lld\n", ++kase, solve(ori, want));
	}
	return 0;
}