#include <cstdio>
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

void solve(int k) {
	vector<tuple<int, int, int> > v;
	int ans = 0;
	for (int y = k+1; y <= 2*k; ++y) {
		if ((k * y) % (y - k) != 0)
			continue;
		int x = (k * y) / (y - k);
		++ans;
		v.push_back(make_tuple(k, x, y));
	}
	printf("%d\n", ans);
	for (int i = 0; i < v.size(); ++i)
		printf("1/%d = 1/%d + 1/%d\n", get<0>(v[i]), get<1>(v[i]), get<2>(v[i]));
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int n;
	while (cin >> n) {
		solve(n);
	}
	return 0;
}