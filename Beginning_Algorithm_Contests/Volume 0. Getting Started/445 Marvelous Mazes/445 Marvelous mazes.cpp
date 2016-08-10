/*

Marvelous Mazes 

Your mission, if you decide to accept it, is to create a maze drawing program. A maze will consist of the alphabetic characters A-Z, * (asterisk), and spaces.

Input and Output

Your program will get the information for the mazes from the input file. This file will contain lines of characters which your program must interpret to draw a maze. Each row of the maze will be described by a series of numbers and characters, where the numbers before a character tell how many times that character will be used. If there are multiple digits in a number before a character, then the number of times to repeat the character is the sum of the digits before that character.

The lowercase letter "b" will be used in the input file to represent spaces in the maze. The descriptions for different rows in the maze will be separated by an exclamation point (!) or by an end of line.

Descriptions for different mazes will be separated by a blank line in both input and output. The input file will be terminated by an end of file.

There is no limit to the number of rows in a maze or the number of mazes in a file, though no row will contain more than 132 characters.

Happy mazing!

Sample Input

1T1b5T!1T2b1T1b2T!1T1b1T2b2T!1T3b1T1b1T!3T3b1T!1T3b1T1b1T!5T1*1T
 
11X21b1X
4X1b1X
Sample Output

T TTTTT
T  T TT
T T  TT
T   T T
TTT   T
T   T T
TTTTT*T
 
XX   X
XXXX X
*/


#include<iostream>
#include<ctype.h>
#include<stdio.h>
using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int a=0,i;
	char c;
	while((c=getchar())!=EOF)
	{
		if(isdigit(c))
			a+=(c-'0');
		if(c=='b')
		{
			for(i=0;i<a;i++)
				putchar(' ');
			a=0;
		}
		if(c=='*')
		{
			for(i=0;i<a;i++)
				putchar(c);
			a=0;
		}
		if(isupper(c))
		{
			for(i=0;i<a;i++)
				putchar(c);
			a=0;
		}
		if(c=='!')
			putchar('\n');
		if(c=='\n')
			putchar(c);
	}
	return 0;
}
