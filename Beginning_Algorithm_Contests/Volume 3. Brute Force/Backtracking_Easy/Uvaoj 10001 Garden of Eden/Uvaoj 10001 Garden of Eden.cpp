/*
// TLE!

#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

const int maxstep = 1000000;

set<long long> s;

char f[50];

int n;
int iden;
long long final;

int at(long long k, int pos){
	pos = (pos + n) % n;
	int ans = 1 & (k>>pos);
	//printf("%d\n", ans);
	return ans;
}

int cal(int left, int cell, int right){
	int k = left*4+cell*2+right;
	return (iden>>k)&1;
}

long long big(int n){
	if(n < 31)
		return 1<<n;
	else
		return ((long long)1<<30) * (1<<(n-30));
}

long long evolve(long long k){
	int h[50];
	for(int i=0;i<n;i++)
		h[i] = cal(at(k, i+1), at(k, i), at(k, i-1));
	long long ans = 0;
	for(int i=n-1;i>=0;i--){
		ans = ans << 1;
		ans += h[i];
	}
	//printf("ans:%lld\n", ans);
	return ans;
}

bool solve(){
	long long b = big(n);
	for(long long i=0;i<b;i++){
		long long e = evolve(i);
	//	printf("%lld %lld\n", i, e);
		if(e == final)
			return true;
	}
	return false;
}

int main()
{
	//freopen("data.txt", "r", stdin);
	while(scanf("%d%d%s", &iden, &n, f) != EOF){
		s.clear();
		final = 0;
		for(int i=0;i<strlen(f);i++){
			final = final << 1;
			//final *= 2;
			//printf("%d\n", final);
			final += f[i]-'0';
		}
		//printf("%s\n",f);
	//	printf("%d\n", final);
		// for(int i=0;i<8;i++){
		// 	printf("%d\n", at(iden, i));
		// }
		// printf("%d\n", iden);
		// printf("%d\n", (iden>>6)&1);
		// printf("%d\n", at(iden, 6));
		bool ok = solve();
		if(!ok)
			printf("GARDEN OF EDEN\n");
		else
			printf("REACHABLE\n");
	}
	return 0;
}
*/

#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

char f[50];

int n;
int iden;
long long final;

int id[8];

void pre(){
	for(int i=0;i<8;i++)
		id[i] = (iden>>i)&1;
}

bool solve(vector<int> v, int level){
	// for(int i=0;i<v.size();i++)
	// 	printf("%d ", v[i]);
	// printf("\n");
	if(v.size() == n){
		int left = v[n-1];
		int cell = v[0];
		int right = v[1];
		if(f[0]-'0' != id[4*left+2*cell+right])
			return false;
		left = v[n-2];
		cell = v[n-1];
		right = v[0];
		if(f[n-1]-'0' != id[4*left+2*cell+right])
			return false;
		return true;
	}
	for(int i=0;i<8;i++)
		if(id[i] == f[level]-'0'){
			//printf("i: %d level:%d\n", i, level);
			if((i>>2) == v[v.size()-2] && ((i>>1)&1) == v[v.size()-1]){
				vector<int> h = v;
			//	printf("kao\n");
				h.push_back(i&1);
				bool ok = solve(h, level+1);
				if(ok)
					return true;
			}
		}
	//printf("\n");
	return false;
}

bool solve(){
	for(int i=0;i<8;i++)
		if(id[i] == f[1]-'0'){
			vector<int> v;
			v.push_back(i>>2);
			v.push_back((i>>1)&1);
			v.push_back(i&1);
			bool ok = solve(v,2);
			if(ok)
				return true;
		}
	return false;
}

int main()
{
	//freopen("data.txt", "r", stdin);
	while(scanf("%d%d%s", &iden, &n, f) != EOF){
		pre();
		bool ok = solve();
		if(!ok)
			printf("GARDEN OF EDEN\n");
		else
			printf("REACHABLE\n");
	}
	return 0;
}