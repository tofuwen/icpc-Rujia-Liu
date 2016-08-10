#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 110;

vector<string> word1;
vector<string> word2;
vector<string> ans;

int dp[maxn][maxn];
int pre[maxn][maxn];

int DP(int i, int j){
	if(i >= word1.size() || j >= word2.size())
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	if(word1[i] == word2[j]){
		pre[i][j] = 0;
		return dp[i][j] = 1+DP(i+1, j+1);
	}
	if(DP(i+1,j) > DP(i, j+1)){
		pre[i][j] = 1;
		return dp[i][j] = DP(i+1,j);
	}
	else{
		pre[i][j] = 2;
		return dp[i][j] = DP(i, j+1);
	}
}

int main()
{
	//freopen("data.txt","r",stdin);
	string s;
	while(cin>>s){
		word1.clear();
		word2.clear();
		word1.push_back(s);
		while(cin>>s){
			if(s == "#")
				break;
			word1.push_back(s);
		}
		while(cin>>s){
			if(s == "#")
				break;
			word2.push_back(s);
		}
		ans.clear();
		memset(dp,-1,sizeof(dp));
		memset(pre,-1,sizeof(pre));
		DP(0,0);
		int h = pre[0][0];
		int next1 = 0, next2 = 0;
		while(h != -1){
			if(h == 0){
				ans.push_back(word1[next1]);
				next1++;
				next2++; 
			}
			if(h == 1)
				next1++;
			if(h == 2)
				next2++;
			h = pre[next1][next2];
		}
		for(int i=0;i<ans.size();i++){
			if(i==0)
				cout<<ans[i];
			else
				cout<<" "+ans[i];
		}
		cout<<endl;
	}
	return 0;
}