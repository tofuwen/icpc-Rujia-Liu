#include <cstdio>
#include <vector>
using namespace std;

int h, k;

int ans;
vector<int> ansv;

bool okay(int all, vector<int>& v, int degree){
	if(all < 0)
		return false;
	if(all == 0)
		return true;
	if(degree == 0)
		return false;
	for(int i=0;i<v.size();i++){
		bool ok = okay(all-v[i], v, degree-1);
		if(ok)
			return true;
	}
	return false;
}

int check(vector<int>& v){
	for(int i=1;;i++){
		if(!okay(i,v,h))
			return i-1;
	}
}

void solve(vector<int>& v){
	int nSize = v.size();
	if(nSize == k){
		int num = check(v);
		if(num > ans){
			ans = num;
			ansv = v;
		}
		return;
	}
	else{
		int start = v[nSize-1]+1, finish = v[nSize-1]*h+1;
		for(int i=start;i<=finish;i++){
			vector<int> h = v;
			h.push_back(i);
			solve(h);
		}
	}
}

void print(){
	for(int i=0;i<ansv.size();i++)
		printf("%3d", ansv[i]);
	printf(" ->");
	printf("%3d\n", ans);
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d%d", &h, &k) && h){
		ans = 0;
		vector<int> v;
		v.push_back(1);
		solve(v);
		print();
	}
	return 0;
}