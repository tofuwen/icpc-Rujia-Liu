#include <cstdio>
using namespace std;

const int maxn = 210;
const int mod = 1000000;

int C[maxn][maxn];

void pre() {
	for(int i=1;i<maxn;i++) {
		C[i][0] = C[i][i] = 1;
		for(int j=1;j<i;j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int N, K;
	pre();
	while(scanf("%d%d", &N, &K) && N) {
		printf("%d\n", C[N+K-1][K-1]);
	} 
	return 0;
}