#include <cstdio>
#include <cstring>
using namespace std;

const int maxnn = 100010;
const int maxn = 2*maxnn;

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

int main()
{
	//freopen("data.txt", "r", stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++)
	{
		BIT solve;
		//printf("kao");
		int n,m;
		int id[maxn];
		scanf("%d%d",&n,&m);
		int a[maxn];
		memset(a,0,sizeof(a));
		for(int i=maxnn;i<maxnn+n;i++){
			a[i] = 1;
			id[i-maxnn+1] = i+1;
		}
		solve.init(maxn-10,a);
		int pre = maxnn-1;
		for(int i=0;i<m;i++)
		{
			int h;
			scanf("%d",&h);
			if(i!=m-1)
				printf("%d ",solve.sum(id[h]-1));
			else
				printf("%d\n",solve.sum(id[h]-1));
			solve.add(id[h],-1);
			solve.add(pre,1);
			id[h] = pre--;
		}
	}
	return 0;
}
