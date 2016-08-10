/*
Integer Inquiry 

One of the first users of BIT's new supercomputer was Chip Diller. He extended his exploration of powers of 3 to go from 0 to 333 and he explored taking various sums of those numbers.

``This supercomputer is great,'' remarked Chip. ``I only wish Timothy were here to see these results.'' (Chip moved to a new apartment, once one became available on the third floor of the Lemon Sky apartments on Third Street.)

Input

The input will consist of at most 100 lines of text, each of which contains a single VeryLongInteger. Each VeryLongInteger will be 100 or fewer characters in length, and will only contain digits (no VeryLongInteger will be negative).

The final input line will contain a single zero on a line by itself.

Output

Your program should output the sum of the VeryLongIntegers given in the input.

Sample Input

123456789012345678901234567890
123456789012345678901234567890
123456789012345678901234567890
0
Sample Output

370370367037037036703703703670
*/

#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	char sum[110],t;
	int i,j,f=0;
	for(i=0;i<110;i++)
		sum[i]='0';
	char a[110];
	while(gets(a))
	{
		if(a[0]=='0') break;
		for(i=0;i<strlen(a)/2;i++)
		{
			t=a[i];
			a[i]=a[strlen(a)-i-1];
			a[strlen(a)-i-1]=t;
		}
		for(i=strlen(a);i<110;i++)
			a[i]='0';
		for(i=0;i<110;i++)
		{
			t=sum[i];
			sum[i]=((sum[i]-'0')+(a[i]-'0')+f)%10+'0';
			f=((t-'0')+(a[i]-'0')+f)/10;
		}
	}
	for(i=109;i>=0;i--)
		if(sum[i]!='0') break;
	for(j=i;j>=0;j--)
		putchar(sum[j]);
	putchar('\n');
	return 0;
}