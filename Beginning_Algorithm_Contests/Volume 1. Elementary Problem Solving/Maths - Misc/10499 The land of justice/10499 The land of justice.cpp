/*The Land of Justice
Input: standard input
Output: standard output
Time Limit: 4 seconds

In the Land of Justice the selling price of everything is fixed all over the country. Nobody can buy a thing and sell it in double price. But, that created problems for the businessmen. They left their business and went to the production. So, after some days everybody was in production and nobody in business. And the people didn¡¯t get their necessary things though the country was self-sufficient in every sector.
 
The government became very much anxious. But, they were intelligent enough to call the mathematicians.
 
The mathematicians gave a solution.  They suggested setting the surface area of an object as its selling-unit instead of its volume. Actually the clever mathematicians were very much interested to establish their own business.
 
Now, the government asks the programmers to build the software that would calculate the profit things.
 
Here your job is to calculate the business profit for a solid sphere. A businessman buys a complete sphere and to maximize his profit he divides it in n equal parts. All cut should go through the axis of the sphere. And every part should look like the picture below:


 
Input
You are given a sequence of integers N (0 < N < 231), indicating the numbers of parts of the sphere. The input file is terminated with a negative number. This number should not be processed.
 
Output
Calculate the profit over the sold pieces. The result should be in percentage and rounded to the nearest integer.
  
Sample input
2
2
-1
 
Sample output
50%
50%

*/

#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	//int n;
	long long n;
	while(cin>>n)
	{
		if(n<0) break;
		if(n==1) n=0;
		cout<<25*n;
		putchar('%');
		putchar('\n');
	}
	return 0;
}