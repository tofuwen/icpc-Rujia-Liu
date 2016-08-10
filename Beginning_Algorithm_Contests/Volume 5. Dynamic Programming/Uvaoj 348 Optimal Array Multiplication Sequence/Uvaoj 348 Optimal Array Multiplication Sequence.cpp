#include <cstdio>
#include <cstring>
//#include <algorithm>
using namespace std;

struct matrix
{
	int first;
	int second;
};

const int INF = 1<<30;
const int maxn = 20;
int n;
matrix data[maxn];
int dp[maxn][maxn];
int cut[maxn][maxn];

int DP(int i, int j){
	if(dp[i][j] != -1)
		return dp[i][j];
	int m = INF;
	//int cutp = 0;
	for(int c=i;c<j;c++){
		int hold = DP(i,c) + DP(c+1,j) + data[i].first*data[c].second*data[j].second;
		if(m > hold){
			m = hold;
			cut[i][j] = c;
		}
	}
	return dp[i][j] = m;
}

void print(int i, int j){
	if(i == j){
		printf("A%d", i+1);
		return;
	}
	printf("(");
	print(i, cut[i][j]);
	printf(" x ");
	print(cut[i][j]+1, j);
	printf(")");
}

int main()
{
	//freopen("data.txt","r",stdin);
	int kase = 0;
	while(scanf("%d",&n) && n){
		printf("Case %d: ", ++kase);
		for(int i=0;i<n;i++)
			scanf("%d%d",&data[i].first, &data[i].second);
		memset(dp,-1,sizeof(dp));
		memset(cut,-1,sizeof(cut));
		for(int i=0;i<maxn;i++)
			dp[i][i] = 0;
		DP(0, n-1);
		print(0, n-1);
		printf("\n");
	}
	return 0;
}