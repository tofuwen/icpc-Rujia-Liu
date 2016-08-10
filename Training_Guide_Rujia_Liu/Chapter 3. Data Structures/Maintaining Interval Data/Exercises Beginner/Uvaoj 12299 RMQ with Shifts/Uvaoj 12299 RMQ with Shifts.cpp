#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1<<30;
const int maxn = 100010;

//使用前需给A[]和n赋完值
int A[maxn];//起始数据,从0开始
int n;//起始数据个数
int minv[4*maxn];//minv[i]: i结点编号 从1开始

void init(int o, int L, int R)
{
	int M = L+(R-L)/2;
	if(L==R){
		minv[o] = A[L];
		return;
	}
	init(o*2,L,M);
	init(o*2+1,M+1,R);
	minv[o] = min(minv[o*2],minv[o*2+1]);
}

void init()
{
	init(1,0,n-1);
}

int query(int o, int L, int R, int ql, int qr)//查询[ql,qr]中的最小值
{
	//o: 当前结点编号。从1开始
	//L,R: 当前结点的左右端点。从0开始
	int M = L+(R-L)/2;
	int ans = INF;
	if(ql<=L && R<=qr)
		return minv[o];
	if(ql<=M)
		ans = min(ans,query(o*2,L,M,ql,qr));
	if(M<qr)
		ans = min(ans,query(o*2+1,M+1,R,ql,qr));
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
		minv[o] = v;//叶节点，直接更新minv
	else
	{
		if(p<=M)
			update(o*2,L,M,p,v);
		else
			update(o*2+1,M+1,R,p,v);
		minv[o] = min(minv[o*2],minv[o*2+1]);
	}
}

void update(int p, int v)//修改：A[p] = v
{
	update(1,0,n-1,p,v);
}

int digits(int want)
{
	if(want==0)
		return 1;
	int num = 0;
	while(want>0){
		want /= 10;
		++num;
	}
	return num;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	char op[30];
	init();
	for(int k=0;k<q;k++)
	{
		scanf("%s",op);
		if(op[0] == 'q')
		{
			int y1, y2;
			char* h = strchr(op,'(')+1;
			sscanf(h, "%d,%d", &y1, &y2);
			printf("%d\n",query(y1-1,y2-1));
		}
		else
		{
			int a[30];
			char* h = strchr(op,'(')+1;
			int num = 0;
			for(int i=0;i<strlen(h)-1;i++)
				if(!(h[i]>='0' && h[i]<='9')){
					h[i] = ' ';
					++num;
				}
			++num;
			//printf("%s\n",h);
			for(int i=0;i<num;++i)
			{
				sscanf(h,"%d",&a[i]);
				h += digits(a[i])+1;
				a[i]--;
			}
			// for(int i=0;i<num;i++)
			// 	printf("t:%d\n", a[i]);
			for(int i=0;i<num;i++){
				update(a[i],A[a[(i+1)%num]]);
			}
			int hold = A[a[0]];
			for(int i=0;i<num-1;i++)
				A[a[i]] = A[a[i+1]];
			A[a[num-1]] = hold;
			// for(int i=0;i<n;i++)
			// 	printf("%d ",A[i]);
			// printf("\n");
		}
	} 
	return 0;
}