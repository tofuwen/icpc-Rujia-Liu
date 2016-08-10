#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

const int maxrow = 1000;
const int maxcol = 18300;

int col, row;

string data[maxrow][maxcol];
bool isNumber[maxrow][maxcol];
long long num[maxrow][maxcol];

bool isChar(char a){
	if(a>='A' && a<='Z')
		return true;
	return false;
}

void position(string s, int& x, int& y){
	int i;
	for(i=0;i<s.length();i++)
		if(!isChar(s[i]))
			break;
	//printf("i:%d\n",i);
	string s1 = s.substr(0, i);
	string s2 = s.substr(i);
	//cout<<s1<<endl;
	//cout<<s2<<endl;
	stringstream ss(s2);
	ss>>x;
	int l = s1.length();
	y = 0;
	for(int k=0;k<l;k++){
		y *= 26;
		y += s1[k]-'A'+1;
	}
}

long long solve(int i, int j){
	if(isNumber[i][j])
		return num[i][j];
	isNumber[i][j] = true;
	if(data[i][j][0] >= '0' && data[i][j][0] <= '9'){
		stringstream ss(data[i][j]);
		int h;
		ss>>h;
		return num[i][j] = h;
	}
	string s = data[i][j];
	for(int k=0;k<s.length();k++){
		if(s[k] == '+' || s[k] == '=')
			s[k] = ' ';
	}
	stringstream ss(s);
	string h;
	vector<string> v;
	while(ss>>h)
		v.push_back(h);
	long long ans = 0;
	for(int k=0;k<v.size();k++){
		int x, y;
		position(v[k], x, y);
		//printf("x:%d y:%d\n",x,y);
		ans += solve(x-1, y-1);
	}
	return num[i][j] = ans;
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++){
		scanf("%d%d", &col, &row);
		memset(isNumber, 0, sizeof(isNumber));
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				cin>>data[i][j];
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				if(j == col-1)
					printf("%lld\n", solve(i,j));
				else
					printf("%lld ", solve(i,j));
	}
	return 0;
}