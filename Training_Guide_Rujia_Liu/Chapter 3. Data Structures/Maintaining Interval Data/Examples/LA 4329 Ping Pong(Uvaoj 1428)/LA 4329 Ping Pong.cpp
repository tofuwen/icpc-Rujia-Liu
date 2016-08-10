#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 20010;

//Binary Indexed Tree(index start from 1)
struct BIT
{
	int n;//number of nodes in the BIT
	int C[maxn+1];

	int lowbit(int x)
	{
		return x&-x;
	}

	int sum(int x)
	{
		int ret = 0;
		while(x>0){
			ret += C[x];
			x -= lowbit(x);
		}
		return ret;
	}

	void add(int x, int d)
	{
		while(x<=n){
			C[x] += d;
			x += lowbit(x);
		}
	}

	void init(int n, int *a)
	{
		//array a's index start from 0
		this->n = n;
		memset(C,0,sizeof(C));
		for(int i=0;i<n;i++)
			add(i+1,a[i]);
	}

	void init(int n)
	{
		this->n = n;
		memset(C,0,sizeof(C));
	}
};


struct player
{
	int id;
	int rank;
	friend bool operator < (const player& a, const player& b)
	{
		return a.rank<b.rank;
	}
};

player p[maxn];

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&p[i].rank);
			p[i].id = i;
		}
		sort(p+1,p+n+1);
		int num[maxn];
		BIT solve;
		solve.init(n);
		for(int i=1;i<=n;i++)
		{
			num[i] = solve.sum(p[i].id);
			solve.add(p[i].id,1);
		}
		long long ans = 0;
		for(int i=1;i<=n;i++)
			ans += ((long long)num[i]*(n-p[i].id-i+1+num[i])+(i-1-num[i])*(p[i].id-1-num[i]));
		printf("%lld\n",ans);
	}
	return 0;
}