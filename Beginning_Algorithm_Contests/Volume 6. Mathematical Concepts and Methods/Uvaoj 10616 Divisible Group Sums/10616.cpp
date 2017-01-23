#include <cstdio>
#include <iostream> 
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

const int maxn = 200 + 10;
const int maxd = 20 + 5;
const int maxm = 10 + 3;

vector<int> v;

int D, M;

ll dp[maxn][maxd][maxm];

ll DP(int n, int cur, int choose) {
	if (choose < 0)
		return 0;
	if (choose == 0 && cur == 0)
		return 1;
	if (choose == 0)
		return 0;
	if (choose > n)
		return 0;
	if (dp[n][cur][choose] != -1)
		return dp[n][cur][choose];
	int c = (v[n-1] % D + D) % D;
	ll ans = DP(n-1, cur, choose) + DP(n-1, (cur+D-c) % D, choose-1);
	return dp[n][cur][choose] = ans;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int N, Q;
	int kase = 0;
	while (cin >> N >> Q && N) {
		v.clear();
		int h;
		for (int i = 0; i < N; ++i) {
			cin >> h;
			v.push_back(h);
		}
		cout << "SET " << ++kase << ":" << endl;
		for (int i = 1; i <= Q; ++i) {
			cin >> D >> M;
			memset(dp, -1, sizeof(dp));
			cout << "QUERY " << i << ": " << DP(N, 0, M) << endl;
		}
	}
	return 0;
}