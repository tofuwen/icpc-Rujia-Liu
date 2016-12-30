#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

const int maxn = 100100;
int a[maxn];

int absolute(int k) {
	return k > 0 ? k : -k;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int n;
	while (cin >> n && n) {
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		ll work = 0;
		for (int i = 0; i < n; ++i) {
			int j = i + 1;
			while (a[i] != 0) {
				if (a[i] * a[j] < 0) {
					if (absolute(a[i]) > absolute(a[j])) {
						work += absolute(a[j]) * (j-i);
						a[i] += a[j];
						a[j] = 0;
						++j;
					} else {
						work += absolute(a[i]) * (j-i);
						a[j] += a[i];
						a[i] = 0;
					}
				} else {
					++j;
				}
			}
		}
		cout << work << endl;
	}
	return 0;
}