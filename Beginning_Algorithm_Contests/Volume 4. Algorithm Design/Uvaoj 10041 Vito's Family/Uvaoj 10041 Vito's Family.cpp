/*
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
using namespace std;

const int maxn = 600;
const int INF = 1<<30;

int n;
int data[maxn];
int maxs;
int mins;
int ans;

int cal(int d)
{
	int a = 0;
	for(int i=0;i<n;i++)
		a += abs(data[i]-d);
	return a;
}

int main()
{
	freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	getchar();
	string s;
	for(int cc=0;cc<T;cc++)
	{
		n = 0;
		int x;
		mins = INF;
		ans = INF;
		maxs = 0;
		getline(cin,s);
		stringstream ss(s);
		while(ss>>x)
		{
			data[n++] = x;
			mins = min(mins,x);
			maxs = max(maxs,x);
		}
		for(int i=0;i<n;i++)
			cout<<data[i];
		cout<<endl;
		for(int i=mins;i<=maxs;i++)
		{
			int sum = cal(i);
			ans = min(ans,sum);
		}
		printf("%d\n",ans);
	}
	return 0;
}
*/


/*
//brute force, TLE!!
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 600;
const int INF = 1<<30;

int n;
int data[maxn];
int maxs;
int mins;
int ans;

int cal(int d)
{
	int a = 0;
	for(int i=0;i<n;i++)
		a += abs(data[i]-d);
	return a;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++)
	{
		scanf("%d",&n);
		mins = INF;
		ans = INF;
		maxs = 0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&data[i]);
			mins = min(mins,data[i]);
			maxs = max(maxs,data[i]);
		}
		for(int i=mins;i<=maxs;i++)
		{
			int sum = cal(i);
			ans = min(ans,sum);
		}
		printf("%d\n",ans);
	}
	return 0;
}
*/

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 600;
const int INF = 1<<30;

int n;
int data[maxn];
int ans;

int cal(int d)
{
	int a = 0;
	for(int i=0;i<n;i++)
		a += abs(data[i]-d);
	return a;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&data[i]);
		sort(data,data+n);
		printf("%d\n",cal(data[n/2]));
	}
	return 0;
}