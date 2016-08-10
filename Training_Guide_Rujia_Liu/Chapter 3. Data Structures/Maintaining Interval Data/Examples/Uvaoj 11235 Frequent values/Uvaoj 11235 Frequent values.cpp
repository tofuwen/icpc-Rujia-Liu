/*
2007/2008 ACM International Collegiate Programming Contest 
University of Ulm Local Contest
Problem F: Frequent values

You are given a sequence of n integers a1 , a2 , ... , an in non-decreasing order. In addition to that, you are given several queries consisting of indices i and j (1 ≤ i ≤ j ≤ n). For each query, determine the most frequent value among the integers ai , ... , aj.

Input Specification

The input consists of several test cases. Each test case starts with a line containing two integers n and q (1 ≤ n, q ≤ 100000). The next line contains n integers a1 , ... , an (-100000 ≤ ai ≤ 100000, for each i ∈ {1, ..., n}) separated by spaces. You can assume that for each i ∈ {1, ..., n-1}: ai ≤ ai+1. The following q lines contain one query each, consisting of two integers i and j (1 ≤ i ≤ j ≤ n), which indicate the boundary indices for the query.

The last test case is followed by a line containing a single 0.

Output Specification

For each query, print one line with one integer: The number of occurrences of the most frequent value within the given range.

Sample Input

10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10
0
Sample Output

1
4
3
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100010;
const int maxlogn = 20;
const int INF = 1<<30;

int d[maxn][maxlogn];
vector<int> v;
int Count[maxn];
int id[maxn];
int left[maxn];
int right[maxn];

void RMQ_init(const vector<int>& A)
{
	int n = A.size();
	for(int i=0;i<n;i++)
		d[i][0] = A[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=0;i+(1<<j)-1<n;i++)
			d[i][j] = max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}

int RMQ(int L, int R)//L, R inclusive
{
	if(L>R)
		return 0;
	int k = 0;
	while((1<<(k+1))<=R-L+1)
		k++;
	return max(d[L][k],d[R-(1<<k)+1][k]);
}

int max(int a1, int a2, int a3)
{
	return max(max(a1,a2),a3);
}

int main()
{
	//freopen("data.txt","r",stdin);
	int n,q;
	while(scanf("%d",&n)&&n)
	{
		memset(Count,0,sizeof(Count));
		v.clear();
		int pre = INF;
		int num = -1;
		scanf("%d",&q);
		for(int i=0;i<n;i++)
		{
			int now;
			scanf("%d",&now);
			if(now!=pre)
			{
				Count[++num]++;
				pre = now;
				left[num] = i;
				if(i!=0)
					right[num-1] = i-1;
			}
			else
				Count[num]++;
			id[i] = num;
		}
		right[num] = n-1;
		for(int i=0;i<=num;i++)
			v.push_back(Count[i]);
		// for(int i=0;i<=num;i++)
		// 	printf("%d ",Count[i]);
		// printf("\n");
		RMQ_init(v);
		for(int i=0;i<q;i++)
		{
			int L,R;
			scanf("%d%d",&L,&R);
			L--;
			R--;
			int l = id[L];
			int r = id[R];
			if(l==r)
			{
				printf("%d\n",R-L+1);
				continue;
			}
			int a1 = Count[l] - (L-left[l]);
			int a2 = Count[r] - (right[r]-R);
			int a3 = RMQ(l+1,r-1);
			// printf("a1: %d\n",a1);
			// printf("a2: %d\n",a2);
			// printf("a3: %d\n",a3);
			printf("%d\n",max(a1,a2,a3));
		}
	}
	return 0;
}