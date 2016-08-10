#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000;
const int maxl = 1000;

char data[maxn][maxl];

bool isSub(char c1[], char c2[])
{
	int l1 = strlen(c1);
	int l2 = strlen(c2);
	int l = min(l1,l2);
	for(int i=0;i<l;i++)
		if(c1[i]!=c2[i])
			return false;
	return true;
}

bool solve(int n)
{
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(isSub(data[i],data[j]))
				return true;
	return false;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int n = 0;
	int kase = 0;
	while(scanf("%s",&data[n])!=EOF)
	{
		if(data[n][0]=='9'){
			bool ok = solve(n);
			if(ok)
				printf("Set %d is not immediately decodable\n",++kase);
			else
				printf("Set %d is immediately decodable\n",++kase);
			n = 0;
			continue;
		}
		n++;
	}
	return 0;
}