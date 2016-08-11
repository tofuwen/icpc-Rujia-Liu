#include <cstdio>
#include <vector>
using namespace std;

struct Tuple {
	int a, b, c;
	Tuple(int a, int b, int c):a(a), b(b), c(c){}
};

double cal(const vector<Tuple> & v, double x) {
	double ans = -1e100;
	for(int i=0;i<v.size();i++) {
		ans = max(ans, v[i].a*x*x+v[i].b*x+v[i].c);
	}
	return ans;
}

double solve(const vector<Tuple> & v) {
	double left = 0, right = 1000;
	int times = 100;
	while (times--) {
		double step = (right - left) / 3;
		double l = left + step;
		double r = right - step;
		double lv = cal(v, l);
		double rv = cal(v, r);
		if (lv > rv) 
			left = l;
		else
			right = r;
	}
	return cal(v, right);
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int cc=0; cc<T; cc++) {
		int n;
		scanf("%d", &n);
		vector<Tuple> v;
		for (int i=0;i<n;i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			v.push_back(Tuple(a, b, c));
		}
		printf("%.4f\n", solve(v));
	}
	return 0;
}