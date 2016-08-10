#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

const int maxn = 50000;
int a[maxn];
long long b[maxn];

int digit(int num)
{
	if(0<=num&&num<=9)
		return 1;
	if(10<=num&&num<=99)
		return 2;
	if(100<=num&&num<=999)
		return 3;
	if(1000<=num&&num<=9999)
		return 4;
	if(10000<=num&&num<=99999)
		return 5;
}

int cal(int num, int p)
{
   // printf("kao\n");
    //printf("num:%d p:%d\n",num,p);
	char s[100];
	sprintf(s,"%d",num);
	return s[p-1]-'0';
}

void pre()
{
	a[0] = b[0] = 0;
	for(int i=1;i<maxn;i++)
		a[i] = digit(i)+a[i-1];
	for(int i=1;i<maxn;i++)
		b[i] = b[i-1]+a[i];
}

int main()
{
	//freopen("data.txt","r",stdin);
	//freopen("dataout.txt","w",stdout);
	int T;
	scanf("%d",&T);
	pre();
	//for(int i=0;i<maxn;i++)
    //    printf("%lld\n",b[i]);
	for(int cc=0;cc<T;cc++)
	{
		long long k;
		scanf("%lld",&k);
		int p = lower_bound(b, b+maxn, k) - b;
		//printf("p:%d\n",p);
		if(b[p]==k)
			printf("%d\n",p%10);
		else
		{
			int r = k-b[p-1];
			//printf("k:%d b[p-1]: %d\n",k,b[p-1]);
			int q = lower_bound(a, a+maxn, r) - a;
			//printf("kao\n");
			if(a[q]==r)
				printf("%d\n",q%10);
			else
			{
				int rr = r - a[q-1];
				//printf("r:%d a[q-1]: %d\n",r,a[q-1]);
				printf("%d\n",cal(q,rr));
			}
		}
	}
	return 0;
}
