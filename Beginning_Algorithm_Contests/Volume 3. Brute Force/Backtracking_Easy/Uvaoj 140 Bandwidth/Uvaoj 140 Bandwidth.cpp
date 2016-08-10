#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10;

vector<char> v;
vector<int> per;
int ans;
vector<int> ansv;

vector<int> g[maxn];

bool isExist[30];

int id(char a){
	for(int i=0;i<v.size();i++)
		if(v[i] == a)
			return i;
	return -1;
}

int cal(int start, int finish, vector<int> per){
	int index1 = 0, index2 = 0;
	for(int i=0;i<per.size();i++){
		if(start == per[i])
			index1 = i;
		if(finish == per[i])
			index2 = i;
	}
	return abs(index1-index2);
}

int solve(vector<int> per){
	int nowAns = 0;
	int n = v.size();
	for(int i=0;i<n;i++)
		for(int j=0;j<g[i].size();j++){
			int k = cal(i, g[i][j], per);
			nowAns = max(nowAns, k);
		}
	return nowAns;
}

void solve(){
	for(int i=0;i<v.size();i++)
		per.push_back(i);
	do{
		int now = solve(per);
		if(ans > now){
			ans = now;
			ansv = per;
		}
	}while(next_permutation(per.begin(), per.end()));
}

int main()
{
	//freopen("data.txt", "r", stdin);
	string s;
	while(cin>>s && s[0] != '#'){
		v.clear();
		per.clear();
		ansv.clear();
		memset(isExist, 0, sizeof(isExist));
		ans = 10;
		for(int i=0;i<maxn;i++)
			g[i].clear();
		for(int i=0;i<s.length();i++){
			if(s[i] >= 'A' && s[i] <= 'Z'){
				if(!isExist[s[i]-'A']){
					isExist[s[i]-'A'] = true;
					v.push_back(s[i]);
				}
			}
			if(s[i] == ';')
				s[i] = ' ';
		}
		sort(v.begin(), v.end());
		stringstream ss(s);
		while(ss>>s){
			int Start = id(s[0]);
			for(int i=2;i<s.length();i++){
				int Finish = id(s[i]);
				g[Start].push_back(Finish);
				//g[Finish].push_back(Start);
			}
		}
		solve();
		for(int i=0;i<v.size();i++)
			printf("%c ", v[ansv[i]]);
		printf("-> %d\n", ans);
	}
	return 0;
}