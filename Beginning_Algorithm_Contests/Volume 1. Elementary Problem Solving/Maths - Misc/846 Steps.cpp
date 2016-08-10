/*Steps 
One steps through integer points of the straight line. The length of a step must be nonnegative and can be by one bigger than, equal to, or by one smaller than the length of the previous step.

What is the minimum number of steps in order to get from x to y? The length of the first and the last step must be 1.

Input and Output 

Input consists of a line containing n, the number of test cases. For each test case, a line follows with two integers: 0<x<=y < 2^31. For each test case, print a line giving the minimum number of steps to get from x to y.
Sample Input 

3
45 48
45 49
45 50
Sample Output 

3
3
4
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long a,b,p=1;
//	int a,b,p=1;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		if(a==b) p=0;
		if(p)
		{
			p=floor(sqrt(b-a)+1e-9);
			//cout<<p<<endl;
			if(p*p==b-a)
				p=p*2-1;
			else
			{
				if((p*p+p)>=b-a)
					p*=2;
				else
					p=p*2+1;
			}
		}
		cout<<p<<endl;;
	}
	return 0;
}
