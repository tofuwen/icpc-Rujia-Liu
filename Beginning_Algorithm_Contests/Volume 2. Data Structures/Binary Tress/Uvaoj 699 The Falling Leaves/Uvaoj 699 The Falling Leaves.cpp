#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1<<30;

int data[500];
int front;
int rear;

void next(int degree)
{
	int h;
	scanf("%d",&h);
	if(h==-1)
		return;
	data[degree] += h;
	front = min(front,degree);
	rear = max(rear,degree);
	next(degree-1);
	next(degree+1);
}

int main()
{
	//freopen("data.txt","r",stdin);
	int n;
	int kase = 0;
	while(scanf("%d",&n)!=EOF)
	{
	    //printf("n:%d\n",n);
	    if(n==-1)
            break;
		printf("Case %d:\n",++kase);
		int now = 100;
		front = now;
		rear = now;
		memset(data,0,sizeof(data));
		data[now] += n;
		next(now-1);
		next(now+1);
		for(int i=front;i<=rear;i++)
			if(i==front)
				printf("%d",data[i]);
			else
				printf(" %d",data[i]);
		printf("\n\n");
	}
	return 0;
}
