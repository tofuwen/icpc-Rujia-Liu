/*
//The number is so hugr!!
//Brute force don't work!!
#include <cstdio>
#include <map>
using namespace std;

const int maxn = 10000000;
map<long long, int> m;

int main()
{
    //freopen("dataout.txt","w",stdout);
	for(int i=0;i<maxn;i++)
	{
		long long k;
		k = ((long long)i)*i;
		m[k] = i;
	}
	int count = 0;
	for(int i=2;;i++)
	{
		long long k = ((long long)i)*(i+1)/2;
		//printf("k:%lld\n",k);
		if(k%4==0||k%4==1)
		{
			map<long long, int>::iterator iter = m.find(k);
			if(iter!=m.end())
			{
				count++;
				int hold = iter->second;
				printf("%10d %10d\n",hold,i);
				if(count>=8)
					break;
			}
		}
	}
	return 0;
}
*/


#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int a[15];
	int b[15];
	a[0] = 6;
	a[1] = 35;
	for(int i=2;i<10;i++)
		a[i] = 6*a[i-1]-a[i-2];
	for(int i=0;i<10;i++)
		b[i] = floor(sqrt(2.0*a[i]*a[i]));
	for(int i=0;i<10;i++)
		printf("%10d%10d\n",a[i],b[i]);
	return 0;
}