/*Simple calculations 
The Problem

There is a sequence of n+2 elements a0, a1,¡­, an+1 (n <= 3000; -1000 <=  ai 1000). It is known that ai = (ai¨C1 + ai+1)/2 ¨C ci   for each i=1, 2, ..., n. You are given a0, an+1, c1, ... , cn. Write a program which calculates a1.
The Input

The first line is the number of test cases, followed by a blank line.
For each test case, the first line of an input file contains an integer n. The next two lines consist of numbers a0 and an+1 each having two digits after decimal point, and the next n lines contain numbers ci (also with two digits after decimal point), one number per line.

Each test case will be separated by a single line.

The Output

For each test case, the output file should contain a1 in the same format as a0 and an+1.
Print a blank line between the outputs for two consecutive test cases.

Sample Input

1

1
50.50
25.50
10.15
Sample Output

27.85
*/

#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i,j;
	int m;
	double a0,p,c;
	for(i=0;i<n;i++)
	{
		double sum=0;
		cin>>m;
		cin>>a0>>p;
		for(j=0;j<m;j++)
		{
			cin>>c;
			sum+=c*(m-j);
		}
		sum*=2;
		c=m*a0+p-sum;
		c/=(m+1);
		printf("%.2lf\n",c);
		if(i!=n-1)
			putchar('\n');
	}
	return 0;
}