#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int maxn = 27000;

vector<string> v;

vector<string> g[maxn];

void Add(string s){
	int l = min((int)s.length(),3);
	int k = 0;
	for(int i=0;i<l;i++){
		k *= 27;
		k += s[i]-'a'+1;
	}
	g[k].push_back(s);
}

bool isExist(string s){
	if(s.length() == 0)
		return false;
	int l = min((int)s.length(),3);
	int k = 0;
	for(int i=0;i<l;i++){
		k *= 27;
		k += s[i]-'a'+1;
	}
	for(int i=0;i<g[k].size();i++)
		if(g[k][i] == s)
			return true;
	return false;
}

bool isOk(string s){
	for(int j=1;j<s.length();j++){
		string s1 = s.substr(0,j);
		string s2 = s.substr(j);
		if(isExist(s1) && isExist(s2))
			return true;
	}
	return false;
}

void solve(){
	for(int i=0;i<v.size();i++)
		if(isOk(v[i]))
			cout<<v[i]<<endl;
}

int main()
{
	//freopen("data.txt", "r",stdin);
	string s;
	for(int i=0;i<maxn;i++)
		g[i].clear();
	while(cin>>s){
		v.push_back(s);
		Add(s);
	}
	solve();
	// sort(v.begin(), v.end());
	// for(int i=0;i<v.size();i++)
	// 	Add(v[i]);
	return 0;
}