#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 3660;

bool day[maxn];

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++){
		memset(day, 0, sizeof(day));
		int n, p;
		scanf("%d%d", &n, &p);
		int num = 0;
		for(int i=0;i<p;i++){
			int h;
			scanf("%d", &h);
			for(int j=h;j<=n;j+=h){
				if(!day[j] && j%7 != 0 && j%7 != 6){
					day[j] = true;
					num++;
				}
			}
		}
		//for(int i=1;i<=n;i++)
		//	printf("i:%d %d\n",i, day[i]);
		printf("%d\n", num);
	}
	return 0;
}