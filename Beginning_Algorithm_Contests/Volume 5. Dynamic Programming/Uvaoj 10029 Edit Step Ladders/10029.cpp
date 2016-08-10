#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 25010;

vector<int> g[maxn];
int dp[maxn];
int n;

void make_edge(const vector<string> & v, int index) {
	int l = v[index].length();
	for(int i=0;i<=l;i++) {
		for(char c='a';c<='z';c++) {
			string next = v[index];
			next.insert(i, 1, c);
			auto iter = lower_bound(v.begin() + index, v.end(), next);
			if(iter != v.end() && *iter == next)
				g[index].push_back(iter - v.begin());
		}
	}
	for(int i=0;i<l;i++) {
		string next = v[index];
		next.erase(i, 1);
		auto iter = lower_bound(v.begin() + index, v.end(), next);
		if(iter != v.end() && *iter == next)
			g[index].push_back(iter - v.begin());
	}
	for(int i=0;i<l;i++) {
		for(char c='a';c<='z';c++) {
			if(v[index][i] == c)
				continue;
			string next = v[index];
			next.replace(i, 1, 1, c);
			auto iter = lower_bound(v.begin() + index, v.end(), next);
			if(iter != v.end() && *iter == next)
				g[index].push_back(iter - v.begin());
		}
	}
}

void make_graph(const vector<string> & v) {
	int size = v.size();
	for(int i=0;i<size;i++)
		make_edge(v, i);
	// for(int i=0;i<size;i++) {
	// 	for(int j=0;j<g[i].size();j++)
	// 		cout << g[i][j] << ' ';
	// 	cout << endl;
	// }
}

int DP(int index) {
	if(dp[index] != -1)
		return dp[index];
	int ans = 1;
	for(int i=0;i<g[index].size();i++)
		ans = max(ans, 1+DP(g[index][i]));
	return dp[index] = ans;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	string s;
	vector<string> v;
	while(cin >> s) {
		v.push_back(s);
	}
	make_graph(v);
	n = v.size();
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	for(int i=0;i<n;i++)
		ans = max(ans, DP(i));
	cout << ans << endl;
	return 0;
}