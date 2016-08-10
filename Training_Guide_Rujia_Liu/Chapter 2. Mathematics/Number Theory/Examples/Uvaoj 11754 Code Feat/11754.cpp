#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

const long long threshold = 10000;
const int reserve_num = 100;
const int maxn = 110;

long long S;

vector<long long> g[maxn];

void print(const vector<long long> & v) {
	for(long long i=0;i<S;i++)
		printf("%lld\n", v[i]);
	printf("\n");
}

bool okay(long long x, const vector<long long> & mod) {
	long long n = mod.size();
	for(long long i=0;i<n;i++) {
		long long r = x % mod[i];
		auto iter = lower_bound(g[i].begin(), g[i].end(), r);
		if(iter == g[i].end() || *iter != r)
			return false;
	}
	return true;
}

void solve_by_search(const vector<long long> & mod) {
	double ratio = 1e10;
	long long want = 0;
	long long n = mod.size();
	for(long long i=0;i<n;i++) {
		double r = (double)g[i].size() / mod[i];
		if(ratio > r) {
			ratio = r;
			want = i;
		}
	}
	vector<long long> ans;
	long long cur = 0;
	long long total = g[want].size();
	while(ans.size() < S) {
		long long cur_round = cur / total;
		long long cur_index = cur % total;
		long long cur_num = cur_round * mod[want] + g[want][cur_index];
		if(okay(cur_num, mod) && cur_num)
			ans.push_back(cur_num);
		cur++;
	}
	print(ans);
}

void gcd(LL a, LL b, LL & d, LL & x, LL & y) {
	if(!b) { d = a; x = 1; y = 0; }
	else { 
		gcd(b, a%b, d, y, x); 
		y -= x*(a/b); 
	}
}

LL CRT(long long n, const vector<long long> & a, const vector<long long> & m) {
	LL M = 1, d, y, x = 0;
	for(long long i=0;i<n;i++)
		M *= m[i];
	for(long long i=0;i<n;i++) {
		LL w = M / m[i];
		gcd(m[i], w, d, d, y);
		x = (x + y*w*a[i]) % M;
	}
	return (x+M)%M;
}

void make_order(vector<long long> & ans, long long x, const vector<long long> & v) {
	long long n = v.size();
	for(long long i=0;i<n;i++) {
		ans.push_back(x / v[i]);
		x -= v[i] * ans.back();
	}
	reverse(ans.begin(), ans.end());
}

void solve_by_crt(const vector<long long> & mod) {
	long long n = mod.size();
	vector<long long> v;
	v.reserve(reserve_num);
	v.push_back(1);
	for(long long i=0;i<n-1;i++)
		v.push_back(g[i].size()*v.back());
	reverse(v.begin(), v.end());
	long long level = v[0] * g[n-1].size();
	vector<long long> ans;
	ans.reserve(reserve_num);
	long long product_mod = 1;
	for(long long i=0;i<n;i++)
		product_mod *= mod[i];
	for(long long i=0;i<level;i++) {
		vector<long long> a;
		a.reserve(reserve_num);
		make_order(a, i, v);
		vector<long long> m;
		for(long long i=0;i<n;i++)
			m.push_back(g[i][a[i]]);
		long long crt_ans = CRT(n, m, mod);
		if(crt_ans)
			ans.push_back(crt_ans);
		else
			ans.push_back(product_mod);
	}
	sort(ans.begin(), ans.end());
	long long cur = 0;
	while(ans.size() < S) {
		ans.push_back(ans[cur++]+product_mod);
	}
	print(ans);
}

int main()
{
	// freopen("data.txt", "r", stdin);
	long long C;
	while(scanf("%lld%lld", &C, &S) && C) {
		vector<long long> mod;
		mod.reserve(reserve_num);
		long long level = 1;
		for(long long i=0;i<C;i++) {
			long long X, k;
			scanf("%lld%lld", &X, &k);
			mod.push_back(X);
			level *= k;
			for(long long j=0;j<k;j++) {
				long long h;
				scanf("%lld", &h);
				g[i].push_back(h);
				if(j == k-1)
					sort(g[i].begin(), g[i].end());
			}
		}
		if(level >= threshold)
			solve_by_search(mod);
		else
			solve_by_crt(mod);
		for(int i=0;i<C;i++)
			g[i].clear();
	}
	return 0;
}