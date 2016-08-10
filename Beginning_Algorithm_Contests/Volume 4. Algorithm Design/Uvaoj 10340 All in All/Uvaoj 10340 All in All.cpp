#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

bool solve(string a, string b){
	int l = a.length();
	if(l < 1)
		return true;
	char c = a[0];
	int position = b.find(c);
	if(position == b.npos)
		return false;
	return solve(a.substr(1), b.substr(position+1));
}

int main()
{
	//freopen("data.txt","r",stdin);
	string a, b;
	while(cin>>a>>b){
		bool ok = solve(a,b);
		if(ok)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}