#include <cstdio>
#include <cmath>
using namespace std;

char order[10][10];
char data[10000];

int main()
{
	//freopen("data.txt","r",stdin);
	int n;
	int kase = 0;
	while(scanf("%d",&n))
	{
		if(!n)
			break;
		printf("S-Tree #%d:\n",++kase);
		for(int i=0;i<n;i++)
			scanf("%s",order[i]);
		scanf("%s",data);
		int q;
		scanf("%d",&q);
		for(int i=0;i<q;i++)
		{
			char oldq[10], newq[10];
			scanf("%s",oldq);
			for(int i=0;i<n;i++)
			{
				int h = order[i][1]-'1';
				newq[i] = oldq[h];
			}
			newq[n] = '\0';
			int ans = 0;
			for(int i=0;i<n;i++)
				if(newq[i]=='1')
					ans += 1<<(n-i-1);
			printf("%c",data[ans]);
		}
		printf("\n\n");
	}
	return 0;
}