#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 30;
int rank[maxn];
int n;
int data[maxn];
int num[maxn];
int d[maxn];
int m;

bool isSmaller(int a, int b)
{
	return rank[a]<rank[b];
}

bool cmp(int a, int b)
{
	return d[a-1]<d[b-1];
}

int main()
{
	//freopen("data.txt", "r", stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		//rank[x] = i;
		rank[i] = x;
	}
	while(scanf("%d",&d[0])==1)
	{
		m = 1;
		for(int i=1;i<n;i++)
			scanf("%d",&d[i]);
		for(int i=0;i<n;i++)
			data[i] = i+1;
		sort(data,data+n,cmp);
		memset(num,0,sizeof(num));
		num[0] = 1;
		for(int i=1;i<n;i++)
		{
			int ans = 1;
			for(int j=0;j<i;j++)
			{
				if(isSmaller(data[j], data[i]))
					ans = max(ans,num[j]+1);
			}
			num[i] = ans;
			m = max(num[i],m);
		}
		// for(int i=0;i<n;i++)
		//  	printf("%d", data[i]);
		//  putchar('\n');
		printf("%d\n",m);
	}
	return 0;
}