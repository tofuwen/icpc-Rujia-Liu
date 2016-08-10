#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct point
{
	int x, y;
	point(int x, int y):x(x),y(y){}
};

int board[10][10];

int ans;

bool isOkay(int x, int y, vector<point> v){
	for(int i=0;i<v.size();i++)
		if(v[i].y == y || v[i].y+v[i].x == y+x || v[i].y-v[i].x == y-x)
			return false;
	return true;
}

void solve(vector<point> v){
	if(v.size() == 8){
		int k = 0;
		for(int i=0;i<v.size();i++)
			k += board[v[i].x][v[i].y];
		ans = max(ans, k);
		return;
	}
	for(int i=0;i<8;i++)
		if(isOkay(v.size(), i, v)){
			vector<point> h = v;
			h.push_back(point(v.size(),i));
			solve(h);
		}
}

void solve(){
	for(int i=0;i<8;i++){
		vector<point> v;
		v.push_back(point(0,i));
		solve(v);
	}
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++){
		ans = 0;
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
				scanf("%d", &board[i][j]);
		solve();
		printf("%5d\n", ans);
	}
	return 0;
}