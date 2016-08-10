#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct sprinkler{
	double left, right;
	sprinkler(double left, double right):left(left), right(right){}
	friend bool operator < (const sprinkler & a, const sprinkler & b){
		return a.left < b.left;
	}
};

int solve(const vector<sprinkler> & v, double l){
	double start = 0.0;
	int n = v.size();
	if(n == 0)
		return -1;
	int ans = 0;
	int cur = 0;

	while(cur < n){
		if(v[cur].left > start)
			return -1;
		double h = 0.0;
		while(cur < n && v[cur].left <= start){
			h = max(h, v[cur].right);
			++cur;
		}
		start = max(start, h);
		++ans;
		if(start >= l)
			return ans;
	}
	return -1;
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int n;
	double l, w;
	while(scanf("%d%lf%lf", &n, &l, &w) != EOF){
		double center, r;
		vector<sprinkler> v;
		for(int i=0;i<n;i++){
			scanf("%lf%lf", &center, &r);
			double hh = r*r-w*w/4;
			if(r < w/2)
				continue;
			double h = sqrt(hh);
			v.push_back(sprinkler(center-h, center+h));
		}
		sort(v.begin(), v.end());
		//v = f(v);
		// for(int i=0;i<v.size();i++)
		// 	printf("%f %f\n", v[i].left, v[i].right);
		printf("%d\n", solve(v, l));
	}
	return 0;
}