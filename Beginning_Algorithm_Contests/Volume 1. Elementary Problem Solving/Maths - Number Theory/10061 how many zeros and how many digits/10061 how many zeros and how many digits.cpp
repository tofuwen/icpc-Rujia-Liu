/*
How many zeros and how many digits?
Input: standard input
Output: standard output

Given a decimal integer number you will have to find out how many trailing zeros will be there in its factorial in a given number system and also you will have to find how many digits will its factorial have in a given number system? You can assume that for a b based number system there are b different symbols to denote values ranging from 0 ... b-1.

Input
There will be several lines of input. Each line makes a block. Each line will contain a decimal number N (a 20bit unsigned number) and a decimal number B (1<B<=800), which is the base of the number system you have to consider. As for example 5! = 120 (in decimal) but it is 78 in hexadecimal number system. So in Hexadecimal 5! has no trailing zeros

Output
For each line of input output in a single line how many trailing zeros will the factorial of that number have in the given number system and also how many digits will the factorial of that number have in that given number system. Separate these two numbers with a single space. You can be sure that the number of trailing zeros or the number of digits will not be greater than 2^31-1

Sample Input:
2 10
5 16
5 10
 
Sample Output:
0 1
0 2
1 3

  */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int f(int n,int b);
int g(int n,int b);
int is_prime(int i);
int main()
{
	int n,b;
	while(cin>>n>>b)
	{
		if(n==1)
			printf("0 1\n");
		else
			printf("%d %d\n",f(n,b),g(n,b));
	}
	return 0;
}


int g(int n,int b)
{
	double sum=0;
	for(int i=2;i<=n;i++)
		sum+=log10((double)i);
	double t=log10((double)b);
	return floor(sum/t+1e-9)+1;
}


int f(int n,int b)
{
	int a[800];
	int c[800],d[800];
	int i,j;
	int step=0;
	int t=b;
	int min=pow(2,30)+pow(2,29);
	//cout<<min<<endl;;
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	for(i=2;i<=b;i++)
	{
		if(is_prime(i))
			a[step++]=i;
	}
	for(i=0;i<step;i++)
	{
		while(t%a[i]==0)
		{
			c[i]++;
			t/=a[i];
		}
	}
	for(i=2;i<=n;i++)
	{
		t=i;
		for(j=0;j<step;j++)
		{
			while(t%a[j]==0)
			{
				d[j]++;
				t/=a[j];
			}
		}
	}
	for(i=0;i<step;i++)
	{
		if(c[i]!=0)
		{
			if(min>(d[i]/c[i]))
				min=d[i]/c[i];
		}
	}
	return min;
}



int is_prime(int i)
{
	int ok=1;
	for(int j=2;j*j<=i+1;j++)
	{
		if(i%j==0)
		{
			ok=0;
			break;
		}
	}
	return ok;
}