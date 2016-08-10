#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxNum = 70000;
const int maxn = 1000010;

int data[maxNum];
int k[maxn];

int main()
{
	//freopen("data.txt","r",stdin);
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(data,0,sizeof(data));
		for(int i=0;i<n;i++){
			scanf("%d",&k[i]);
			data[k[i]]++;
		}
		sort(k,k+n);
		if(n%2 == 1){
			int ans = n/2;
			printf("%d %d %d\n",k[ans],data[k[ans]],1);
		}
		else{
			int ans1 = n/2;
			int ans2 = ans1-1;
			int a;
			if(k[ans1] == k[ans2])
				a = data[k[ans1]];
			else
				a = data[k[ans1]]+data[k[ans2]];
			printf("%d %d %d\n",k[ans2],a, k[ans1]-k[ans2]+1);
		}
	}
	return 0;
}