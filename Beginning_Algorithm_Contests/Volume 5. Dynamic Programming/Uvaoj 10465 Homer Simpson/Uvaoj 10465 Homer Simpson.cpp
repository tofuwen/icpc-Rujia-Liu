#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	//freopen("data.txt", "r", stdin);
	int m,n,t;
	while(scanf("%d%d%d", &m, &n, &t) != EOF){
		int M = max(m,n);
		m = min(m,n);
		int ans = 1<<30;
		int nans = 0;
		int num = t / M;
		for(int i=num;i>=0;i--){
			int r = t - i * M;
			int all = i + r / m;
			int remain = r % m;
			if(remain <= ans){
				ans = remain;
				nans = max(nans, all);
			}
		}
		if(ans == 0)
			printf("%d\n", nans);
		else
			printf("%d %d\n", nans, ans);
		// int num = t / m;
		// int r = t % m;
		// int rr = M % m;
		// int k = M / m;
		// int nnum = 0;
		// while(r >= rr && num >= k){
		// 	r -= rr;
		// 	num -= k;
		// 	++nnum;
		// }
		// if(r == 0)
		// 	printf("%d\n", num + nnum);
		// else
		// 	printf("%d %d\n", num+nnum, r);
	}
	return 0;
}