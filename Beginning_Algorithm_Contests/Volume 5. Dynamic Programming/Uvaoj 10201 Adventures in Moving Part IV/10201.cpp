#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int large = 1 << 25;
const int INF = 1 << 30;

struct station {
	long long d, c;
	station(long long d, long long c):d(d), c(c){}
};

int dis;
vector<station> v;

long long dp[110][210];

long long DP(int i, int j) {
	if(j < 0 || j > 200)
		return INF;
	if(dp[i][j] != -1)
		return dp[i][j];
	int x = v[i].d - v[i-1].d;
	return dp[i][j] = min(DP(i, j-1) + v[i].c, DP(i-1, j+x));
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	char s[1000];
	scanf("%d\n\n", &T);
	for(int cc=0;cc<T;cc++) {
		if(cc)
			printf("\n");
		v.clear();
		char ss[100];
		gets(ss);
		sscanf(ss, "%d", &dis);
		// printf("dis: %d\n", dis);
		while(gets(s)) {
			// printf("s: %s\n", s);
			int d, c;
			if(sscanf(s, "%d%d", &d, &c) < 2) {
				// printf("s: %s\n", s);
				if(v.size() == 0)
					v.push_back(station(0, large));
				break;
			}
			if(v.size() == 0 && d != 0)
				v.push_back(station(0, large));
			if(d <= dis)
				v.push_back(station(d, c));
		}
		if(v[v.size()-1].d != dis)
			v.push_back(station(dis, large));
		memset(dp, -1, sizeof(dp));
		for(int i=0;i<210;i++) {
			if(i <= 100)
				dp[0][i] = 0;
			else
				dp[0][i] = (i-100) * v[0].c;
		}
		long long ans = DP(v.size()-1, 100);
		// printf("dis: %d\n", dis);
		if(ans >= large) 
			printf("Impossible\n");
		else
			printf("%lld\n", ans);
	}
	return 0;
}