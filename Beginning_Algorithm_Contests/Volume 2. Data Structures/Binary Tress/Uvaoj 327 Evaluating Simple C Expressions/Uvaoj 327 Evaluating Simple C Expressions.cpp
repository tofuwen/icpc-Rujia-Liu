#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 30;

int before[maxn];
int after[maxn];
bool v[maxn];

void pre()
{
	for(int i=0;i<26;i++)
		before[i] = after[i] = i+1;
	memset(v,0,sizeof(v));
}

int solve(char o, int a, int b)
{
	switch(o)
	{
		case '+': return a+b;
		case '-': return a-b;
	}
	return a+b;
}

int main()
{
	//freopen("data.txt","r",stdin);
	string s;
	string special[2];
	special[0] = "++";
	special[1] = "--";
	while(getline(cin,s))
	{
		cout<<"Expression: "<<s<<endl;
		pre();
		int p;
		for(int k=0;k<2;k++){
			while((p = s.find(special[k]))!=s.npos)
			{
				int beforeStart = p-1;
				int afterStart = p+2;
				int l = s.length();
				while(beforeStart >= 0 && s[beforeStart] == ' ')
					beforeStart--;
				if(beforeStart>=0 && s[beforeStart]>='a' && s[beforeStart]<='z'){
					int in = s[beforeStart] - 'a';
					if(k==0)
						after[in]++;
					else
						after[in]--;
				}
				while(afterStart < l && s[afterStart] == ' ')
					afterStart++;
				if(afterStart < l && s[afterStart]>='a' && s[afterStart]<='z'){
					int in = s[afterStart] - 'a';
					if(k==0){
						before[in]++; 
						after[in]++;
					}
					else{
						before[in]--; 
						after[in]--;
					}
				}
				s.erase(p,2);
			}
		}
		//cout<<s<<endl;
		int pre = 0;
		char o = '+';
		for(int i=0;i<s.length();i++){
			if(s[i]>='a' && s[i]<='z'){
				pre = solve(o,pre,before[s[i]-'a']);
				v[s[i]-'a'] = true;
			}
			else
				if(s[i]!=' ')
					o = s[i];
		}
		printf("    value = %d\n",pre);
		for(int i=0;i<26;i++)
			if(v[i])
				printf("    %c = %d\n",i+'a',after[i]);
	}
	return 0;
}