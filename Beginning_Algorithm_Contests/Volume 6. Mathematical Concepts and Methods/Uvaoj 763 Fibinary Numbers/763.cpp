#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100 + 10;

int num[maxn];

bool okay() {
	for (int i = 0; i < maxn-1; ++i) {
		if (num[i] >= 2 || (num[i] && num[i+1]))
			return false;
	}
	return true;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	string a, b;
	bool is_first = true;
	while (cin >> a >> b) {
		memset(num, 0, sizeof(num));
		int la = a.length();
		int lb = b.length();
		for (int i = 0; i < la; ++i) {
			if (a[i] == '1')
				num[la-1-i]++;
		}
		for (int i = 0; i < lb; ++i) {
			if (b[i] == '1')
				num[lb-1-i]++;
		}
		// for (int i = 0; i < 6; ++i)
		// 	cout << num[i] << endl;
		while (!okay()) {
			for (int i = 0; i < maxn-1; ++i) {
				if (num[i] >= 2) {
					num[i+1]++;
					num[i] -= 2;
					if (i == 1)
						num[i-1]++;
					if (i > 1)
						num[i-2]++;
				}
				if (num[i] && num[i+1]) {
					num[i]--;
					num[i+1]--;
					num[i+2]++;
				}
			}
		}
		if (!is_first)
			cout << endl;
		is_first = false;
		int first_1 = 0;
		for (int i = maxn-1; i >=0; --i) {
			if (num[i]) {
				first_1 = i;
				break;
			}
		}
		for (int i = first_1; i >= 0; --i)
			if (num[i])
				cout << 1;
			else
				cout << 0;
		cout << endl;
	}
	return 0;
}