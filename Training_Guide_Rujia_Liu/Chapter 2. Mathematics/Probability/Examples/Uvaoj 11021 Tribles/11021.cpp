#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

const int maxn = 1010;

int n, k, m;
double P[maxn];

double f[maxn];

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	cin >> T;
	for(int cc=1;cc<=T;cc++) {
		cin >> n >> k >> m;
		for(int i=0;i<n;i++)
			cin >> P[i];
		f[0] = 0.0;
		f[1] = P[0];
		for(int i=2;i<=m;i++) {
			f[i] = 0;
			for(int j=0;j<n;j++) {
				f[i] += P[j] * pow(f[i-1], j);
			}
		}
		cout << "Case #" << cc << ": " << pow(f[m], k) << endl;
	}
	return 0;
}