#include <cstdio>
#include <map>
using namespace std;

int n;

map<int, int> m;

int solve(int k){
	if(k == 1)
		return 1;
	map<int, int>::iterator iter = m.find(k);
	if(iter == m.end()){
		int ans = solve(k/2)+1;
		m[k] = ans;
		return ans;
	}
	else
		return iter->second;
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d", &n) != EOF){
		printf("%d\n", solve(n));
	}
	return 0;
}