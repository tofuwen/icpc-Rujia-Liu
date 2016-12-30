#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 20;
int a[maxn];

int main()
{
	// freopen("data.txt", "r", stdin);
	int n;
	int kase = 0;
	while (cin >> n) {
		ll ans = 0;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				ll cur = 1;
				for (int k = i; k <= j; ++k)
					cur *= a[k];
				ans = max(ans, cur);
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", ++kase, ans);
	}
	return 0;
}