#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

void cal(int & a11, int & a12, int & a21, int & a22, int b, ll n) {
	if (n == 1) {
		a11 = a12 = a21 = 1;
		a22 = 0;
		return;
	}
	int b11, b12, b21, b22;
	cal(b11, b12, b21, b22, b, n/2);
	if (n % 2 == 0) {
		a11 = (b11 * b11 + b12 * b21) % b;
		a12 = (b11 * b12 + b12 * b22) % b;
		a21 = (b21 * b11 + b22 * b21) % b;
		a22 = (b21 * b12 + b22 * b22) % b;
		return;
	}
	int c11 = (b11 * b11 + b12 * b21) % b;
	int c12 = (b11 * b12 + b12 * b22) % b;
	int c21 = (b21 * b11 + b22 * b21) % b;
	int c22 = (b21 * b12 + b22 * b22) % b;
	a11 = (c11 + c12) % b;
	a12 = c11;
	a21 = (c21 + c22) % b;
	a22 = c21;
}

int g(ll n, int b) { // fib
	if (n == 0 || n == 1)
		return 1 % b;
	int a11, a12, a21, a22;
	cal(a11, a12, a21, a22, b, n-1);
	return (a11 + a12) % b;
	// return ((g(n-1, b)+g(n-2, b)) % b);
}

int solve(ll n, int b) {
	if (n == 0 || n == 1)
		return 1 % b;
	if (n == 2)
		return 3 % b;
	if (n == 3)
		return 5 % b;
	if (n == 4)
		return 9 % b;
	ll m = n - 2;
	// need to know S(n) for fibonacci
	// S(n) = A(n+2) - 1
	return (g(m,b)*solve(n-m,b)+g(m-1,b)*solve(n-m-1,b)+g(m+1,b)-1) % b;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	ll n;
	int b;
	int kase = 0;
	while (cin >> n >> b && b) {
		cout << "Case " << ++kase << ": " << n << " " << b << " " << solve(n, b) << endl;
	}
	return 0;
}