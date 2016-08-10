/*
Problem F: Factoring Large Numbers

One of the central ideas behind much cryptography is that factoring large numbers is computationally intensive. In this context one might use a 100 digit number that was a product of two 50 digit prime numbers. Even with the fastest projected computers this factorization will take hundreds of years.

You don't have those computers available, but if you are clever you can still factor fairly large numbers.


Input

The input will be a sequence of integer values, one per line, terminated by a negative number. The numbers will fit in gcc's long long int datatype. You may assume that there will be at most one factor more than 1000000.

Output

Each positive number from the input must be factored and all factors (other than 1) printed out. The factors must be printed in ascending order with 4 leading spaces preceding a left justified number, and followed by a single blank line.

Sample Input

90
1234567891
18991325453139
12745267386521023
-1
Sample Output

    2
    3
    3
    5

    1234567891

    3
    3
    13
    179
    271
    1381
    2423

    30971
    411522630413
	*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int is_prime(long long n);
int main()
{
	long long a,i,j;
	while(cin>>a)
	{
		if(a<0) break;
		j=floor(sqrt(a)+1e-9);
		while(1)
		{
			if(a==1) break;
			if(is_prime(a))
			{
				cout<<"    "<<a<<endl;
				break;
			}
			else
			{
				for(i=2;i<=j;i++)
				{
					while(a%i==0)
					{
						a/=i;
						j=floor(sqrt(a)+1e-9);
						cout<<"    "<<i<<endl;
					}
				}
			}
		}
		putchar('\n');
	}
	return 0;
}




int is_prime(long long n)
{
	long long i;
	int ok=1;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
			ok=0;
	}
	return ok;
}