#include <cstdio>
#include <algorithm>
using namespace std;

//const long long INF = (long long)(1<<30)*(long long)(1<<30);
const int maxn = 200010;

//使用前需给A[]和n赋完值
int A[maxn];//起始数据,从0开始
int n;//起始数据个数
long long sumv[4*maxn];//从1开始

void init(int o, int L, int R)
{
	int M = L+(R-L)/2;
	if(L==R){
		sumv[o] = A[L];
		return;
	}
	init(o*2,L,M);
	init(o*2+1,M+1,R);
	sumv[o] = sumv[o*2] + sumv[o*2+1];
}

void init()
{
	init(1,0,n-1);
}

long long query(int o, int L, int R, int ql, int qr)//查询[ql,qr]中的最小值
{
	//o: 当前结点编号。从1开始
	//L,R: 当前结点的左右端点。从0开始
	int M = L+(R-L)/2;
	long long ans = 0;
	if(ql<=L && R<=qr)
		return sumv[o];
	if(ql<=M)
		ans += query(o*2,L,M,ql,qr);
	if(M<qr)
		ans += query(o*2+1,M+1,R,ql,qr);
	return ans;
}

int query(int ql, int qr)//查询[ql,qr]中的最小值
{
	return query(1,0,n-1,ql,qr);
}

void update(int o, int L, int R, int p, int v)
{
	int M = L+(R-L)/2;
	if(L==R)
		sumv[o] = v;//叶节点，直接更新minv
	else
	{
		if(p<=M)
			update(o*2,L,M,p,v);
		else
			update(o*2+1,M+1,R,p,v);
		sumv[o] = sumv[o*2] + sumv[o*2+1];
	}
}

void update(int p, int v)//修改：A[p] = v
{
	A[p] = v;
	update(1,0,n-1,p,v);
}

int main()
{
	//freopen("data.txt","r",stdin);
	char c[10];
	int kase = 0;
	while(scanf("%d",&n)!=EOF && n){
		if(kase)
			printf("\n");
		printf("Case %d:\n",++kase);
		for(int i=0;i<n;i++)
			scanf("%d",&A[i]);
		init();
		while(1){
			scanf("%s",c);
			if(c[0]=='E')
				break;
			if(c[0]=='M'){
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%d\n",query(x-1,y-1));
			}
			else{
				int x, r;
				scanf("%d%d",&x,&r);
				update(x-1, r);
			}
		}
	}
	return 0;
}