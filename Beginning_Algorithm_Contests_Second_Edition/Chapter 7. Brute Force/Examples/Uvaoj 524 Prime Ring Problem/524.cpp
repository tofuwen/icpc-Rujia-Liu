#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 16 + 4;
bool is_prime[40];


void dfs(vector<int> & v, bool * is_used, int n) {
	if (v.size() == n) {
		cout << v[0];
		for (int i = 1; i < n; ++i)
			cout << " " << v[i];
		cout << endl;
	}
	int last = v[v.size()-1];
	for (int i = 2; i <= n; ++i) {
		if (is_used[i])
			continue;
		if (is_prime[i + last]) {
			if (v.size() < n-1 || (v.size() == n-1 && is_prime[i + v[0]])) {
				v.push_back(i);
				is_used[i] = true;
				dfs(v, is_used, n);
				is_used[i] = false;
				v.pop_back();
			}
		}
	}
}

void solve(int n) {
	vector<int> ans;
	ans.push_back(1);
	bool is_used[maxn];
	memset(is_used, 0, sizeof(is_used));
	dfs(ans, is_used, n);
}

void pre() {
	memset(is_prime, 0, sizeof(is_prime));
	int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	for (int i = 0; i < 12; ++i)
		is_prime[a[i]] = true;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	pre();
	int n;
	int kase = 0;
	while (cin >> n) {
		if (kase)
			cout << endl;
		cout << "Case " << ++kase << ":" << endl;
		solve(n);
	}
	return 0;
}