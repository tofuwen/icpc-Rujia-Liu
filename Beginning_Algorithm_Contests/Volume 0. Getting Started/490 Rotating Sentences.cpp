/*
Rotating Sentences 

In ``Rotating Sentences,'' you are asked to rotate a series of input sentences 90 degrees clockwise. 
So instead of displaying the input sentences from left to right and top to bottom, your program will display them from top to bottom and right to left.

Input and Output

As input to your program, you will be given a maximum of 100 sentences, each not exceeding 100 characters long. 
Legal characters include: newline, space, any punctuation characters, digits, and lower case or upper case English letters. (NOTE: Tabs are not legal characters.)

The output of the program should have the last sentence printed out vertically in the leftmost column; 
the first sentence of the input would subsequently end up at the rightmost column.

Sample Input

Rene Decartes once said,
"I think, therefore I am."


Sample Output

"R
Ie
 n
te
h 
iD
ne
kc
,a
 r
tt
he
es
r
eo
fn
oc
re
e
 s
Ia
 i
ad
m,
.
"

  */



#include<stdio.h>
#include<string.h>
char c[105][105],d[105][105];
int main()
{
	int n=0,max=0,i,j,a[105];
	while(gets(c[n]))
	{
		a[n]=strlen(c[n]);
		if(a[n]>max)
			max=a[n];
		n++;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<a[n-1-i];j++)
			d[j][i]=c[n-1-i][j];
		for(j=a[n-1-i];j<max;j++)
			d[j][i]=' ';
	}
	for(i=0;i<max;i++)
		d[i][n]='\0';
	for(i=0;i<max;i++)
		puts(d[i]);
	return 0;
}