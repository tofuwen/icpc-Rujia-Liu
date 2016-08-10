#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 7;

int ans = 0;

int n;
int data[maxn];

void check(vector<int> v){
	int h[maxn];
	for(int i=0;i<n;i++)
		h[i] = data[i];
	for(int i=0;i<v.size();i++){
		int now = v[i];
		swap(h[now], h[now+1]);
	}
	bool ok = true;
	for(int i=0;i<n-1;i++)
		if(h[i] > h[i+1])
			ok = false;
	if(ok)
		ans++;
}

void solve(int level, vector<int> v, int pre){
	if(level == 0){
		check(v);
		return;
	}
	for(int i=0;i<n-1;i++){
		vector<int> h = v;
		if(i != pre){
			h.push_back(i);
			solve(level-1, h, i);
		}
	}
}

void solve(int level){
	if(level == 0)
		return;
	vector<int> v;
	solve(level, v, -1);
}

int main()
{
	//freopen("data.txt","r",stdin);
	int kase = 0;
	while(scanf("%d", &n) && n){
		ans = 0;
		for(int i=0;i<n;i++)
			scanf("%d", &data[i]);
		int level = 0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(data[i] > data[j])
					level++;
		solve(level);
		printf("There are %d swap maps for input data set %d.\n", ans, ++kase);
	}
	return 0;
}