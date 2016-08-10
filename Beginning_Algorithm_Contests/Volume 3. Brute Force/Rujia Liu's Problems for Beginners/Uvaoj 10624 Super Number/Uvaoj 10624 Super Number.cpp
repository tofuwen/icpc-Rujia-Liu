#include <cstdio>
#include <vector>
using namespace std;

int n, m;
vector<int> ans;

bool solve(vector<int> v, int level){
	int l = v.size();
	if(level == m+1){
		ans = v;
		return true;
	}
	int mod = 0;
	for(int i=0;i<v.size();i++){
		mod *= 10;
		mod += v[i];
		mod %= level;
	}
	int want = (level - (mod * 10 % level)) % level;
	while(want>=0 && want<=9){
		v.push_back(want);
		bool ok = solve(v, level+1);
		if(ok)
			return true;
		v.resize(l);
		want += level;
	}
	return false;
}

bool next(vector<int>& v){
	int i;
	for(i=v.size()-1;i>=0;i--)
		if(v[i] != 9)
			break;
	if(i == -1)
		return false;
	for(int k=i+1;k<v.size();k++)
		v[k] = 0;
	v[i]++;
	return true;
}

bool solve(){
	vector<int> v;
	v.push_back(1);
	for(int i=1;i<n-1;i++)
		v.push_back(0);
	do{
		bool ok = solve(v, n);
		if(ok)
			return true;
	}while(next(v));
	return false;
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=1;cc<=T;cc++){
		scanf("%d%d", &n, &m);
		if(n == 1)
			n = 2;
		if(solve()){
			printf("Case %d: ",cc);
			for(int i=0;i<ans.size();i++)
				printf("%d", ans[i]);
			printf("\n");
		}
		else
			printf("Case %d: -1\n",cc);
	}
	return 0;
}