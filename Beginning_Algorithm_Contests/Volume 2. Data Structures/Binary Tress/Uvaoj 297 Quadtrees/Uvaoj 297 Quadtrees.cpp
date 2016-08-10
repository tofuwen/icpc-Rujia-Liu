#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

struct Tree
{
	bool isParent;
	string s;
	int x[4];
	int y[4];
	Tree(string s)
	{
		this->s = s;
		if(s[0] == 'p'){
			isParent = true;
			int pre = 1;
			for(int i=0;i<4;i++)
			{
				int remain = 1;
				x[i] = y[i] = pre;
				while(remain>0){
					if(s[y[i]] == 'p')
						remain += 3;
					else
						remain--;
					y[i]++;
				}
				pre = y[i];
			}
		}
		else
			isParent = false;
	}
};

void make(Tree t1, Tree t2, string& ans)
{
	if(t1.s[0]=='f' || t2.s[0]=='f'){
		ans += "f";
		return;
	}
	if(t1.s[0]=='e'){
		ans += t2.s;
		return;
	}
	if(t2.s[0]=='e'){
		ans += t1.s;
		return;
	}
	ans += "p";
	for(int i=0;i<4;i++)
	{
		Tree m1 = Tree(t1.s.substr(t1.x[i],t1.y[i]-t1.x[i]));
		Tree m2 = Tree(t2.s.substr(t2.x[i],t2.y[i]-t2.x[i]));
		make(m1,m2,ans);
	}
}

int cal(Tree t, int degree)
{
	if(t.s[0] == 'f')
		return pow(2,2*degree);
	if(t.s[0] == 'e')
		return 0;
	int ans = 0;
	for(int i=0;i<4;i++)
		ans += cal(Tree(t.s.substr(t.x[i],t.y[i]-t.x[i])),degree-1);
	return ans;
}

int cal(string ans)
{
	Tree t = Tree(ans);
	return cal(t,5);
}


int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=1;cc<=T;cc++)
	{
		string tree1, tree2;
		cin>>tree1>>tree2;
		Tree t1 = Tree(tree1);
		Tree t2 = Tree(tree2);
		// for(int i=0;i<4;i++)
		// 	printf("x[i]:%d y[i]:%d\n",t1.x[i],t1.y[i]);
		string ans = "";
		make(t1,t2,ans);
		//cout<<ans<<endl;
		printf("There are %d black pixels.\n",cal(ans));
	}
	return 0;
}