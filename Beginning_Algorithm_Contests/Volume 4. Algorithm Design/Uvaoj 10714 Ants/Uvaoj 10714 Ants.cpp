#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1<<30;

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++){
		int l, n;
		scanf("%d%d",&l,&n);
		int minans = -INF, maxans = -INF;
		for(int i=0;i<n;i++){
			int h;
			scanf("%d",&h);
			minans = max(min(h, l-h), minans);
			maxans = max(maxans, max(h, l-h));
		}
		printf("%d %d\n",minans, maxans);
	}
	return 0;
}