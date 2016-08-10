#include <iostream>
#include <cstdio>
using namespace std;

long long sg(long long x) {
	if(x == 1)
		return 0; 
	if(x % 2 == 0)
		return x / 2;
	return sg(x/2);
}

int main()
{
	freopen("data.txt", "r", stdin);
	long long T;
	cin >> T;
	while(T--) {
		long long n;
		cin >> n;
		long long ans = 0;
		while(n--) {
			long long x;
			cin >> x;
			ans ^= sg(x);
		}
		if(ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}