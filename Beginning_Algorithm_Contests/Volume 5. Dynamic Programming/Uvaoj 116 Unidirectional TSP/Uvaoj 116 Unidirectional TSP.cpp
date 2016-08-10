#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxm = 15;
const int maxn = 110;
const int inf = 1<<30;
const int INF = 1<<30;

int m,n;
int data[maxm][maxn];
int pre[maxm][maxn];
int dp[maxm][maxn];

struct Ans
{
	int a[maxn];
	friend bool operator < (const Ans& a1, const Ans& a2)
	{
		int i;
		for(i=0;i<n;i++)
			if(a1.a[i]!=a2.a[i])
				break;
		if(i==n)
			return true;
		return a1.a[i]<a2.a[i];
	}
};

Ans an[maxm];

int make(int x, int incre)
{
	if(x==0&&incre==-1)
		return m-1;
	if(x==m-1&&incre==1)
		return 0;
	return x+incre;
}

bool isSmaller(int a1[], int a2[], int num)
{
	int i;
	for(i=0;i<num;i++)
		if(a1[i]!=a2[i])
			break;
	if(i==num)
		return false;
	return a1[i]<a2[i];
}

int g(int row, int col, int x1, int x2)
{
	int a1[maxn];
	int a2[maxn];
	int hold = x1;
	for(int i=col-1;i>=0;i--)
	{
		a1[i] = hold+1;
		hold = pre[hold][i];
	}
	hold = x2;
	for(int i=col-1;i>=0;i--)
	{
		a2[i] = hold+1;
		hold = pre[hold][i];
	}
	if(isSmaller(a1,a2,col))
		return x1;
	return x2;
}

int f(int i, int j)
{
	int ans = INF;
	/*
	if(j==0)
	{
		if(ans>dp[0][i-1])
		{
			ans = dp[0][i-1];
			pre[j][i] = 0;
		}
		if(ans>dp[1][i-1])
		{
			ans = dp[1][i-1];
			pre[j][i] = 1;
		}
		if(ans>dp[m-1][i-1])
		{
			ans = dp[m-1][i-1];
			pre[j][i] = m-1;
		}
		return dp[j][i] = ans+data[j][i];
	}
	if(j==m-1)
	{
		if(ans>dp[0][i-1])
		{
			ans = dp[0][i-1];
			pre[j][i] = 0;
		}
		if(ans>dp[m-2][i-1])
		{
			ans = dp[m-2][i-1];
			pre[j][i] = m-2;
		}
		if(ans>dp[m-1][i-1])
		{
			ans = dp[m-1][i-1];
			pre[j][i] = m-1;
		}
		return dp[j][i] = ans+data[j][i];
	}
	*/
	for(int k=-1;k<=1;k++)
	{
		int preIndex = make(j,k);
		int h = dp[preIndex][i-1];
		if(ans>=h)
		{
			if(ans>h)
			{
				ans = h;
				pre[j][i] = preIndex;
			}
			else
			{
				pre[j][i] = g(j,i,pre[j][i],preIndex);
			}
		}
	}
	return dp[j][i] = ans+data[j][i];
}

void write(int num, int position)
{
	int hold = position;
	for(int i=n-1;i>=0;i--)
	{
		an[num].a[i] = hold+1;
		hold = pre[hold][i];
	}
}

int main()
{
	//freopen("data.txt", "r", stdin);
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		memset(pre,-1,sizeof(pre));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&data[i][j]);
		// for(int i=0;i<m;i++)
		// {
		// 	for(int j=0;j<n;j++)
		// 		printf("%d ",data[i][j]);
		// 	printf("\n");
		// }
		for(int i=0;i<m;i++)
			dp[i][0] = data[i][0];
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				f(i,j);
			}
		}
		 // for(int i=0;i<m;i++)
		 // {
		 // 	for(int j=0;j<n;j++)
		 // 		printf("%d ",dp[i][j]);
		 // 	printf("\n");
		 // }
		int minValue = INF;
		for(int i=0;i<m;i++)
			minValue = min(minValue,dp[i][n-1]);
		int counter = 0;
		for(int i=0;i<m;i++)
		{
			if(dp[i][n-1]==minValue)
				write(counter++,i);
		}
		sort(an,an+counter);
		for(int i=0;i<n;i++)
			if(i!=n-1)
				printf("%d ",an[0].a[i]);
			else
				printf("%d\n",an[0].a[i]);
		printf("%d\n", minValue);
	}
	return 0;
}