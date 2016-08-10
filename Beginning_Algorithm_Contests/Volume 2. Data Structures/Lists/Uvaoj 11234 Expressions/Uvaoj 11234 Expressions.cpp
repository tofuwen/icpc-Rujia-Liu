#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


const int maxn = 10010;

vector<char> v[maxn];
int maxLevel;

struct treeNode
{
	char c;
	treeNode* lch;
	treeNode* rch;
	int level;
	treeNode(char c, int level):c(c),level(level){}
};

bool isBigChar(char c){
	if(c>='A' && c<='Z')
		return true;
	return false;
}

treeNode* makeTree(string s, int level){
	maxLevel = max(maxLevel, level);
	int l = s.length();
	char c = s[l-1];
	v[level].push_back(c);
	treeNode* ans = new treeNode(c, level);
	if(l == 1){
		ans->rch = ans->lch = NULL;
		return ans;
	}
	s = s.substr(0,l-1);
	int remain = 1;
	int i;
	for(i=s.length()-1;i>=0;i--){
		if(isBigChar(s[i]))
			remain++;
		else
			remain--;
		if(remain == 0)
			break;
	}
	string s1 = s.substr(0,i);
	string s2 = s.substr(i);
	//cout<<"s1 "<<s1<<endl;
	//cout<<"s2 "<<s2<<endl;
	ans->lch = makeTree(s2, level+1);
	ans->rch = makeTree(s1, level+1);
	return ans;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	cin>>T;
	for(int cc=0;cc<T;cc++){
		string s;
		cin>>s;
		for(int i=0;i<maxn;i++)
			v[i].clear();
		maxLevel = 0;
		treeNode* root = makeTree(s, 0);
		for(int i=maxLevel;i>=0;i--){
			for(int j=0;j<v[i].size();j++){
				cout<<v[i][j];
			}
		}
		cout<<endl;
	}
	return 0;
}