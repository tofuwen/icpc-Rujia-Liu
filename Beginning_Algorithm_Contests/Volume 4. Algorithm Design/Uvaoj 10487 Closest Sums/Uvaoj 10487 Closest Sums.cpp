#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 1010;
const int I = 1<<30;
const long long INF = (long long)I*I*2;

int n;
long long data[maxn];

long long f(long long a, long long b, long long q){
	long long a1 = abs(q-a);
 	long long b1 = abs(q-b);
	if(a1 < b1)
		return a;
	return b;
}

bool isValid(int index){
	if(index>=0 && index < n)
		return true;
	return false;
}

void solve(long long q){
	long long closest = INF;
	for(int i=0;i<n-1;i++){
		long long want = q-data[i];
		long long* iter = lower_bound(data, data+n, want);
		int position = iter - data;
		if(position == n)
			closest = f(closest, data[i]+data[n-1], q);
		else{
			int preStep = position-1;
			int afterStep = position;
			if(preStep == i)
				preStep--;
			if(afterStep == i)
				afterStep++;
			if(isValid(preStep))
				closest = f(closest, data[i]+data[preStep], q);
			if(isValid(afterStep))
				closest = f(closest, data[i]+data[afterStep], q);
		}
	}
	printf("Closest sum to %lld is %lld.\n",q, closest);
}

int main()
{
	//freopen("data.txt","r",stdin);
	int kase = 0;
	while(scanf("%d",&n) && n){
		printf("Case %d:\n",++kase);
		for(int i=0;i<n;i++)
			scanf("%lld",&data[i]);
		sort(data,data+n);
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			long long q;
			scanf("%lld",&q);
			solve(q);
		}
	}
	return 0;
}