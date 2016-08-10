#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 505;

struct cube{
	int color[6];
};

cube c[maxn];

int dp[6*maxn];
int p[6*maxn];

vector<int> g[maxn * 6];

string s[6] = {"front","back","left","right","top","bottom"};

bool ok(int i, int j){
	int n1 = i / 6;
	int n2 = j / 6;
	int m1 = i - n1 * 6;
	int m2 = j - n2 * 6;
	int c1 = c[n1].color[m1];
	int c2 = c[n2].color[m2^1];
	return n1 > n2 && c1 == c2;
}

int DP(int i){
	if(dp[i] != -1)
		return dp[i];
	int ans = 1;
	for(int j=0;j<g[i].size();j++){
		int h = DP(g[i][j]) + 1;
		if(h > ans){
			ans = h;
			p[i] = g[i][j];
		}
	}
	return dp[i] = ans;
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int n;
	int kase = 0;
	while(scanf("%d", &n) && n){
		for(int i=0;i<n;i++){
			for(int j=0;j<6;j++)
				scanf("%d", &c[i].color[j]);
		}
		for(int i=0;i<6*maxn;i++)
			g[i].clear();
		for(int i=6;i<6*n;i++){
			for(int j=0;j<i;j++){
				if(ok(i, j))
					g[i].push_back(j);
			}
		}
		memset(dp, -1, sizeof(dp));
		memset(p, -1, sizeof(p));
		// for(int i=0;i<6*n;i++){
		// 	for(int j=0;j<g[i].size();j++)
		// 		printf("%d ", g[i][j]);
		// 	printf("\n");
		// }
		int M = 0;
		for(int i=6*n-1;i>=0;i--)
			M = max(M, DP(i));
		if(kase >= 1)
			printf("\n");
		printf("Case #%d\n", ++kase);
		printf("%d\n", M);
		int start;
		for(start=6*n-1;start>=0;start--)
			if(dp[start] == M)
				break;
		vector<int> v;
		while(start != -1){
			v.push_back(start);
			start = p[start];
		}
		for(int i=v.size()-1;i>=0;i--){
			cout << v[i]/6 + 1 << " " << s[v[i]%6] << endl;
		}
	}
	return 0;
}