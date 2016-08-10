#include <cstdio>
using namespace std;

const int maxn = 110;
const int eps = 1e-10;

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=1;cc<=T;cc++) {
		char s[100];
		int n;
		scanf("%s%d", s, &n);
		int a, b;
		sscanf(s, "%d/%d", &a, &b);
		double p = (double)a / b;
		double data[maxn][maxn];
		data[1][0] = 1 - p;
		data[1][1] = p;
		for(int i=2;i<maxn;i++) {
			for(int j=0;j<=i;j++) {
				if(j == 0) {
					data[i][j] = data[i-1][j] * (1-p);
				}
				else {
					double p0 = ((double)j-1)/(i-1);
					if(p0 > p)
						data[i][j] = 0;
					else {
						double p1 = ((double)j)/(i-1);
						if(p1 > p)
							data[i][j] = data[i-1][j-1] * p;
						else
							data[i][j] = data[i-1][j-1]*p + data[i-1][j] * (1-p);
					}
				}
			}
		}
		double ans = 0;
		for(int i=1;i<=n;i++) {
			int want = a*i/b + 1;
			ans += data[i][want];
		}
		ans = 1 / (1-ans);
		if(a == 0)
			ans = 1.1;
		printf("Case #%d: %d\n", cc, (int)ans);
	}
	return 0;
}