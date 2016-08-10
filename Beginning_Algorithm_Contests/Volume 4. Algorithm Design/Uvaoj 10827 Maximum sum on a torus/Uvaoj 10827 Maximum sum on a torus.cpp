#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 80;
const int INF = 1<<30;

int data[maxn][maxn];

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++){
		int n;
		scanf("%d",&n);
		memset(data,0,sizeof(data));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int a;
				scanf("%d",&a);
				data[i][j] = data[i-1][j] + data[i][j-1] + a - data[i-1][j-1];
			}
		}
		// for(int i=1;i<=n;i++){
		// 	for(int j=1;j<=n;j++)
		// 		printf("%d ", data[i][j]);
		// 	printf("\n");
		// }
		int ans = -INF;
		for(int index1=1;index1<=n;index1++){
			for(int index2=index1;index2<=n;index2++){
				int mins[maxn], maxs[maxn];
				int all = data[index2][n]-data[index1-1][n];
				mins[0]  = maxs[0] = 0;
				int M = -INF;
				for(int i=1;i<=n;i++)
					mins[i] = min(mins[i-1],data[index2][i-1]-data[index1-1][i-1]);
				//printf("mins1:%d\n",mins[1]);
				for(int i=1;i<=n;i++)
					M = max(M, data[index2][i] - data[index1-1][i] - mins[i]);
				//printf("M:%d\n",M);
				ans = max(M, ans);
				int m = INF;
				for(int i=1;i<=n;i++)
					maxs[i] = max(maxs[i-1],data[index2][i]-data[index1-1][i]);
				if(maxs[n] == 0){
					maxs[n] = -INF;
					//printf("kao\n");
					for(int i=1;i<=n;i++)
						maxs[n] = max(maxs[n], data[index2][i]-data[index1-1][i]);
					//printf("maxs:%d\n", maxs[n]);
				}
				//printf("ans: %d\n",ans);
				for(int i=1;i<=n;i++)
					m = min(m, data[index2][i] - data[index1-1][i] - maxs[i]);
				ans = max(ans,all-m);
			}
		}
		for(int index1=2;index1<=n;index1++){
			for(int index2=index1;index2<=n;index2++){
				int mins[maxn], maxs[maxn];
				int all = data[n][n] - (data[index2][n]-data[index1-1][n]);
				mins[0]  = maxs[0] = 0;
				int M = -INF;
				for(int i=1;i<=n;i++)
					mins[i] = min(mins[i-1],data[n][i-1] - (data[index2][i-1]-data[index1-1][i-1]));
				//printf("mins1:%d\n",mins[1]);
				for(int i=1;i<=n;i++)
					M = max(M, data[n][i] - (data[index2][i] - data[index1-1][i]) - mins[i]);
				//printf("M:%d\n",M);
				ans = max(M, ans);
				int m = INF;
				for(int i=1;i<=n;i++)
					maxs[i] = max(maxs[i-1],data[n][i] - (data[index2][i]-data[index1-1][i]));
				if(maxs[n] == 0){
					maxs[n] = -INF;
					//printf("kao\n");
					for(int i=1;i<=n;i++)
						maxs[n] = max(maxs[n], data[n][i] - (data[index2][i]-data[index1-1][i]));
					//printf("maxs:%d\n", maxs[n]);
				}
				//printf("ans: %d\n",ans);
				for(int i=1;i<=n;i++)
					m = min(m, data[n][i] - (data[index2][i] - data[index1-1][i]) - maxs[i]);
				ans = max(ans,all-m);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}