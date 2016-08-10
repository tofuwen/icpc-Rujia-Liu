#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;

struct command{
	int b;
	int j;
	friend bool operator < (const command& a, const command& b){
		return a.j > b.j;
	}
};

command c[maxn];

int main()
{
	//freopen("data.txt","r",stdin);
	int n;
	int kase = 0;
	while(scanf("%d",&n) && n){
		for(int i=0;i<n;i++)
			scanf("%d%d",&c[i].b,&c[i].j);
		sort(c,c+n);
		int ans = 0;
		int acc = 0;
		for(int i=0;i<n;i++){
			ans = max(ans,acc+c[i].b+c[i].j);
			acc += c[i].b;
		}
		printf("Case %d: %d\n",++kase,ans);
	}
	return 0;
}