#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 110;
const int INF = 1<<30;

int data[maxn][maxn];

int dp[maxn][maxn];

int DP(int x, int y){
	if(dp[x][y] != -1)
		return dp[x][y];
	dp[x][y] = 1;
	int a[] = {0,0,-1,1};
	int b[] = {1,-1,0,0};
	for(int i=0;i<4;i++){
		int newx = x + a[i];
		int newy = y + b[i];
		if(data[newx][newy] < data[x][y])
			dp[x][y] = max(dp[x][y], DP(newx, newy) + 1);
	}
	return dp[x][y];
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++){
		char s[1000];
		int r, c;
		scanf("%s%d%d", s, &r, &c);
		for(int i=0;i<maxn;i++)
			for(int j=0;j<maxn;j++)
				data[i][j] = INF;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				scanf("%d", &data[i][j]);
		memset(dp, -1, sizeof(dp));
		int M = 0;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				M = max(M, DP(i,j));
		printf("%s: %d\n", s, M);
	}
	return 0;
}