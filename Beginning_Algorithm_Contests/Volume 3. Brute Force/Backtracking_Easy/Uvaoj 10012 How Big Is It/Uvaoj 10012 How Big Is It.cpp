#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 10;
int n;

struct Point{
	double x;
	double y;
	double r;
	Point(double x, double y, double r):x(x),y(y),r(r){}
};

double r[maxn];
double ans;

double cal(double r1, double r2){
	double hypotenuse = r1 + r2;
	double right1 = fabs(r1-r2);
	return sqrt(hypotenuse*hypotenuse - right1*right1);
}

void solve(vector<int> v){
	// int num = v.size();
	// if(num >= 2){
	// 	if(r[v[1]] > r[v[0]] + cal(r[v[0]], r[v[1]])){
	// 		v.erase(v.begin());
	// 		solve(v);
	// 		return;
	// 	}
	// 	if(r[v[num-2]] > r[v[num-1]] + cal(r[v[num-2]], r[v[num-1]])){
	// 		v.erase(v.begin()+num-1);
	// 		solve(v);
	// 		return;
	// 	}
	// }
	// for(int i=1;i<num-1;i++){
	// 	double l1 = cal(r[v[i-1]], r[v[i]]) + cal(r[v[i]], r[v[i+1]]);
	// 	double l2 = cal(r[v[i-1]], r[v[i+1]]);
	// 	if(l1 < l2){
	// 		v.erase(v.begin()+i);
	// 		solve(v);
	// 		return;
	// 	}
	// }
	// double all = r[v[0]] + r[v[num-1]];
	// for(int i=0;i<num-1;i++)
	// 	all += cal(r[v[i]], r[v[i+1]]);
	// ans =  min(all, ans);
	vector<Point> p;
	for(int i=0;i<v.size();i++){
		int now = v[i];
		double maxl = r[now];
		for(int j=0;j<p.size();j++)
			maxl = max(maxl, p[j].x + cal(p[j].r, r[now]));
		p.push_back(Point(maxl, r[now], r[now]));
	}
	double maxans = 0;
	for(int i=0;i<p.size();i++)
		maxans = max(maxans, p[i].x + p[i].r);
	ans = min(ans, maxans);
}

int main()
{
	//freopen("data.txt", "r",stdin);
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++){
		//double maxr = 0;
		ans = 1e30;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%lf", &r[i]);
		//	maxr = max(maxr, r[i]);
		}
		std::vector<int> v;
		for(int i=0;i<n;i++)
			v.push_back(i);
		do{
			solve(v);
		}while(next_permutation(v.begin(), v.end()));
		printf("%.3f\n", ans);
	}
	return 0;
}