/*
Problem D

Dancing Digits

Digits like to dance. One day, 1, 2, 3, 4, 5, 6, 7 and 8 stand in a line to have a wonderful party. Each time, a male digit can ask a female digit to dance with him, or a female digit can ask a male digit to dance with her, as long as their sum is a prime. Before every dance, exactly one digit goes to who he/she wants to dance with - either to its immediate left or immediate right.

For simplicity, we denote a male digit x by itself x, and denote a female digit x by -x. Suppose the digits are in order {1, 2, 4, 5, 6, -7, -3, 8}. If -3 wants to dance with 4, she must go either to 4's left, resulting {1, 2, -3, 4, 5, 6, -7, 8} or his right, resulting {1, 2, 4, -3, 5, 6, -7, 8}. Note that -3 cannot dance with 5, since their sum 3+5=8 is not a prime; 2 cannot dance with 5, since they're both male.

Given the initial ordering of the digits, find the minimal number of dances needed for them to sort in increasing order (ignoring signs of course).

Input

The input consists of at most 20 test cases. Each case contains exactly 8 integers in a single line. The absolute values of these integers form a permutation of {1, 2, 3, 4, 5, 6, 7, 8}. The last case is followed by a single zero, which should not be processed.

Output

For each test case, print the case number and the minimal number of dances needed. If they can never be sorted in increasing order, print -1.

Sample Input

1 2 4 5 6 -7 -3 8
1 2 3 4 5 6 7 8
1 2 3 5 -4 6 7 8
1 2 3 5 4 6 7 8
2 -8 -4 5 6 7 3 -1
0
Output for the Sample Input

Case 1: 1
Case 2: 0
Case 3: 1
Case 4: -1
Case 5: 3
Rujia Liu's Present 1: A Tiny Contest of Brute Force
*/


#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

struct dance
{
	/* data */
	int times;
	int v;
};


const int mod = 30013;
int cases;
bool p[18];
bool isNegative[10];
vector<int> v[mod];
queue<dance> q;

void prime()
{
	memset(p,0,sizeof(p));
	p[2] = p[3] = p[5] = p[7] = p[11] = p[13] = p[17] = true;
}

void pre()
{
	memset(isNegative,0,sizeof(isNegative));
	for(int i=0;i<mod;i++)
		v[i].clear();
	while(!q.empty())
		q.pop();
}

int abso(int k)
{
	if(k<0)
		return -k;
	return k;
}

int make(int data[])
{
	int ans = 0;
	for(int i=0;i<8;i++)
	{
		ans *= 10;
		ans += abso(data[i]);
	}
	return ans;
}

void demake(int v, int a[])
{
	for(int i=7;i>=0;i--)
	{
		a[i] = v%10;
		if(isNegative[a[i]])
			a[i] = -a[i];
		v /=10;
	}
}

bool isExist(int value)
{
	int check = value % mod;
	for(int i=0;i<v[check].size();i++)
	{
		if(v[check][i]==value)
			return true;
	}
	v[check].push_back(value);
	return false;
}

bool isOk(int v)
{
	if(v==12345678)
		return true;
	return false;
}

// void print(int h[])
// {
// 	for(int i=0;i<8;i++)
// 		printf("%d ",h[i]);
// 	printf("\n");
// }

void moveBefore(int s, int d, int o[], int a[])
{
	for(int i=0;i<8;i++)
		a[i] = o[i];
	if(s==d-1)
		return;
	if(s<d)
	{
		for(int i=s;i<d-1;i++)
			a[i] = o[i+1];
		a[d-1] = o[s];
	}
	else
	{
		a[d] = o[s];
		for(int i=d;i<s;i++)
			a[i+1] = o[i];
	}
}

void moveAfter(int s, int d, int o[], int a[])
{
	for(int i=0;i<8;i++)
		a[i] = o[i];
	if(s==d+1)
		return;
	if(s<d)
	{
		for(int i=s;i<d;i++)
			a[i] = o[i+1];
		a[d] = o[s];
	}
	else
	{
		a[d+1] = o[s];
		for(int i=d+1;i<s;i++)
			a[i+1] = o[i];
	}
}

void oo(int a[], int tt)
{
	int h[10];
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(i!=j)
			{
				if(p[abso(a[i])+abso(a[j])]&&a[i]*a[j]<0)
				{
					moveBefore(i,j,a,h);
					int hold = make(h);
					if(!isExist(hold))
					{
						dance hh;
						hh.times = tt+1;
						hh.v = hold;
						q.push(hh);
					//	print(h);
					}
					moveAfter(i,j,a,h);
					hold = make(h);
					if(!isExist(hold))
					{
						dance hh;
						hh.times = tt+1;
						hh.v = hold;
						q.push(hh);
					//	print(h);
					}
				}
			}
		}
	}
}

bool o(dance now)
{
	int a[10];
	int tt = now.times;
	if(isOk(now.v))
	{
		printf("Case %d: %d\n",++cases,tt);
		return true;
	}
	demake(now.v,a);
	oo(a,tt);
	return false;
}

int main()
{
	//freopen("data.txt","r",stdin);
	//freopen("dataout.txt","w",stdout);
	int data[8];
	prime();
	cases = 0;
	while(scanf("%d",&data[0])&&data[0])
	{
		pre();
		if(data[0]<0)
			isNegative[-data[0]] = true;
		for(int i=1;i<8;i++)
		{
			scanf("%d",&data[i]);
			if(data[i]<0)
				isNegative[-data[i]] = true;
		}
		dance s;
		s.v = make(data);
		s.times = 0;
		q.push(s);
		bool ok = false;
		while(!q.empty())
		{
			dance now = q.front();
			q.pop();
			ok = o(now);
			if(ok)
				break;
		}
		if(!ok)
			printf("Case %d: -1\n",++cases);
	}
	return 0;
}