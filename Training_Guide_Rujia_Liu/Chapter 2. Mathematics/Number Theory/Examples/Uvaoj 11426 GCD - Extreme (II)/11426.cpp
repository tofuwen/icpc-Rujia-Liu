#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int maxn = 4000010;
int phi[maxn+10];
LL f[maxn+10];
LL s[maxn+10];

void euler_phi_table(int n, int *phi){
	for(int i=2;i<=n;i++)
		phi[i] = 0;
	phi[1] = 1;
	for(int i=2;i<=n;i++)
		if(!phi[i])
			for(int j=i;j<=n;j+=i){
				if(!phi[j])
					phi[j] = j;
				phi[j] = phi[j]/i*(i-1);
			}
}

int main()
{
	// freopen("data.txt", "r", stdin);
	memset(f, 0, sizeof(f));
	euler_phi_table(maxn, phi);
	for(int i=1;i<maxn;i++) {
		for(int j=2*i;j<maxn;j+=i) {
			f[j] += i*phi[j/i];
		}
	}
	s[0] = 0;
	for(int i=1;i<maxn;i++)
		s[i] = s[i-1] + f[i];
	int n;
	while(scanf("%d", &n) && n) {
		printf("%lld\n", s[n]);
	}
	return 0;
}