#include <cstdio>
using namespace std;

const int maxn = 30010;
const int nWay = 11;

int n, point;
long long dp[nWay][maxn];
int a[nWay] = {5,10,20,50,100,200,500,1000,2000,5000,10000};

long long DP(int i, int j)
{
	if(j<0)
		return 0;
	return dp[i][j];
}

void pre()
{
	for(int i=0;i<nWay;i++)
		dp[i][0] = 1;
	for(int i=0;i<maxn;i++)
		dp[0][i] = 1;
	for(int i=1;i<nWay;i++)
		for(int j=1;j<maxn;j++)
			dp[i][j] = dp[i-1][j]+DP(i,j-a[i]);
}

int main()
{
	//freopen("data.txt","r",stdin);
	pre();
	while(scanf("%d.%d",&n,&point))
	{
		if(n==0&&point==0)
			break;
		int way = n*100+point;
		char s[10];
		if(point<10)
		{
			s[0] = '0';
			s[1] = '0'+point;
			s[2] = '\0';
		}
		else
		{
			s[0] = point/10+'0';
			s[1] = point%10+'0';
			s[2] = '\0';
		}
		printf("%3d.%s",n,s);
		printf("%17lld\n",dp[nWay-1][way]);
	}
	return 0;
}