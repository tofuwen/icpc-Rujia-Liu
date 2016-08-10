#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

typedef long long LL;

const LL mod = 100000007;

struct point {
	int x, y;
	point(int x, int y):x(x), y(y){}
};

int N, K, B, R;


// ax+by = gcd(a, b), minimize abs(x)+abs(y) x, y may be negative
void gcd(LL a, LL b, LL & d, LL & x, LL & y) {
	if(!b) { d = a; x = 1; y = 0; }
	else { 
		gcd(b, a%b, d, y, x); 
		y -= x*(a/b); 
	}
}

// calculate inv(a) mod n. If not exist, return -1
LL inv(LL a, LL n) {
	LL d, x, y;
	gcd(a, n, d, x, y);
	return d == 1 ? (x+n)%n : -1;
}

// return ab mod n. 0<=a,b<n
LL mul_mod(LL a, LL b, int n) {
	return a * b % n;
}

// return a^p mod n, 0<=a<n
LL pow_mod(LL a, LL p, LL n) {
	if(p == 0)
		return 1;
	LL ans = pow_mod(a, p/2, n);
	ans = ans * ans % n;
	if(p % 2 == 1)
		ans = ans * a % n;
	return ans;
}

// solve a^x=b mod n. n prime. If no solution, return -1
int log_mod(int a, int b, int n) {
	int m, v, e = 1;
	m = (int)sqrt(n+0.5);
	v = inv(pow_mod(a, m, n), n);
	map<int, int> x;
	x[1] = 0;
	for(int i=1;i<m;i++) {
		e = mul_mod(e, a, n);
		if(!x.count(e))
			x[e] = i;
	}
	for(int i=0;i<m;i++) {
		if(x.count(b))
			return i*m + x[b];
		b = mul_mod(b, v, n);
	}
	return -1;
}

bool is_exist(int x, int y, const vector<point> & ps) {
	int n = ps.size();
	for(int i=0;i<n;i++)
		if(ps[i].x == x && ps[i].y == y)
			return true;
	return false;
}

bool is_k(const vector<point> & ps, point p) {
	if(p.x == 1)
		return true;
	if(is_exist(p.x-1, p.y, ps))
		return true;
	return false;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=1;cc<=T;cc++) {
		scanf("%d%d%d%d", &N, &K, &B, &R);
		vector<point> ps;
		int last_row = 0;
		int last_row_num = 0;
		for(int i=0;i<B;i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			ps.push_back(point(x, y));
			last_row = max(last_row, x);
		}
		for(int i=0;i<B;i++)
			if(ps[i].x == last_row)
				last_row_num++;
		LL cur = 1;
		if(last_row)
			cur = mul_mod(pow_mod(K, N, mod), pow_mod(K-1, ((long long)N)*(last_row-1), mod), mod);
		LL k_1_inv = inv(K-1, mod);
		LL k_inv = inv(K, mod);
		for(int i=0;i<B;i++) {
			if(is_k(ps, ps[i])) {
				if(ps[i].x == last_row)
					cur = mul_mod(cur, k_inv, mod);
				else
					cur = mul_mod(cur, k_1_inv, mod);
			}
			else {
				if(ps[i].x == last_row) {
					cur = mul_mod(cur, k_1_inv, mod);
				}
				else {
					cur = mul_mod(cur, pow_mod(k_1_inv, 2, mod), mod);
					cur = mul_mod(cur, K, mod);
				}
			}
		}
		if(cur == R && last_row) {
			printf("Case %d: %d\n", cc, last_row);
			continue;
		}
		if(!B)
			last_row_num = N;
		cur = mul_mod(cur, pow_mod(K, last_row_num, mod), mod);
		cur = mul_mod(cur, pow_mod(K-1, N-last_row_num, mod), mod);
		if(cur == R) {
			printf("Case %d: %d\n", cc, last_row+1);
			continue;
		}
		int each = pow_mod(K-1, N, mod);
		int ans = log_mod(each, mul_mod(inv(cur, mod), R, mod), mod);
		printf("Case %d: %d\n", cc, last_row+1+ans);
	}
	return 0;
}