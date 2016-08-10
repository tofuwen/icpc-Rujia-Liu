
/*

Code Refactoring
Time Limit: 2 seconds
"Harry, my dream is a code waiting to be
broken. Break the code, solve the crime."
Agent Cooper

Several algorithms in modern cryptography are based on the fact that factoring large numbers is difficult. Alicia and Bobby know this, so they have decided to design their own encryption scheme based on factoring. Their algorithm depends on a secret code, K, that Alicia sends to Bobby before sending him an encrypted message. After listening carefully to Alicia's description, Yvette says, "But if I can intercept K and factor it into two positive integers, A and B, I would break your encryption scheme! And the K values you use are at most 10,000,000. Hey, this is so easy; I can even factor it twice, into two different pairs of integers!"

Input
The first line of input gives the number of cases, N (at most 25000). N test cases follow. Each one contains the code, K, on a line by itself.

Output
For each test case, output one line containing "Case #x: K = A * B = C * D", where A, B, C and D are different positive integers larger than 1. A solution will always exist.

Sample Input	Sample Output
3
120
210
10000000
Case #1: 120 = 12 * 10 = 6 * 20
Case #2: 210 = 7 * 30 = 70 * 3
Case #3: 10000000 = 10 * 1000000 = 100 * 100000

  */

#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a;
	int b,c,d,e;
	int i,j;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		int count=0;
		for(j=2;j*j<=a;j++)
		{
			if(count==2)
				break;
			if(count==1)
			{
				if(a%j==0)
				{
					d=j;
					e=a/j;
					count++;
				}
			}
			if(count==0)
			{
				if(a%j==0)
				{
					b=j;
					c=a/j;
					count++;
				}
			}
		}
		printf("Case #%d: %d = %d * %d = %d * %d\n",i,a,b,c,d,e);
	}
	return 0;
}
