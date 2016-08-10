#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1010;

struct elephant
{
	int w;
	int s;
	int id;
	elephant(int w, int s, int id):w(w),s(s),id(id){}
	elephant(){}
	friend bool operator < (const elephant& a, const elephant&b)
	{
		return a.w<b.w;
	}
};

elephant e[maxn];
int pre[maxn];
int num[maxn];

int main()
{
	freopen("data.txt","r",stdin);
	int w,s;
	int n = 0;
	while(scanf("%d%d",&w,&s)!=EOF)
	{
		e[n] = elephant(w,s,n+1);
		n++;
	}
		
	//for(int i=0;i<n;i++)
	//	printf("%d\n",e[i].id);
	sort(e,e+n);
	//printf("n:%d\n", n);
	//printf("n\n");
	memset(pre,-1,sizeof(pre));
	for(int i=0;i<n;i++)
		num[i] = 1;
	int Max = 0;
	int ii;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(e[j].w<e[i].w && e[j].s>e[i].s)
			{
				if(num[i]<num[j]+1)
				{
					num[i] = num[j]+1;
					pre[i] = j;
				}
			}
		}
		if(num[i]>Max)
		{
			Max = num[i];
			ii = i;
		}
	}
   // for(int i=0;i<n;i++)
    //    printf("%d\n",pre[i]);
	int ans[maxn];
	int counter = 0;
	for(int i=ii;i!=-1;i=pre[i])
	{
		ans[counter++] = i;
		//if(counter>1500)
		//{
		//	printf("Error!");
		//	break;
		//}
	}
	printf("%d\n",Max);
	for(int i=counter-1;i>=0;i--)
		printf("%d\n",e[ans[i]].id);
	return 0;
}
