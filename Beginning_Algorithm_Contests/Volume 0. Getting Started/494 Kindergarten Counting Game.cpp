/*
Kindergarten Counting Game 

Everybody sit down in a circle. Ok. Listen to me carefully.

``Woooooo, you scwewy wabbit!''

Now, could someone tell me how many words I just said?

Input and Output

Input to your program will consist of a series of lines, each line containing multiple words (at least one).
 A ``word'' is defined as a consecutive sequence of letters (upper and/or lower case).

Your program should output a word count for each line of input. Each word count should be printed on a separate line.

Sample Input

Meep Meep!
I tot I taw a putty tat.
I did! I did! I did taw a putty tat.
Shsssssssssh ... I am hunting wabbits. Heh Heh Heh Heh ...
Sample Output

2
7
10
9

  */

#include<stdio.h>
#include<ctype.h>
int main()
{
	char c=NULL,d=NULL;
	int n=0;
	while((d=getchar())!=EOF)
	{
		if(isalpha(c)&&!isalpha(d))
			n++;
		if(d=='\n')
		{
			c=NULL;
			printf("%d\n",n);
			n=0;
		}
		c=d;
	}
	return 0;
}