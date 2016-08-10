/*
Skew Binary 
When a number is expressed in decimal, the k-th digit represents a multiple of 10k. (Digits are numbered from right to left, where the least significant digit is number 0.) For example, 



When a number is expressed in binary, the k-th digit represents a multiple of 2k. For example, 



In skew binary, the k-th digit represents a multiple of 2k+1 - 1. The only possible digits are 0 and 1, except that the least-significant nonzero digit can be a 2. For example, 



The first 10 numbers in skew binary are 0, 1, 2, 10, 11, 12, 20, 100, 101, and 102. (Skew binary is useful in some applications because it is possible to add 1 with at most one carry. However, this has nothing to do with the current problem.)

Input 

The input file contains one or more lines, each of which contains an integer n. If n = 0 it signals the end of the input, and otherwise n is a nonnegative integer in skew binary.
Output 

For each number, output the decimal equivalent. The decimal value of n will be at most 231 - 1 = 2147483647.
Sample Input 

10120
200000000000000000000000000000
10
1000000000000000000000000000000
11
100
11111000001110000101101102000
0
Sample Output 

44
2147483646
3
2147483647
4
7
1041110737
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
	char c[100];
	while(gets(c))
	{
		int sum=0;
		if(c[0]=='0')
			break;
		for(int i=strlen(c);i>=1;i--)
		{
			sum+=((c[strlen(c)-i]-'0')*(pow(2,i)-1));
		}
		cout<<sum<<endl;
	}
	return 0;
}
