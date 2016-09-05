#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100010;

bool okay(int p, const vector<int> & r) {
	int n = r.size();
	int left[maxn], right[maxn];
	left[0] = r[0];
	right[0] = 0;
	int left_max = r[0];
	int right_max = p - left_max;
	for (int i=1;i<n;i++) {
		int want = r[i];
		if (i % 2) {
			int left_portion = min(left_max - left[i-1], want);
			int right_portion = want - left_portion;
			if (right_portion > right_max - right[i-1])
				return false;
			left[i] = left_portion;
			right[i] = right_portion;
		} else {
			int right_portion = min(right_max - right[i-1], want);
			int left_portion = want - right_portion;
			if (left_portion > left_max - left[i-1])
				return false;
			left[i] = left_portion;
			right[i] = right_portion;
		}
	}
	return left[n-1] == 0;
}

int solve_odd(const vector<int> & r) {
	int n = r.size();
	if (n == 1)
		return r[0];
	int small = 0;
	int big = 1 << 30;
	while(big - small > 1) {
		int mid = (small + big) / 2;
		if (okay(mid, r))
			big = mid;
		else
			small = mid; 
	}
	return big;
}

int solve(const vector<int> & r) {
	int n = r.size();
	if (n % 2)
		return solve_odd(r);
	int ans = r[0] + r[n-1];
	for(int i=0;i<n-1;i++)
		ans = max(r[i]+r[i+1], ans);
	return ans;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	// freopen("dataout.txt", "w", stdout);
	int n;
	while(scanf("%d", &n) == 1 && n) {
		vector<int> r;
		r.reserve(n);
		for (int i=0;i<n;i++) {
			int a;
			scanf("%d", &a);
			r.push_back(a);
		}
		printf("%d\n", solve(r));
	}
	return 0;
}