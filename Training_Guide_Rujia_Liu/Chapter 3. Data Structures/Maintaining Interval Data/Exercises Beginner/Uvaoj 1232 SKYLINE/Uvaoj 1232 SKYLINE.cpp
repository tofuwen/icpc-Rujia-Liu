#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1<<30;
const int maxn = 100010;
const int lmax = 100010;

int n;//起始数据个数
int minv[4*maxn];
int maxv[4*maxn];
int y1, y2;
int v;

int ans;

void maintain(int o, int L, int R)//维护结点o，对应区间[L,R]
{
	int lc = o*2, rc = o*2+1;
	if(R>L){
		minv[o] = max(min(minv[lc],minv[rc]),minv[o]);
		maxv[o] = max(max(maxv[lc],maxv[rc]),maxv[o]);
	}
}

void update(int o, int L, int R)
{
	int lc = o*2, rc = o*2+1;
	if(minv[o]>v){
			return;
	}
	if(y1<=L && y2>=R){
		if(maxv[o]<=v){
			maxv[o] = v;
			minv[o] = v;
			ans += R-L+1;
			//printf("R:%d L:%d\n",R,L);
			return;
		}
	}
	int M = L+(R-L)/2;
	if(y1<=M)
		update(lc,L,M);
	if(y2>M)
		update(rc,M+1,R);
	maintain(o,L,R);
}

void update()//把Ay1...Ay2的值全部增加v，但是其实并没有改变A数组的值
{
	update(1,0,lmax-5);
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++)
	{
		scanf("%d",&n);
		ans = 0;
		memset(minv,0,sizeof(minv));
		memset(maxv,0,sizeof(maxv));
		for(int i=0;i<n;i++)
		{
			int l,r,h;
			scanf("%d%d%d",&l,&r,&h);
			y1 = l-1;
			y2 = r-2;
			v = h;
			update();
		}
		printf("%d\n",ans);
	}
	scanf("%d",&T);
	return 0;
}