#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int maxn = 1010;

int n;

struct point{
	int x, y;
	point(int x, int y):x(x), y(y){}
	friend bool operator < (const point & a, const point & b){
		if(a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	}
};

bool solve(const vector<point> & v){
	multiset<point> s;
	int sum = v[0].x + v[n-1].x;
	for(int i=0;i<n;i++)
		s.insert(v[i]);
	for(int i=0;i<n;i++){
		point next = point(sum - v[i].x, v[i].y);
		auto look = s.find(next);
		if(look == s.end())
			return false;
		s.erase(look);
	}
	return true;
}

int main()
{
	//freopen("data.txt","r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++){
		scanf("%d", &n);
		vector<point> v;
		v.reserve(n+5);
		for(int i=0;i<n;i++){
			int x, y;
			scanf("%d%d", &x, &y);
			v.push_back(point(x, y));
		}
		sort(v.begin(), v.end());
		if(solve(v))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}