#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const int maxn = 14;

struct dic
{
	string replace;
	string by;
};

dic d[maxn];

int main()
{
	//freopen("data.txt","r",stdin);
	int n;
	while(scanf("%d\n",&n))
	{
		if(n == 0)
			break;
		for(int i=0;i<n;i++){
			getline(cin,d[i].replace);
			getline(cin,d[i].by);
		}
		string ans;
		getline(cin,ans);
		int now = 0;
		while(now<n){
			int p = ans.find(d[now].replace);
			if(p == ans.npos)
			{
				now++;
				continue;
			}
			ans.replace(p,d[now].replace.length(),d[now].by);
		}
		cout<<ans<<endl;
	}
	return 0;
}