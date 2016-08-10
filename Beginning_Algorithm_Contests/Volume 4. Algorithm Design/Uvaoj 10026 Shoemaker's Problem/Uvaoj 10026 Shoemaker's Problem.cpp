#include <cstdio>
using namespace std;

const int maxn = 1010;

int t[maxn];
int fine[maxn];
int ans[maxn];

bool okay(int i, int j){
	if(t[ans[i]]*fine[ans[j]] > t[ans[j]]*fine[ans[i]])
		return true;
	return false;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++){
		if(cc)
			printf("\n");
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&t[i],&fine[i]);
		for(int i=0;i<n;i++)
			ans[i] = i;
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i-1;j++)
				if(okay(j,j+1)){
					ans[j] ^= ans[j+1];
					ans[j+1] ^= ans[j];
					ans[j] ^= ans[j+1];
				}
		}
		for(int i=0;i<n;i++)
			if(i!=n-1)
				printf("%d ",ans[i]+1);
			else
				printf("%d\n",ans[i]+1);
	}
	return 0;
}