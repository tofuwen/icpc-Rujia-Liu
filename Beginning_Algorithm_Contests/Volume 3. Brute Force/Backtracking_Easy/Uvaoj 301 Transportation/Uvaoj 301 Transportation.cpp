#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 25;
const int maxStation = 10;

int ans;

int n, m, num;
int sPos[maxn];
int dPos[maxn];
int p[maxn];

void solve(vector<int> v, int now, int money){
	ans = max(money, ans);
	if(now == num)
		return;
	solve(v, now+1, money);
	bool ok = true;
	for(int i=sPos[now];i<dPos[now];i++){
		v[i] += p[now];
		if(v[i] > n)
			ok = false;
	}
	if(ok)
		solve(v, now+1, p[now]*(dPos[now]-sPos[now])+money);
}

void solve(){
	vector<int> v;
	for(int i=0;i<m;i++)
		v.push_back(0);
	solve(v,0,0);
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d%d%d", &n, &m, &num) && n){
		ans = 0;
		for(int i=0;i<num;i++)
			scanf("%d%d%d", &sPos[i], &dPos[i], &p[i]);
		solve();
		printf("%d\n", ans);
	}
	return 0;
}