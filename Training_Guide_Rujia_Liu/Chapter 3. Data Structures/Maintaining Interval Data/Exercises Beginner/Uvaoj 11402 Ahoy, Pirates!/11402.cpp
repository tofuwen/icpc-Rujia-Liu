#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const long long INF = 1LL << 60;
const int maxn = 1024010;

//支持两种操作：
//Set（L,R,v）：把AL,...,AR的值全部修改为v
//Query（L,R）：计算子序列AL,...,AR的元素和、最小值、最大值
//使用前需给A[]和n赋完值
int A[maxn];//起始数据,从0开始
int n;//起始数据个数
long long setv[4*maxn];//-1 代表没有被修改
long long num[4*maxn][2];
int y1, y2;//查询、修改范围均为[y1,y2]
int v;//需修改的值
long long _ans;

void init(int o, int L, int R){
	int M = L+(R-L)/2;
	if(L==R){
		num[o][A[L]] = 1;
		num[o][A[L]^1] = 0;
		setv[o] = A[L];
		return;
	}
	init(o*2,L,M);
	init(o*2+1,M+1,R);
	num[o][0] = num[2*o][0] + num[2*o+1][0];
	num[o][1] = num[2*o][1] + num[2*o+1][1];
	setv[o] = -1;
}

void init(){
	init(1,0,n-1);
}

void maintain(int o, int L, int R){ //维护结点o，对应区间[L,R]
	if(setv[o]==0 || setv[o] == 1){
		num[o][setv[o]] = R-L+1;
		num[o][setv[o]^1] = 0;
		return;
	}
	if(R>L){
		num[o][0] = num[2*o][0] + num[2*o+1][0];
		num[o][1] = num[2*o][1] + num[2*o+1][1];
		if(setv[o] == 2)
			swap(num[o][0], num[o][1]);
	}
}

void query(int o, int L, int R, int want){ //查询[y1,y2]中的最小值、最大值、累加和，结果存在全局变量中
	//o: 当前结点编号。从1开始
	//L,R: 当前结点的左右端点。从0开始
	if(setv[o] == 0 || setv[o] == 1){ //递归边界1：有set标记
		if(setv[o] == want)
			_ans += min(R,y2)-max(L,y1)+1;
	}else if(y1<=L && y2>=R){ //递归边界2： 边界区间
		_ans += num[o][want];
	}
	else{
		int M = L+(R-L)/2;
		if(y1<=M)
			query(o*2,L,M, setv[o]==2?want^1:want);
		if(y2>M)
			query(o*2+1,M+1,R,setv[o]==2?want^1:want);
	}
}

void query(){ //查询[y1,y2]中的最小值、最大值、累加和，结果存在全局变量中
	_ans = 0;
	query(1,0,n-1, 1);
}

void pushdown(int o){ //标记传递
	int lc = o*2, rc = o*2+1;
	if(setv[o]>=0){
		if(setv[o] != 2)
			setv[lc] = setv[rc] = setv[o];
		else {
			setv[lc] = 1 - setv[lc];
			setv[rc] = 1 - setv[rc];
		}
		setv[o] = -1;
	}
}

void update(int o, int L, int R){ //把Ay1...Ay2的值全部修改为v，但是并没有改变A数组的值
	int lc = o*2, rc = o*2+1;
	if(y1<=L && y2>=R) {
		if(v == 0 || v == 1)
			setv[o] = v;
		else
			setv[o] = 1 - setv[o];
	}
	else{
		pushdown(o);
		int M = L+(R-L)/2;
		if(y1<=M)
			update(lc,L,M);
		else
			maintain(lc,L,M);
		if(y2>M)
			update(rc,M+1,R);
		else
			maintain(rc,M+1,R);
	}
	maintain(o,L,R);
}

void update(){ //把Ay1...Ay2的值全部修改为v，但是其实并没有改变A数组的值
	update(1,0,n-1);
}

void print(int q) {
	printf("Q%d: %d\n", q, _ans);
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=1;cc<=T;cc++) {
		printf("Case %d:\n", cc);
		int N;
		scanf("%d", &N);
		int cur_num = 0;
		for(int i=0;i<N;i++) {
			int num;
			char s[maxn];
			scanf("%d%s", &num, s);
			int l = strlen(s);
			for(int j=0;j<num;j++)
				for(int k=0;k<l;k++)
					A[cur_num++] = s[k] - '0';
		}
		n = cur_num;
		init();
		int num_q;
		scanf("%d", &num_q);
		int cur_q = 0;
		for(int i=0;i<num_q;i++) {
			char s[10];
			scanf("%s %d %d", s, &y1, &y2);
			switch(s[0]) {
				case 'F': v = 1; update(); break;
				case 'E': v = 0; update(); break;
				case 'I': v = 2; update(); break;
				default: query(); print(++cur_q); break;
			}
		}
	}
	return 0;
}