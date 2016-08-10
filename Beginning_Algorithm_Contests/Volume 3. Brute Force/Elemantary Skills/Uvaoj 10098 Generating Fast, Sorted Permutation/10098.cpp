#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char word[100];

int main()
{
	freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++)
	{
		scanf("%s",word);
		int d = strlen(word);
		sort(word,word+d);
		do
		{
			printf("%s\n",word);
		}while(next_permutation(word,word+d));
		putchar('\n');
	}
	return 0;
}