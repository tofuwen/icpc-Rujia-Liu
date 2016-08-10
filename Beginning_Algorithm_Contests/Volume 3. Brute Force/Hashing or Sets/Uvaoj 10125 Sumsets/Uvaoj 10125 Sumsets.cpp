#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int mod = 100001;
const int INF = 1<<30;

struct h
{
	int a, b, sum;
	h(int a, int b, int sum):a(a), b(b), sum(sum){}
};

int n;

vector<int> v;

vector<h> hash[mod];

bool isExist(int a, int x, int y){
	int k = (a % mod + mod) % mod;
	for(int i=0;i<hash[k].size();i++){
		h& hold = hash[k][i];
		if(hold.sum == a && hold.a != x && hold.a != y && hold.b != x && hold.b != y)
			return true;
	}
	return false;
}

int solve(){
	for(int i=v.size()-1;i>=0;i--){
		for(int j=0;j<v.size();j++){
			if(i != j && isExist(v[i]-v[j], v[i], v[j]))
				return v[i];
		}
	}
	return INF;
}

int main()
{
	//freopen("data.txt", "r", stdin);
	while(scanf("%d", &n) && n){
		v.clear();
		for(int i=0;i<mod;i++)
			hash[i].clear();
		for(int i=0;i<n;i++){
			int h;
			scanf("%d", &h);
			v.push_back(h);
		}
		//printf("kao\n");
		sort(v.begin(), v.end());
		for(int i=0;i<v.size();i++)
			for(int j=i+1;j<v.size();j++){
				int sum = v[i] + v[j];
				int k = (sum % mod + mod) % mod;
				hash[k].push_back(h(v[i], v[j], sum));
			}
		//printf("kao\n");
		int ans = solve();
		//printf("%d\n", INF);
		if(ans == INF)
			printf("no solution\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}