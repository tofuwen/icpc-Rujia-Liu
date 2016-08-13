#include <cstdio>
#include <cmath>
using namespace std;

int how_many(int m, int a, int b) {
	if(b == m)
		return m-1;
	if (b >= 0)
		return b + (m-b) / (a+1);
	return (m+a*b) / (a+1);

	// stupid but correct version
	// int l = 0, r = 0;  
 //    int tmp = a * b;  
 //    for (int i = 1; i < m; i++) {  
 //        if (tmp >= a) {  
 //            r++;  
 //            tmp -= a;  
 //        } else {  
 //            l++;  
 //            tmp++;  
 //        }  
 //    }
 //  	return r;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int m, p, a, b;
	while(scanf("%d%d%d%d", &m, &p, &a, &b) != EOF) {
		int num_positive = how_many(m, a, b);
		// printf("%d\n", num_positive);
		int num_negative = m - num_positive - 1;
		int r = a*b - num_positive*a + num_negative;
		double ans = (num_positive * pow(a, p) + num_negative + pow(r, p)) / pow(a, p/2);
		printf("%lld\n", (long long)(ans+0.5));
	}
	return 0;
}