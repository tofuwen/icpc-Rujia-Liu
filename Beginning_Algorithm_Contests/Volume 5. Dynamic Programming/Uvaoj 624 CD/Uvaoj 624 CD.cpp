#include <cstdio>
#include <cstring>
using namespace std;

const int maxt = 23;
const int maxn = 90000;
const int INF = 1<<30;

int n, t;
int tracks[maxt];

int dp[maxn][maxt];
bool isSelf[maxn][maxt];
int h[maxt];
int numh;

int DP(int rTime, int track){
	if(rTime < 0)
		return -INF;
	if(track < 0)
		return 0;
	if(dp[rTime][track] != -1)
		return dp[rTime][track];
	int self = DP(rTime-tracks[track], track-1) + tracks[track];
	int notSelf = DP(rTime, track-1);
	if(self >= notSelf){
		isSelf[rTime][track] = true;
		return dp[rTime][track] = self;
	}
	return dp[rTime][track] = notSelf;
}

void solve(int rTime, int track){
	if(track < 0 || rTime < 0)
		return;
	if(isSelf[rTime][track]){
		h[numh++] = tracks[track];
		solve(rTime - tracks[track], track-1);
	}
	else
		solve(rTime, track-1);
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d%d",&n, &t) != EOF){
		for(int i=0;i<t;i++)
			scanf("%d",&tracks[i]);
		 memset(dp, -1, sizeof(dp));
		 for(int i=0;i<maxt;i++)
		 	dp[0][i] = 0;
		 memset(isSelf, 0, sizeof(isSelf));
		 int ans = DP(n, t-1);
		 numh = 0;
		 solve(n, t-1);
		 for(int i=numh-1;i>=0;i--)
		 	printf("%d ",h[i]);
		 printf("sum:%d\n",ans);
	}
	return 0;
}