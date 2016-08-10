/*

Triangle Wave 
In this problem you are to generate a triangular wave form according to a specified pair of Amplitude and Frequency.

Input and Output

The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs.

Each input set will contain two integers, each on a separate line. The first integer is the Amplitude; the second integer is the Frequency.

For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line.

For the output of your program, you will be printing wave forms each separated by a blank line. The total number of wave forms equals the Frequency, and the horizontal ``height'' of each wave equals the Amplitude. The Amplitude will never be greater than nine.

The waveform itself should be filled with integers on each line which indicate the ``height'' of that line.

NOTE: There is a blank line after each separate waveform, excluding the last one.

Sample Input

1

3
2
Sample Output

1
22
333
22
1

1
22
333
22
1
*/


#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n,i,j,q,p;
	int a,f;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a>>f;
		for(j=0;j<f;j++)
		{
			for(q=1;q<=a;q++)
			{
				for(p=0;p<q;p++)
					cout<<q;
				putchar('\n');
			}
			for(q=a-1;q>=1;q--)
			{
				for(p=0;p<q;p++)
					cout<<q;
				putchar('\n');
			}
			if(j!=f-1||i!=n-1)
				putchar('\n');
		}
	}
	return 0;
}