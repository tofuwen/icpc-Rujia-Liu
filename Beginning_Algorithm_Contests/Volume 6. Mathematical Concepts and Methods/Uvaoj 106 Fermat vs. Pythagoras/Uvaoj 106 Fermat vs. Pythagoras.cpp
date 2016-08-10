#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1000010;
const int maxE = 1005;

int n;
int nTriple;
int num;
bool v[maxn];

bool isRelPrime(int a, int b)
{
	return __gcd(a,b)==1;
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
		memset(v,0,sizeof(v));
		nTriple = num = 0;
		for(int i=1;i<maxE;i++)
		{
			for(int j=i+1;j<maxE;j+=2)
			{
				if(i*i+j*j>n)
					break;
				if(isRelPrime(i, j))
				{
					nTriple++;
					int a[3];
					a[0] = j*j-i*i;
					a[1] = 2*i*j;
					a[2] = i*i+j*j;
					for(int t=1;;t++)
						if(t*a[2]<=n)
						{
							for(int k=0;k<3;k++)
							{
								if(!v[a[k]*t])
								{
									v[a[k]*t] = true;
									num++;
								}
							}
						}
						else
							break;
				}
			}
			if(i*i>n)
				break;
		}
		printf("%d %d\n",nTriple,n-num);
	}
	return 0;
}