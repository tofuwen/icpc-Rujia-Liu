#include <cstdio>
#include <cmath>
using namespace std;

const long long mod = 1000;
const long long bigMod = 10000000000;

long long n, k;

long long solve1(long long n, long long k){
	n %= mod;
	if(k == 1)
		return n;
	if(k == 0)
		return 0;
	long long h = solve1(n, k/2)%mod;
	if(k%2 == 1)
		return (h*h*n)%mod;
	return (h*h)%mod;
}

/*
long long o(long long h){
	while(h>=bigMod)
		h /= 10;
	return h;
}

long long ans(long long h){
	while(h>=1000)
		h /= 10;
	return h;
}

long long f(long long n, long long k){
	n = o(n);
	if(k == 1)
		return n;
	if(k == 0)
		return 1;
	long long h = o(f(n, k/2));
	if(k%2 == 1)
		return o(o(h*h)*n);
	return o(h*h);
}
*/

long long solve2(long long n, long long k){
	double p = k*log10(n);
	double ans = p-floor(p);
	double num = pow(10, ans);
	while(num < 100)
		num *= 10;
	while(num > 1000)
		num /= 10;
	return (int)num;
}

int main()
{
	//freopen("data.txt","r",stdin);
	//freopen("dataout.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++){
		scanf("%lld%lld",&n,&k);
		printf("%03lld...%03lld\n", solve2(n,k), solve1(n,k));
	}
	return 0;
}