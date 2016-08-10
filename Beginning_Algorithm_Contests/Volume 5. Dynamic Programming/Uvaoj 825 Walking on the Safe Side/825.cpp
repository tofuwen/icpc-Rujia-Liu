#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1010;
bool dont[maxn][maxn];
long long dp[maxn][maxn];
int n, m;

long long DP(int i, int j) {
	// cout << i << j << endl;
	if(dont[i][j] || i < 0 || j < 0)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	return dp[i][j] = DP(i-1, j) + DP(i, j-1);
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	cin >> T;
	for(int cc=0;cc<T;cc++) {
		if(cc)
			cout << endl;
		cin >> n >> m;
		memset(dont, 0, sizeof(dont));
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 1;
		string s;
		getline(cin, s);
		for(int i=0;i<n;i++){
			getline(cin, s);
			stringstream ss(s);
			int a;
			ss >> a;
			while(ss >> a)
				dont[i][a-1] = 1;
		}
		if(dont[0][0] || dont[n-1][m-1]) {
			cout << 0 << endl;
			continue;
		}
		cout << DP(n-1, m-1) << endl;
	}
	return 0;
}