//自己死都弄不出来，放弃了···
//想了N多方法，两天时间，实在不会了···
//至少我知道自己错在哪里了：我的思路是set碰到add把add往下挤，反之亦然。
//问题就在于你针对下面的线段修改的时候，必须要把上面对应的线段也修改了。
//以前只有add，set的时候递归自动就实现了。现在不行了···

/*
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const long long INF = ((long long)(1<<30))*((long long)(1<<30));
const int maxn = 1000010;

//支持三种操作：
//Add（L,R,v）：把AL,...,AR的值全部增加v
//Set（L,R,v）：把AL,...,AR的值全部修改为v，且set的值必须为非负值
//Query（L,R）：计算子序列AL,...,AR的元素和、最小值、最大值
//使用前需给A[]和n赋完值
int A[maxn];//起始数据,从0开始
int n;//起始数据个数
long long minv[4*maxn];//minv[i]: i结点编号 从1开始
long long maxv[4*maxn];
long long sumv[4*maxn];
long long addv[4*maxn];
long long setv[4*maxn];//-1 代表没有被修改
int y1, y2;//查询、修改范围均为[y1,y2]
int v;//需增加 or 修改的值
long long _min, _max;//全局变量，当前最小、最大值
long long _sum;//全局变量，当前累加和

void init(int o, int L, int R)
{
	int M = L+(R-L)/2;
	if(L==R){
		minv[o] = maxv[o] = addv[o] = sumv[o] =  A[L];
		setv[o] = -1;
		return;
	}
	init(o*2,L,M);
	init(o*2+1,M+1,R);
	minv[o] = min(minv[o*2],minv[o*2+1]);
	maxv[o] = max(maxv[o*2],maxv[o*2+1]);
	addv[o] = 0;
	setv[o] = -1;
	sumv[o] = sumv[o*2]+sumv[o*2+1];
}

void init()
{
	init(1,0,n-1);
}

void maintainAdd(int o, int L, int R)//维护结点o，对应区间[L,R]
{
	int lc = o*2, rc = o*2+1;
	sumv[o] = minv[o] = maxv[o] = 0;
	if(R>L){
		sumv[o] = sumv[lc] + sumv[rc];
		minv[o] = min(minv[lc],minv[rc]);
		maxv[o] = max(maxv[lc],maxv[rc]);
	}
	minv[o] += addv[o];
	maxv[o] += addv[o];
	sumv[o] += addv[o]*(R-L+1);
}

void maintainSet(int o, int L, int R)//维护结点o，对应区间[L,R]
{
	int lc = o*2, rc = o*2+1;
	if(setv[o]>=0)
	{
		minv[o] = maxv[o] = setv[o];
		sumv[o] = (R-L+1)*setv[o];
		if(L==R)
			addv[o] = setv[o];
		else
			addv[o] = 0;
		return;
	}
	if(R>L){
		sumv[o] = sumv[lc] + sumv[rc];
		minv[o] = min(minv[lc],minv[rc]);
		maxv[o] = max(maxv[lc],maxv[rc]);
	}
}

void query(int o, int L, int R, long long add)//查询[y1,y2]中的最小值、最大值、累加和，结果存在全局变量中
{
	//o: 当前结点编号。从1开始
	//L,R: 当前结点的左右端点。从0开始
	//add: 当前区间的所有祖先结点add值之和
	if(setv[o]>=0){//递归边界1：有set标记
		_sum += (add+setv[o])*(min(R,y2)-max(L,y1)+1);
		_min = min(_min,setv[o]+add);
		_max = max(_max,setv[o]+add);
		return;
	}
	if(y1<=L && y2>=R){
		_sum += sumv[o] + add*(R-L+1);
		_min = min(_min,minv[o]+add);
		_max = max(_max,maxv[o]+add);
	}
	else{
		int M = L+(R-L)/2;
		if(y1<=M)
			query(o*2,L,M,add+addv[o]);
		if(y2>M)
			query(o*2+1,M+1,R,add+addv[o]);
	}
}

void query()//查询[y1,y2]中的最小值、最大值、累加和，结果存在全局变量中
{
	_sum = 0;
	_max = -INF;
	_min = INF;
	query(1,0,n-1,0);
}

void pushdown(int o, int L, int R)//标记传递
{
	int lc = o*2, rc = o*2+1;
	int M = L+(R-L)/2;
	if(setv[o]>=0){
		setv[lc] = setv[rc] = setv[o];
		setv[o] = -1;
		if(L==M)
			addv[lc] = setv[lc];
		else
			addv[lc] = 0;
		if(M+1==R)
			addv[rc] = setv[rc];
		else
			addv[rc] = 0;
	}
}

void pushdownAdd(int o, int L, int R)
{
   if(addv[o]!=0)
   {
       int lc = o*2, rc = o*2+1;
       int M = L+(R-L)/2;
       if(setv[lc]>=0 && L<M){
           pushdown(lc,L,M);
           maintainSet(lc, L, M);
       }
       addv[lc] += addv[o];
       maintainAdd(lc,L,M);
       if(setv[rc]>=0 && M+1<R){
           pushdown(rc,M+1,R);
           maintainSet(rc, M+1, R);
       }
       addv[rc] += addv[o];
       maintainAdd(rc,M+1,R);
       addv[o] = 0;
   }
}

void updateAdd(int o, int L, int R)//把Ay1...Ay2的值全部增加v，但是其实并没有改变A数组的值
{
    int lc = o*2, rc = o*2+1;
    int M = L+(R-L)/2;
	if(setv[o]>=0){
		pushdown(o,L,R);
		maintainSet(lc,L,M);
		maintainSet(rc,M+1,R);
	}
	if(y1<=L && y2>=R)
		addv[o] += v;
	else
	{
		if(y1<=M)
			updateAdd(lc,L,M);
		if(y2>M)
			updateAdd(rc,M+1,R);
	}
	maintainAdd(o,L,R);
}

void updateAdd()//把Ay1...Ay2的值全部增加v，但是其实并没有改变A数组的值
{
	updateAdd(1,0,n-1);
}

void updateSet(int o, int L, int R)//把Ay1...Ay2的值全部修改为v，但是并没有改变A数组的值
{
    if(addv[o]!=0)
    {
       pushdownAdd(o,L,R);
    }
	int lc = o*2, rc = o*2+1;
	if(y1<=L && y2>=R){
		setv[o] = v;
		if(L==R)
			addv[o] = setv[o];
		else
			addv[o] = 0;
	}
	else
	{
		pushdown(o,L,R);
		int M = L+(R-L)/2;
		if(y1<=M)
			updateSet(lc,L,M);
		else
			maintainSet(lc,L,M);
		if(y2>M)
			updateSet(rc,M+1,R);
		else
			maintainSet(rc,M+1,R);
	}
	maintainSet(o,L,R);
}

void updateSet()//把Ay1...Ay2的值全部增加v，但是其实并没有改变A数组的值
{
	updateSet(1,0,n-1);
}

int main()
{
	freopen("data.txt", "r", stdin);
	int r,c,m;
	while(scanf("%d%d%d",&r,&c,&m)!=EOF)
	{
		n = r*c;
		//init();
		memset(addv,0,sizeof(addv));
		memset(minv,0,sizeof(minv));
		memset(maxv,0,sizeof(maxv));
		memset(sumv,0,sizeof(sumv));
		memset(setv,-1,sizeof(setv));
		for(int q=0;q<m;q++)
		{
			int option;
			int x1,x2,z1,z2;
			scanf("%d",&option);
			if(option==1){
				scanf("%d%d%d%d%d",&x1,&z1,&x2,&z2,&v);
				for(int i=x1-1;i<=x2-1;i++){
					y1 = i*c+z1-1;
					y2 = i*c+z2-1;
					updateAdd();
				}
			}
			if(option==2){
				scanf("%d%d%d%d%d",&x1,&z1,&x2,&z2,&v);
				for(int i=x1-1;i<=x2-1;i++){
					y1 = i*c+z1-1;
					y2 = i*c+z2-1;
					updateSet();
				}
			}
			if(option==3){
				scanf("%d%d%d%d",&x1,&z1,&x2,&z2);
				long long __min = INF, __max = -INF, __sum = 0;
				for(int i=x1-1;i<=x2-1;i++){
					y1 = i*c+z1-1;
					y2 = i*c+z2-1;
					query();
					__min = min(__min,_min);
					__max = max(__max,_max);
					__sum += _sum;
				}
				printf("%lld %lld %lld\n",__sum,__min,__max);
			}
		}
	}
	return 0;
}
*/


#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const long long INF = ((long long)(1<<30))*((long long)(1<<30));
const int maxn = 1000010;

//支持三种操作：
//Add（L,R,v）：把AL,...,AR的值全部增加v
//Set（L,R,v）：把AL,...,AR的值全部修改为v，且set的值必须为非负值
//Query（L,R）：计算子序列AL,...,AR的元素和、最小值、最大值
//使用前需给A[]和n赋完值
int A[maxn];//起始数据,从0开始
int n;//起始数据个数
long long minv[4*maxn];//minv[i]: i结点编号 从1开始
long long maxv[4*maxn];
long long sumv[4*maxn];
long long addv[4*maxn];
long long setv[4*maxn];//-1 代表没有被修改
int y1, y2;//查询、修改范围均为[y1,y2]
int v;//需增加 or 修改的值
int op;//操作选择 1：Add 2：Set 3：Query
long long _min, _max;//全局变量，当前最小、最大值
long long _sum;//全局变量，当前累加和

void init(int o, int L, int R)
{
	int M = L+(R-L)/2;
	if(L==R){
		minv[o] = maxv[o] = sumv[o] =  A[L];
		setv[o] = A[L];// 见maintain注释
		addv[o] = 0;
		return;
	}
	init(o*2,L,M);
	init(o*2+1,M+1,R);
	minv[o] = min(minv[o*2],minv[o*2+1]);
	maxv[o] = max(maxv[o*2],maxv[o*2+1]);
	addv[o] = 0;
	setv[o] = -1;
	sumv[o] = sumv[o*2]+sumv[o*2+1];
}

void init()
{
	init(1,0,n-1);
}

// 注意：所有叶子上总是保留set标记而不会被清除（pushdown只能针对非叶结点），因此maintain函数对于叶子来说并不会重复累加addv[o]
// 因为一开始给根节点设置setv[1] = 0，保证了每个叶子上必有一个setv的值
void maintain(int o, int L, int R)//维护结点o，对应区间[L,R]
{
	int lc = o*2, rc = o*2+1;
	if(R>L){
		sumv[o] = sumv[lc] + sumv[rc];
		minv[o] = min(minv[lc],minv[rc]);
		maxv[o] = max(maxv[lc],maxv[rc]);
	}
	if(setv[o]>=0){
		minv[o] = maxv[o] = setv[o];
		sumv[o] = (R-L+1)*setv[o];
	}
	if(addv[o]){
		minv[o] += addv[o];
		maxv[o] += addv[o];
		sumv[o] += addv[o]*(R-L+1);
	}
}

void query(int o, int L, int R, long long add)//查询[y1,y2]中的最小值、最大值、累加和，结果存在全局变量中
{
	//o: 当前结点编号。从1开始
	//L,R: 当前结点的左右端点。从0开始
	//add: 当前区间的所有祖先结点add值之和
	if(setv[o]>=0){//递归边界1：有set标记
		long long hold = add + setv[o] + addv[o];
		_sum += hold*(min(R,y2)-max(L,y1)+1);
		_min = min(_min,hold);
		_max = max(_max,hold);
		return;
	}
	if(y1<=L && y2>=R){
		_sum += sumv[o] + add*(R-L+1);
		_min = min(_min,minv[o]+add);
		_max = max(_max,maxv[o]+add);
	}
	else{
		int M = L+(R-L)/2;
		if(y1<=M)
			query(o*2,L,M,add+addv[o]);
		if(y2>M)
			query(o*2+1,M+1,R,add+addv[o]);
	}
}

void query()//查询[y1,y2]中的最小值、最大值、累加和，结果存在全局变量中
{
	_sum = 0;
	_max = -INF;
	_min = INF;
	query(1,0,n-1,0);
}

void pushdown(int o)//标记传递
{
	int lc = o*2, rc = o*2+1;
	if(setv[o]>=0){
		setv[lc] = setv[rc] = setv[o];
		addv[lc] = addv[rc] = 0;
		setv[o] = -1;
	}
	if(addv[o]){
		addv[lc] += addv[o];
		addv[rc] += addv[o];
		addv[o] = 0;
	}
}

void update(int o, int L, int R)//把Ay1...Ay2的值全部增加或修改为v，但是其实并没有改变A数组的值
{
    int lc = o*2, rc = o*2+1;
    int M = L+(R-L)/2;
	if(y1<=L && y2>=R){
		if(op==1)
			addv[o] += v;
		else{// op==2
			setv[o] = v;
			addv[o] = 0;
		}
	}
	else{
		pushdown(o);
		if(y1<=M)
			update(lc, L, M);
		else
			maintain(lc, L, M);
      	if(y2>M)
      		update(rc, M+1, R);
      	else
      		maintain(rc, M+1, R);
	}
	maintain(o,L,R);
}

void update()//把Ay1...Ay2的值全部增加或修改为v，但是其实并没有改变A数组的值
{
	update(1,0,n-1);
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int r,c,m;
	while(scanf("%d%d%d",&r,&c,&m)!=EOF)
	{
		n = r*c;
		memset(A,0,sizeof(A));
		init();
		// memset(addv,0,sizeof(addv));
		// memset(minv,0,sizeof(minv));
		// memset(maxv,0,sizeof(maxv));
		// memset(sumv,0,sizeof(sumv));
		// memset(setv,-1,sizeof(setv));
		// setv[1] = 0;
		for(int q=0;q<m;q++)
		{
			int x1,x2,z1,z2;
			scanf("%d",&op);
			if(op!=3){
				scanf("%d%d%d%d%d",&x1,&z1,&x2,&z2,&v);
				for(int i=x1-1;i<=x2-1;i++){
					y1 = i*c+z1-1;
					y2 = i*c+z2-1;
					update();
				}
			}
			else{
				scanf("%d%d%d%d",&x1,&z1,&x2,&z2);
				long long __min = INF, __max = -INF, __sum = 0;
				for(int i=x1-1;i<=x2-1;i++){
					y1 = i*c+z1-1;
					y2 = i*c+z2-1;
					query();
					__min = min(__min,_min);
					__max = max(__max,_max);
					__sum += _sum;
				}
				printf("%lld %lld %lld\n",__sum,__min,__max);
			}
		}
	}
	return 0;
}