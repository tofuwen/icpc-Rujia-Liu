#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 30000;

int n, m;
vector<string> v;

vector<string> g[mod];

bool isExist(string s){
	int k = 0;
	for(int i=0;i<min((int)s.length(),3);i++){
		k *= 27;
		k += s[i]-'a'+1;
	}
	for(int i=0;i<g[k].size();i++)
		if(g[k][i] == s)
			return true;
	g[k].push_back(s);
	return false;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	cin>>T;
	for(int cc=1;cc<=T;cc++){
		int num = 0;
		v.clear();
		for(int i=0;i<mod;i++)
			g[i].clear();
		cin>>n>>m;
		getchar();
		for(int i=0;i<n;i++){
			string s;
			getline(cin, s);
			v.push_back(s);
		}
		for(int i=0;i<m;i++){
			string s;
			getline(cin, s);
			for(int j=0;j<n;j++){
				string h = v[j] + s;
				if(!isExist(h))
					num++;
			}
		}
		printf("Case %d: %d\n",cc, num);
	}
	return 0;
}