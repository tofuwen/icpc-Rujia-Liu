/*The ? 1 ? 2 ? ... ? n = k problem 

The problem

Given the following formula, one can set operators '+' or '-' instead of each '?', in order to obtain a given k
? 1 ? 2 ? ... ? n = k

For example: to obtain k = 12 , the expression to be used will be:
- 1 + 2 + 3 + 4 + 5 + 6 - 7 = 12 
with n = 7

The Input

The first line is the number of test cases, followed by a blank line.

Each test case of the input contains integer k (0<=|k|<=1000000000).

Each test case will be separated by a single line.

The Output

For each test case, your program should print the minimal possible n (1<=n) to obtain k with the above formula.

Print a blank line between the outputs for two consecutive test cases.

Sample Input

2

12

-3646397
Sample Output

7

2701
*/

#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		m=abs(m);
		int a=1;
		while(a*(a+1)/2<m)
			a++;
		if((a*(a+1)/2-m)%2==1)
		{
			if(a%2==0)
				a++;
			else
				a+=2;
		}
		cout<<a<<endl;
		//if(i!=n-1)
			putchar('\n');
	}
	return 0;
}