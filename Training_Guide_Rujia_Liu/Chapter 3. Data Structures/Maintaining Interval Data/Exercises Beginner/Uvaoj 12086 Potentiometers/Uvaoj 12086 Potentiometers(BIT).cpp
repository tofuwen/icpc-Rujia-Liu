#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 200010;

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
	//freopen("data.txt","r",stdin);
	char c[10];
	int A[maxn];
	int kase = 0;
	int n;
	BIT solve;
	while(scanf("%d",&n)!=EOF && n){
		if(kase)
			printf("\n");
		printf("Case %d:\n",++kase);
		for(int i=0;i<n;i++)
			scanf("%d",&A[i]);
		solve.init(n,A);
		while(1){
			scanf("%s",c);
			if(c[0]=='E')
				break;
			if(c[0]=='M'){
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%d\n",solve.sum(y)-solve.sum(x-1));
			}
			else{
				int x, r;
				scanf("%d%d",&x,&r);
				solve.add(x, r-A[x-1]);
				A[x-1] = r;
			}
		}
	}
	return 0;
}