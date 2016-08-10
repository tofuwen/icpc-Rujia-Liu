#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 15;
const int maxk = 40;

int k,n;

struct box
{
	int id;
	int l[maxn];
	friend bool operator < (const box& a, const box& b)
	{
		return a.l[0]<b.l[0];
	}
};

box b[maxk];
int num[maxk];
int pre[maxk];
int m;
int iindex;
int ans[maxk];

bool isSmaller(box a, box b)
{
	for(int i=0;i<n;i++)
		if(a.l[i]>=b.l[i])
			return false;
	return true;
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d%d",&k,&n)!=EOF)
	{
		m = 0;
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<n;j++)
				scanf("%d",&b[i].l[j]);
			sort(b[i].l,b[i].l+n);
			b[i].id = i+1;
		}
		sort(b,b+k);
		//  for(int i=0;i<k;i++)
		//  	printf("%d ",b[i].id);
		// printf("\n");
		for(int i=0;i<k;i++)
			num[i] = 1;
		memset(pre,-1,sizeof(pre));
		//num[0] = 1;
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(isSmaller(b[j], b[i]))
				{
					if(num[j]+1>num[i])
					{
						num[i] = num[j]+1;
						pre[i] = j;
					}
				}
			}
			if(m<num[i])
			{
				m = num[i];
				iindex = i;
			}
		}
		// printf("pre7 %d num[7] %d\n",pre[7],num[7]);
		// printf("pre4 %d num[4] %d\n",pre[4],num[4]);
		 //printf("pre1 %d num[1] %d\n",pre[1],num[1]);
		// printf("isSmaller: %d\n",isSmaller(b[2], b[4]));
		int counter = 0;
		 for(int i=iindex;i!=-1;i=pre[i])
		 	ans[counter++] = b[i].id;
		printf("%d\n",counter);
		for(int i=0;i<counter;i++)
			printf("%d ", ans[counter-1-i]);
		printf("\n");
	}
	return 0;
}