#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool okay(vector<int> & v) {
	sort(v.begin(), v.end());
	int size = v.size();
	if (v[size-1] == 0)
		return true;
	int num = v[size-1];
	for (int i = size-2; i > size-2-num; --i) {
		if (i < 0)
			return false;
		if (v[i] == 0)
			return false;
		--v[i];
	}
	v.pop_back();
	return okay(v);
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int n;
	while (cin >> n && n) {
		vector<int> v;
		v.reserve(n);
		for(int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		if (okay(v))
			cout << "Possible" << endl;
		else
			cout << "Not possible" << endl;
	}
	return 0;
}