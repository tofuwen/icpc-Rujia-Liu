#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 6000;
const int INF = 1 << 30;

struct turtle
{
	int w, s;
	turtle(int w, int s):w(w),s(s){}
	friend bool operator < (const turtle & a, const turtle & b) {
		return a.s < b.s;
	}
};

vector<turtle> v;

int main()
{
	// freopen("data.txt", "r", stdin);
	int w, s;
	while(scanf("%d%d", &w, &s) != EOF) {
		if(s < w)
			continue;
		v.push_back(turtle(w, s));
	}
	sort(v.begin(),v.end());
	// for(int i=0;i<v.size();i++)
	// 	printf("%d %d\n", v[i].w, v[i].s);
	int dp[maxn];
	int n = v.size();
	dp[0] = 0;
	for(int i=1;i<=n;i++)
		dp[i] = INF;
	int ans = 0;
	for(int i=0;i<n;i++) {
		for(int j=ans+1;j>=1;j--) {
			if(dp[j-1] + v[i].w < v[i].s)
				dp[j] = min(dp[j], dp[j-1] + v[i].w);
			if(dp[j] < INF)
				ans = max(ans, j);
		}
	}
	printf("%d\n", ans);
	return 0;
}