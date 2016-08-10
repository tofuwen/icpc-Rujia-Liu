#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-10;

bool equals(double a, double b){
	return fabs(a-b) < eps;
}

struct sprinkler{
	double left, right;
	sprinkler(double left, double right):left(left), right(right){}
	friend bool operator < (const sprinkler & a, const sprinkler & b){
		if(equals(a.left, b.left))
			return a.right < b.right;
		return a.left < b.left;
	}
};

// vector<sprinkler> f(const vector<sprinkler> & v){
// 	vector<int> dupli;
// 	for(int i=1;i<(int)v.size();i++)
// 		if(v[i-1].right >= v[i].right)
// 			dupli.push_back(i);
// 	int cur = 0;
// 	int n = dupli.size();
// 	if(n == 0)
// 		return v;
// 	vector<sprinkler> ano;
// 	for(int i=0;i<(int)v.size();i++){
// 		if(cur < n && i != dupli[cur])
// 			ano.push_back(v[i]);
// 		else{
// 			if(cur < n)
// 				++cur;
// 			else
// 				ano.push_back(v[i]);
// 		}
// 	}
// 	return f(ano);
// }

int solve(const vector<sprinkler> & v, double l){
	double start = 0.0;
	int n = v.size();
	//if(n == 0 || v[0].left > eps || v[n-1].right < l-eps)
	if(n == 0 || v[0].left > eps)
		return -1;
	int ans = 0;
	int cur = 0;
	// while(1){
	// 	if(v[cur].left > start + eps)
	// 		return -1;
	// 	while(cur < n && v[cur].left < start + eps)
	// 		++cur;
	// 	cur--;
	// 	++ans;
	// 	start = v[cur].right;
	// 	if(start > l-eps)
	// 		return ans;
	// 	cur++;
	// }


	//for(int i=0;i<n+5;i++){
	while(1){
		//printf("cur :%d\n", cur);
		if(cur >= n)
			return -1;
		if(v[cur].left > start + eps)
			return -1;
		double h = 0.0;
		while(cur < n && v[cur].left < start + eps){
			h = max(h, v[cur].right);
			++cur;
		}
		++ans;
		start = max(h, start);
		if(start > l-eps)
			return ans;
	}
	return -1;
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int n, l, w;
	while(scanf("%d%d%d", &n, &l, &w) != EOF){
		double center, r;
		vector<sprinkler> v;
		for(int i=0;i<n;i++){
			scanf("%lf%lf", &center, &r);
			//printf("%f %f\n", center, r);
			double hh = r*r-(double)w*w/4;
			if(hh < eps)
				continue;
			double h = sqrt(hh);
			v.push_back(sprinkler(center-h<0?0.0:center-h, center+h>l?(double)l:center+h));
		}
		sort(v.begin(), v.end());
		//v = f(v);
		// for(int i=0;i<v.size();i++)
		// 	printf("%f %f\n", v[i].left, v[i].right);
		printf("%d\n", solve(v, l));
	}
	return 0;
}