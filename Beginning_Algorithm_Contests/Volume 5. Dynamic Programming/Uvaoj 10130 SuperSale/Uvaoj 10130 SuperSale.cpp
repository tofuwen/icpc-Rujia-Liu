#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;
const int maxw = 40;

int n;
int price[maxn];
int weight[maxn];

int dp[maxw][maxn];

int DP(int w, int index){
	if(dp[w][index] != -1)
		return dp[w][index];
	if(w == 0)
		return 0;
	if(index < 0)
		return 0;
	if(w >= weight[index])
		return dp[w][index] = max(DP(w, index-1), DP(w-weight[index], index-1)+price[index]);
	return dp[w][index] = DP(w, index-1);
}

int solve(int w){
	memset(dp, -1, sizeof(dp));
	return DP(w, n-1);
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&price[i],&weight[i]);
		int g;
		scanf("%d",&g);
		int ans = 0;
		for(int i=0;i<g;i++){
			int person;
			scanf("%d",&person);
			ans += solve(person);
		}
		printf("%d\n",ans);
	}
	return 0;
}