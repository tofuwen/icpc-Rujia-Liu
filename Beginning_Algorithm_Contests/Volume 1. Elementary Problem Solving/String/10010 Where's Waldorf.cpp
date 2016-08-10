
/*Where's Waldorf? 
Given a m by n grid of letters, ( 1<=m,n<=50 ), and a list of words, find the location in the grid at which the word can be found. 
A word matches a straight, uninterrupted line of letters in the grid. A word can match the letters in the grid regardless of case
 (i.e. upper and lower case letters are to be treated as the same). The matching can be done in any of the eight directions either horizontally, 
 vertically or diagonally through the grid.
Input 

The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. 
This line is followed by a blank line, and there is also a blank line between two consecutive inputs.
The input begins with a pair of integers, m followed by n,   in decimal notation on a single line. The next m lines contain n letters each; 
this is the grid of letters in which the words of the list must be found. The letters in the grid may be in upper or lower case. Following the grid of letters, 
another integer k appears on a line by itself (  ). The next k lines of input contain the list of words to search for, one word per line.
 These words may contain upper and lower case letters only (no spaces, hyphens or other non-alphabetic characters).

Output 

For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line.
For each word in the word list, a pair of integers representing the location of the corresponding word in the grid must be output. 
The integers must be separated by a single space. The first integer is the line in the grid where the first letter of the given word can be found (1 represents the topmost line in the grid, and m represents the bottommost line). The second integer is the column in the grid where the first letter of the given word can be found (1 represents the leftmost column in the grid, and n represents the rightmost column in the grid). If a word can be found more than once in the grid, then the location which is output should correspond to the uppermost occurence of the word (i.e. the occurence which places the first letter of the word closest to the top of the grid). If two or more words are uppermost, the output should correspond to the leftmost of these occurences. All words can be found at least once in the grid.

Sample Input 

1

8 11
abcDEFGhigg
hEbkWalDork
FtyAwaldORm
FtsimrLqsrc
byoArBeDeyv
Klcbqwikomk
strEBGadhrb
yUiqlxcnBjf
4
Waldorf
Bambi
Betty
Dagbert
Sample Output 

2 5
2 3
1 2
7 8
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
char c[55][55];
char d[55],e[55];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n;
	cin>>n;
	int i,j,p,q,y;
	int m;
	for(i=0;i<n;i++)
	{
		int a,b,z;
		cin>>a>>b;
		getchar();
		for(p=0;p<a;p++)
			gets(c[p]);
		for(p=0;p<a;p++)
		{
			for(q=0;q<b;q++)
			{
				if(isupper(c[p][q]))
					c[p][q]=c[p][q]+('a'-'A');
			}
		}
		cin>>z;
		getchar();
		for(j=0;j<z;j++)
		{
			int ok=0;
			gets(d);
			m=strlen(d);
			for(p=0;p<m;p++)
			{
				if(isupper(d[p]))
					d[p]=d[p]+('a'-'A');
			}
			for(p=0;p<a;p++)
			{
				for(q=0;q<b;q++)
				{
					if(q<=b-m)
					{
						for(y=0;y<m;y++)
							e[y]=c[p][q+y];
						e[m]='\0';
						if(strcmp(e,d)==0)
						{
							printf("%d %d\n",p+1,q+1);
							ok=1;
							break;
						}
					}
					if(q>=m-1)
					{
						for(y=0;y<m;y++)
							e[y]=c[p][q-y];
						e[m]='\0';
						if(strcmp(e,d)==0)
						{
							printf("%d %d\n",p+1,q+1);
							ok=1;
							break;
						}
					}
					if(p<=a-m)
					{
						for(y=0;y<m;y++)
							e[y]=c[p+y][q];
						e[m]='\0';
						if(strcmp(e,d)==0)
						{
							printf("%d %d\n",p+1,q+1);
							ok=1;
							break;
						}
					}
					if(p>=m-1)
					{
						for(y=0;y<m;y++)
							e[y]=c[p-y][q];
						e[m]='\0';
						if(strcmp(e,d)==0)
						{
							printf("%d %d\n",p+1,q+1);
							ok=1;
							break;
						}
					}
					if(q<=b-m&&p<=a-m)
					{
						for(y=0;y<m;y++)
							e[y]=c[p+y][q+y];
						e[m]='\0';
						if(strcmp(e,d)==0)
						{
							printf("%d %d\n",p+1,q+1);
							ok=1;
							break;
						}
					}
					if(q<=b-m&&p>=m-1)
					{
						for(y=0;y<m;y++)
							e[y]=c[p-y][q+y];
						e[m]='\0';
						if(strcmp(e,d)==0)
						{
							printf("%d %d\n",p+1,q+1);
							ok=1;
							break;
						}
					}
					if(q>=m-1&&p>=m-1)
					{
						for(y=0;y<m;y++)
							e[y]=c[p-y][q-y];
						e[m]='\0';
						if(strcmp(e,d)==0)
						{
							printf("%d %d\n",p+1,q+1);
							ok=1;
							break;
						}
					}
					if(q>=m-1&&p<=a-m)
					{
						for(y=0;y<m;y++)
							e[y]=c[p+y][q-y];
						e[m]='\0';
						if(strcmp(e,d)==0)
						{
							printf("%d %d\n",p+1,q+1);
							ok=1;
							break;
						}
					}
				}
				if(ok)
					break;
			}
		}
		if(i!=n-1)
			putchar('\n');
	}
	return 0;
}