#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool is_okay(int a, int b) {
	if (a < 1234 || a > 98765 || b < 1234 || b > 98765)
		return false;
	bool vis[12];
	memset(vis, 0, sizeof(vis));
	vis[a % 10] = true;
	vis[(a / 10) % 10] = true;
	vis[(a / 100) % 10] = true;
	vis[(a / 1000) % 10] = true;
	vis[(a / 10000) % 10] = true;
	vis[b % 10] = true;
	vis[(b / 10) % 10] = true;
	vis[(b / 100) % 10] = true;
	vis[(b / 1000) % 10] = true;
	vis[(b / 10000) % 10] = true;
	for (int i = 0; i < 10; ++i)
		if (!vis[i])
			return false;
	return true;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int n;
	bool after_first = false;
	while (cin >> n && n) {
		if (after_first) {
			cout << endl;
		}
		after_first = true;
		bool has_solution = false;
		for (int i = 1234; i < 98765; ++i) {
			if (is_okay(i, i * n)) {
				has_solution = true;
				printf("%05d / %05d = %d\n", n*i, i, n);
				// cout << n * i << " / " << i << " = " << n << endl;
			}
		}
		if (!has_solution)
			cout << "There are no solutions for " << n << "." << endl;
	}
	return 0;
}