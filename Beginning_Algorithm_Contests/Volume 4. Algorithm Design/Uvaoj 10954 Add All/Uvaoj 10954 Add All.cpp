/*
#include <algorithm>
using namespace std;

const int maxn = 5010;

int data[maxn];
int n;

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&data[i]);
		sort(data,data+n);
		long long ans = 0;
		for(int i=0;i<n;i++)
			ans += (n-i)*data[i];
		ans -= data[0];
		printf("%lld\n", ans);
	}
	return 0;
}
*/

#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

const int maxn = 5010;

struct cmp
{
	bool operator ()(int x, int y)
	{
		return x>y;
	}
};

priority_queue<int, vector<int>, cmp> pq;
int n;

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d",&n)==1&&n)
	{
		int x;
		while(!pq.empty())
			pq.pop();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			pq.push(x);
		}
		long long ans = 0;
		while(pq.size()>1)
		{
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			int m = a+b;
			ans += m;
			pq.push(m);
		}
		printf("%lld\n", ans);
	}
	return 0;
}