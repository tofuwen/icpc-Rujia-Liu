/*
Just the Facts 
The expression N!, read as ``N factorial," denotes the product of the first N positive integers, where N is nonnegative. So, for example,
N	N!
0	 1
1	 1
2	 2
3	 6
4	 24
5	 120
10	 3628800
For this problem, you are to write a program that can compute the last non-zero digit of any factorial for ( ). 
For example, if your program is asked to compute the last nonzero digit of 5!, your program should produce ``2" because 5! = 120,
 and 2 is the last nonzero digit of 120.

Input 

Input to the program is a series of nonnegative integers not exceeding 10000, each on its own line with no other letters, digits or spaces. 
For each integer N, you should read the value and compute the last nonzero digit of N!.

  Output 

For each integer input, the program should print exactly one line of output.
 Each line of output should contain the value N, right-justified in columns 1 through 5 with leading blanks, not leading zeroes. 
 Columns 6 - 9 must contain `` -> " (space hyphen greater space). Column 10 must contain the single last non-zero digit of N!.
Sample Input 

1
2
26
125
3125
9999
Sample Output 

    1 -> 1
    2 -> 2
   26 -> 4
  125 -> 8
 3125 -> 2
 9999 -> 8
 */

#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int n;
	int a=1;
	int i,j;
	while(cin>>n)
	{
		for(j=1;j<=n;j++)
		{
			i=j;
			while(i%10==0)
				i/=10;
			if(i%5!=0)
				a=((i%10)*a)%10;
			else
			{
				if(i%3125==0)
				{
					if(a==2){a=(6*((i/3125)%10))%10;continue;}
					if(a==4){a=(2*((i/3125)%10))%10;continue;}
					if(a==6){a=(8*((i/3125)%10))%10;continue;}
					if(a==8){a=(4*((i/3125)%10))%10;continue;}
				}
				else
				{
					if(i%625==0)
					{
						if(a==2){a=(2*(i/625))%10;continue;}
						if(a==4){a=(4*(i/625))%10;continue;}
						if(a==6){a=(6*(i/625))%10;continue;}
						if(a==8){a=(8*(i/625))%10;continue;}
					}
					else
					{
						if(i%125==0)
						{
							if(a==2){a=(4*((i/125)%10))%10;continue;}
							if(a==4){a=(8*((i/125)%10))%10;continue;}
							if(a==6){a=(2*((i/125)%10))%10;continue;}
							if(a==8){a=(6*((i/125)%10))%10;continue;}
						}
						else
						{
							if(i%25==0)
							{
								if(a==2){a=(8*((i/25)%10))%10;continue;}
								if(a==4){a=(6*((i/25)%10))%10;continue;}
								if(a==6){a=(4*((i/25)%10))%10;continue;}
								if(a==8){a=(2*((i/25)%10))%10;continue;}
							}
							else
							{
								if(a==2){a=(6*((i/5)%10))%10;continue;}
								if(a==4){a=(2*((i/5)%10))%10;continue;}
								if(a==6){a=(8*((i/5)%10))%10;continue;}
								if(a==8){a=(4*((i/5)%10))%10;continue;}
							}
						}
					}
				}
			}
		}
		printf("%5d -> %d\n",n,a);
		a=1;
	}
	return 0;
}




























