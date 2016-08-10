#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1100;
const int mod = 34943;

char s[maxn];
int pow_table[maxn];

void pre()
{
	pow_table[0] = 1;
	for(int i=1;i<maxn;i++)
		pow_table[i] = (256*pow_table[i-1])%mod;
}

void toUpperCase(char h[])
{
	for(int i=0;i<strlen(h);i++)
		if(h[i]>='a'&&h[i]<='z')
			h[i] += 'A'-'a';
}

void print(char first[], char second[])
{
	toUpperCase(first);
	toUpperCase(second);
	if(strlen(first)==1)
		printf("0");
	printf("%s ",first);
	if(strlen(second)==1)
		printf("0");
	printf("%s\n",second);
}

int main()
{
	//freopen("data.txt","r",stdin);
	pre();
	while(1)
	{
		gets(s);
		if(s[0]=='#')
			break;
		int cc = 2;
		int va = 0;
		for(int i=strlen(s)-1;i>=0;i--)
		{
			va += (int)s[i]*pow_table[cc++];
			va %= mod;
		}
		int want = (mod-va)%mod;
		char first[10];
		char second[10];
		sprintf(first,"%x",want/256);
		sprintf(second,"%x",want%256);
		print(first,second);
	}
	return 0;
}