#include <cstdio>
using namespace std;

const int maxn = 10010;

int f(char h)
{
	if(h=='o')
		return 1;
	return 0;
}

int main()
{
	//freopen("data.txt","r",stdin);
	char ans[maxn];
	char tape[maxn];
	int n = 0;
	gets(tape);
	while(gets(tape))
	{
		if(tape[0]=='_')
			break;
		int h = 0;
		for(int i=1;i<=9;i++)
		{
			if(i==6)
				continue;
			h *= 2;
			h += f(tape[i]);
		}
		ans[n++] = h;
		//printf("%d\n",h);
	}
	ans[n] = '\0';
	printf("%s",ans);
	return 0;
}