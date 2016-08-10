#include <cstdio>
using namespace std;

const int INF = 1<<30;
const int maxn = 500010;

long long max(long long a, long long b, long long c, int& x)
{
	if(a>=b && a>=c)
    {
        x = 1;
        return a;
    }
    if(b>=a && b>=c)
    {
        x = 2;
        return b;
    }
    x = 3;
    return c;
}

long long max(long long a, long long b, int& x)
{
    if(a>=b){
        x = 1;
        return a;
    }
    x = 2;
    return b;
}

//struct segmentTree
//{
	//使用前需给A[]和n赋完值
	int A[maxn];//起始数据,从0开始
	long long sum[maxn];
	int n;//起始数据个数
	long long max_sub[4*maxn];
	long long max_prefix[4*maxn];
	long long max_suffix[4*maxn];
	int st[4*maxn];
	int finish[4*maxn];
	int stSuf[maxn];
	int finishPre[maxn];

	long long summation(int L, int R)
	{
		long long h = 0;
		if(L>0)
			h = sum[L-1];
		return sum[R]-h;
	}

	void init(int o, int L, int R)
	{
		int M = L+(R-L)/2;
		if(L==R){
			max_sub[o] = A[L];
			st[o] = finish[o] = L;
			max_prefix[o] = A[L];
			finishPre[o] = L;
			max_suffix[o] = A[L];
			stSuf[o] = L;
			return;
		}
		init(o*2,L,M);
		init(o*2+1,M+1,R);
		int x;
		max_sub[o] = max(max_sub[o*2],max_prefix[o*2+1]+max_suffix[o*2],max_sub[o*2+1],x);
		if(x==1)
        {
            st[o] = st[o*2];
            finish[o] = finish[o*2];
        }
        else if(x==2)
        {
            st[o] = stSuf[o*2];
            finish[o] = finishPre[o*2+1];
        }
        else{
            st[o] = st[o*2+1];
            finish[o] = finish[o*2+1];
        }
		max_prefix[o] = max(max_prefix[o*2],summation(L,M)+max_prefix[o*2+1],x);
		if(x==1)
            finishPre[o] = finishPre[o*2];
		else
            finishPre[o] = finishPre[o*2+1];
		max_suffix[o] = max(summation(M+1,R)+max_suffix[o*2],max_suffix[o*2+1],x);
		if(x==1)
            stSuf[o] = stSuf[o*2];
		else
            stSuf[o] = stSuf[o*2+1];
	}

	void init()
	{
		init(1,0,n-1);
	}

	long long query_prefix(int o, int L, int R, int ql, int qr, int& finishPrefix)//查询[ql,qr]中的最小值
	{
		int M = L+(R-L)/2;
		if(ql==L && R==qr){
            finishPrefix = finishPre[o];
			return max_prefix[o];
		}
		if(ql>M){
			return query_prefix(o*2+1,M+1,R,ql,qr,finishPrefix);
		}
		if(qr<=M)
			return query_prefix(o*2,L,M,ql,qr,finishPrefix);
        int x,x1,x2;
		long long ans = max(query_prefix(o*2,L,M,ql,M,x1),query_prefix(o*2+1,M+1,R,M+1,qr,x2)+summation(ql,M),x);
		if(x==1)
            finishPrefix = x1;
        else
            finishPrefix = x2;
		return ans;
	}

	long long query_suffix(int o, int L, int R, int ql, int qr, int& startSuffix)//查询[ql,qr]中的最小值
	{
		int M = L+(R-L)/2;
		if(ql==L && R==qr){
            startSuffix = stSuf[o];
			return max_suffix[o];
		}
		if(ql>M)
			return query_suffix(o*2+1,M+1,R,ql,qr,startSuffix);
		if(qr<=M)
			return query_suffix(o*2,L,M,ql,qr,startSuffix);
        int x,x1,x2;
		long long ans = max(query_suffix(o*2,L,M,ql,M,x1)+summation(M+1,R),query_suffix(o*2+1,M+1,R,M+1,qr,x2),x);
		if(x==1)
            startSuffix = x1;
        else
            startSuffix = x2;
        return ans;
	}

	long long query(int o, int L, int R, int ql, int qr, int& startIndex, int& finishIndex)
	{
		//o: 当前结点编号。从1开始
		//L,R: 当前结点的左右端点。从0开始
		int M = L+(R-L)/2;
		if(ql==L && R==qr){
            startIndex = st[o];
            finishIndex = finish[o];
			return max_sub[o];
		}
		if(ql>M)
			return query(o*2+1,M+1,R,ql,qr,startIndex,finishIndex);
		if(qr<=M)
			return query(o*2,L,M,ql,qr,startIndex,finishIndex);
        int x,s1,s2,f1,f2,x1,x2;
		long long ans =  max(query(o*2,L,M,ql,M,s1,f1),query_prefix(o*2+1,M+1,R,M+1,qr,x1)+query_suffix(o*2,L,M,ql,M,x2),query(o*2+1,M+1,R,M+1,qr,s2,f2),x);
		if(x==1){
            startIndex = s1;
            finishIndex = f1;
		}
		else if(x==2){
            startIndex = x2;
            finishIndex = x1;
		}
		else{
            startIndex = s2;
            finishIndex = f2;
		}
		return ans;
	}



	long long query(int ql, int qr, int& s, int& f)//查询[ql,qr]中的最小值
	{
		return query(1,0,n-1,ql,qr,s,f);
	}
//};

int main()
{
	//freopen("data.txt","r",stdin);
	int m;
	int kase = 0;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		printf("Case %d:\n",++kase);
		//segmentTree solve;
		//solve.n = n;
		long long h = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&A[i]);
			sum[i] = h + A[i];
			h = sum[i];
		}
		init();
		for(int i=0;i<m;i++)
		{
			int h1, h2;
			scanf("%d%d",&h1,&h2);
			int ans1,ans2;
			query(h1-1,h2-1,ans1,ans2);
			printf("%d %d\n",ans1+1,ans2+1);
		}
	}
	return 0;
}
