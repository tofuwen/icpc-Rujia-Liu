#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 15;
int n;
char s[maxn][maxn];

void fill(int i, int j) {
	int a[] = {1,-1,0,0};
	int b[] = {0,0,1,-1};
	if (s[i][j] == '.') {
		int alpha[100];
		memset(alpha, 0, sizeof(alpha));
		for(int k=0;k<4;k++) {
			int nextx = i+a[k];
			int nexty = j+b[k];
			if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n && s[nextx][nexty] != '.') {
				alpha[s[nextx][nexty]-'A'] = 1;
			}
			int p = 0;
			while(alpha[p])
				p++;
			s[i][j] = p+'A';
		}
	}
}

void solve() {
	for (int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			fill(i, j);
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int cc=1;cc<=T;cc++) {
		scanf("%d", &n);
		for (int i=0;i<n;i++) {
			scanf("%s", s[i]);
		}
		solve();
		printf("Case %d:\n", cc);
		for(int i=0;i<n;i++)
			printf("%s\n", s[i]);
	}
	return 0;
}