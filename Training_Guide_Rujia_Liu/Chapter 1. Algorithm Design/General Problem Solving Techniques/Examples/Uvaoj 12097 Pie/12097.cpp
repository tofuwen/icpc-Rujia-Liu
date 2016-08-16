#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const double PI = acos(-1);
const double eps = 1e-5;

bool okay(const vector<int> & v, double each, int F) {
	int ans = 0;
	for(int i=0;i<v.size();i++) {
		double area = v[i] * v[i] * PI;
		ans += (int)(floor(area / each) + 0.5);
	}
	return ans >= F;
}

double solve(const vector<int> & v, int F) {
	double low = 0;
	double high = v[0] * v[0] * PI;
	while(high - low >= eps) {
		double mid = (high+low)/2;
		if(okay(v, mid, F+1))
			low = mid;
		else
			high = mid;
	}
	return low;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		int N, F;
		scanf("%d%d", &N, &F);
		vector<int> v;
		v.reserve(N);
		for(int i=0;i<N;i++) {
			int a;
			scanf("%d", &a);
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		printf("%.5f\n", solve(v, F));
	}
	return 0;
}