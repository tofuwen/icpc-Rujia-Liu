#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int maxn = 210;

int n;
map<string, int> m;
vector<string> ori;
vector<string> sorted;
int data[maxn];

int position(int k){
	for(int i=0;i<n;i++)
		if(data[i] == k)
			return i;
	return -1;
}

int solve(){
	for(int i=n-1;i>=0;i--){
		int p = position(i);
		for(int j=0;j<p;j++)
			if(data[j] > i)
				return i;
	}
	return -1;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++){
		scanf("%d\n",&n);
		ori.clear();
		sorted.clear();
		m.clear();
		for(int i=0;i<n;i++){
			string s;
			getline(cin,s);
			ori.push_back(s);
		}
		for(int i=0;i<n;i++){
			string s;
			getline(cin, s);
			sorted.push_back(s);
			m[s] = i;
		}
		for(int i=0;i<n;i++)
			data[i] = m[ori[i]];
		int in = solve();
		// for(int i=0;i<n;i++)
		// 	printf("p%d\n", data[i]);
		// printf("solve:%d\n",in);
		for(int i=in;i>=0;i--)
			cout<<sorted[i]<<endl;
		cout<<endl;
	}
	return 0;
}