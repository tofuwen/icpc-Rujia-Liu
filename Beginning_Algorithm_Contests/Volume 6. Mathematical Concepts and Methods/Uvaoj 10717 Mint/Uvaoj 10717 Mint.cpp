/*
Problem E: Mint

The Royal Canadian Mint has commissioned a new series of designer coffee tables, with legs that are constructed from stacks of coins. Each table has four legs, each of which uses a different type of coin. For example, one leg might be a stack of quarters, another nickels, another loonies, and another twonies. Each leg must be exactly the same length.
Many coins are available for these tables, including foreign and special commemorative coins. Given an inventory of available coins and a desired table height, compute the lengths nearest to the desired height for which four legs of equal length may be constructed using a different coin for each leg.

Input consists of several test cases. Each case begins with an integers: 4 <= n <= 50 giving the number of types of coins available, and 1 <= t <= 10 giving the number of tables to be designed. n lines follow; each gives the thickness of a coin in hundredths of millimetres. t lines follow; each gives the height of a table to be designed (also in hundredths of millimetres). A line containing 0 0 follows the last test case.

For each table, output a line with two integers: the greatest leg length not exceeding the desired length, and the smallest leg length not less than the desired length.

Sample Input

4 2
50
100
200
400
1000
2000
0 0
Output for Sample Input

800 1200
2000 2000
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1<<30;

int n,t;
int coins[60];
int tables[20];
int com[10];
int g[20];
int l[20];

bool next_Com(int num, int k)//0,1...num-1 choose k
{
	if(com[k-1]!=num-1)
	{
		com[k-1]++;
		return true;
	}
	int i;
	for(i=k-1;i>=0;i--)
		if(com[i]!=num-k+i)
			break;
	if(i==-1)
		return false;
	com[i]++;
	for(int j=i+1;j<k;j++)
		com[j] = com[i]+(j-i);
	return true;
}

void makeFirstCom(int num, int k)
{
	for(int i=0;i<k;i++)
		com[i] = i;
}

int lcm(int a, int b)
{
	int gcd = __gcd(a,b);
	return a/gcd*b;
}

int lcm(int a1, int a2, int a3, int a4)
{
	int b1 = lcm(a1,a2);
	int b2 = lcm(a3,a4);
	return lcm(b1,b2);
}

int main()
{
	//freopen("data.txt", "r", stdin);
	//freopen("dataout.txt","w",stdout);
	// makeFirstCom(8, 4);
	// 	do
	// 	{
	// 		for(int i=0;i<4;i++)
	// 			printf("%d ",com[i]);
	// 		putchar('\n');
	// 	}while(next_Com(8, 4));
	while(scanf("%d%d",&n,&t)&&n)
	{
		memset(g,0,sizeof(g));
		for(int i=0;i<20;i++)
			l[i] = INF;
		for(int i=0;i<n;i++)
			scanf("%d",&coins[i]);
		for(int i=0;i<t;i++)
			scanf("%d",&tables[i]);
       // for(int i=0;i<n;i++)
		//	printf("%d ",coins[i]);
        //printf("\n");
		//for(int i=0;i<t;i++)
		//	printf("%d ",tables[i]);
       // printf("\n");
		makeFirstCom(n, 4);
		do
		{
			int h = lcm(coins[com[0]],coins[com[1]],coins[com[2]],coins[com[3]]);
			for(int i=0;i<t;i++)
			{
                g[i] = max(tables[i]/h*h,g[i]);
                if(tables[i]%h==0)
                    l[i] = tables[i];
                else
                    l[i] = min((tables[i]/h+1)*h,l[i]);
			}
		}while(next_Com(n, 4));
		for(int i=0;i<t;i++)
			printf("%d %d\n",g[i],l[i]);
	}
	return 0;
}
