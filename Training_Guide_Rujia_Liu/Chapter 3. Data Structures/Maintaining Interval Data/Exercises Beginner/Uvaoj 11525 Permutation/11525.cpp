#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 50010;

struct BIT{ //Binary Indexed Tree(index start from 1)
	int n;//number of nodes in the BIT
	int C[maxn+1];

	int lowbit(int x){
		return x&-x;
	}

	int sum(int x){
		int ret = 0;
		while(x>0){
			ret += C[x];
			x -= lowbit(x);
		}
		return ret;
	}

	void add(int x, int d){
		while(x<=n){
			C[x] += d;
			x += lowbit(x);
		}
	}

	void init(int n){ //array a's index start from 0
		this->n = n;
		memset(C,0,sizeof(C));
		for(int i=0;i<n;i++)
			add(i+1,1);
	}
};

BIT b;
int n;
bool vis[maxn];

int solve(int data) {
	int m = 1;
	int M = n+1;
	while(1) {
		int mid = (m+M)/2;
		int cur = b.sum(mid);
		if(cur == data) {
			if(!vis[mid]) {
				b.add(mid, -1);
				vis[mid] = 1;
				return mid;
			}
			else {
				M = mid;
				continue;
			}
		}
		if(cur > data)
			M = mid;
		else
			m = mid;
	}
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++) {
		scanf("%d", &n);
		b.init(n);
		memset(vis, 0, sizeof(vis));
		for(int i=0;i<n;i++) {
			if(i)
				printf(" ");
			int data;
			scanf("%d", &data);
			printf("%d", solve(data+1));
		}
		printf("\n");
	}
	return 0;
}