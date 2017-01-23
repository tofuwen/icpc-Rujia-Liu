#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const double log2_10 = log2(10);

int main()
{
	// freopen("data.txt", "r", stdin);
	long long n;
	while (cin >> n) {
		char s[100];
		sprintf(s, "%lld", n);
		int l = strlen(s);
		for (int k = l+1; ; ++k) {
			double left = log2(n) + log2_10 * k;
			double right = log2(n+1) + log2_10 * k;
			int r = (int)right;
			int le = (int)(ceil(left)+0.1);
			if (r == le) {
				cout << r << endl;
				break;
			}
		}
	}
	return 0;
}
