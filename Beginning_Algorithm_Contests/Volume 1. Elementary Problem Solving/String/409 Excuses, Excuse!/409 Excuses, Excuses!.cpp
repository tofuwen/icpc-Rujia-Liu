/*Excuses, Excuses! 

Judge Ito is having a problem with people subpoenaed for jury duty giving rather lame excuses in order to avoid serving. 
In order to reduce the amount of time required listening to goofy excuses,
 Judge Ito has asked that you write a program that will search for a list of keywords in a list of excuses identifying lame excuses. 
 Keywords can be matched in an excuse regardless of case.

Input

Input to your program will consist of multiple sets of data.

Line 1 of each set will contain exactly two integers.
The first number (  ) defines the number of keywords to be used in the search. 
The second number (  ) defines the number of excuses in the set to be searched.
Lines 2 through K+1 each contain exactly one keyword.
Lines K+2 through K+1+E each contain exactly one excuse.
All keywords in the keyword list will contain only contiguous lower case alphabetic characters of length L (  ) and will occupy columns 1 through L in the input line.
All excuses can contain any upper or lower case alphanumeric character, a space, or any of the following punctuation marks [SPMamp".,!?&] 
not including the square brackets and will not exceed 70 characters in length.
Excuses will contain at least 1 non-space character.

  Output

For each input set, you are to print the worst excuse(s) from the list.

The worst excuse(s) is/are defined as the excuse(s) which contains the largest number of incidences of keywords.
If a keyword occurs more than once in an excuse, each occurrance is considered a separate incidence.
A keyword ``occurs" in an excuse if and only if it exists in the string in contiguous form and is delimited by the beginning or end of the line or any non-alphabetic character or a space.
For each set of input, you are to print a single line with the number of the set immediately after the string ``Excuse Set #". (See the Sample Output). The following line(s) is/are to contain the worst excuse(s) one per line exactly as read in. If there is more than one worst excuse, you may print them in any order.

After each set of output, you should print a blank line.

Sample Input

5 3
dog
ate
homework
canary
died
My dog ate my homework.
Can you believe my dog died after eating my canary... AND MY HOMEWORK?
This excuse is so good that it contain 0 keywords.
6 5
superhighway
crazy
thermonuclear
bedroom
war
building
I am having a superhighway built in my bedroom.
I am actually crazy.
1234567890.....,,,,,0987654321?????!!!!!!
There was a thermonuclear war!
I ate my dog, my canary, and my homework ... note outdated keywords?
Sample Output

Excuse Set #1
Can you believe my dog died after eating my canary... AND MY HOMEWORK?

Excuse Set #2
I am having a superhighway built in my bedroom.
There was a thermonuclear war!
*/

#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
using namespace std;
int f(char d[],char key[][25],int k);
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	char key[25][25],c[25][75],d[25][75],p[75];
	int k,e;
	int i,j;
	int number[25];
	int step=1;
	while(cin>>k>>e)
	{
		getchar();
		int max=0;
		for(i=0;i<k;i++)
			gets(key[i]);
		for(i=0;i<e;i++)
			gets(c[i]);
//		printf("sishi");
		for(i=0;i<e;i++)
		{
			for(j=0;j<75;j++)
			{
				if(c[i][j]>='A'&&c[i][j]<='Z')
					d[i][j]=c[i][j]+('a'-'A');
				else
					d[i][j]=c[i][j];
			}
		}
	//	printf("sishi");
		for(i=0;i<e;i++)
		{
			strcpy(p,d[i]);
		//	puts(p);
			number[i]=f(p,key,k);
		}
	//	printf("sishi");
		for(i=0;i<e;i++)
			if(number[i]>max)
				max=number[i];
		printf("Excuse Set #%d\n",step++);
	//	cout<<max<<endl;
		for(i=0;i<e;i++)
		{
			if(number[i]==max)
				puts(c[i]);
			//	puts(d[i]);
			//	cout<<number[i]<<"     "<<i<<endl;
		}
		putchar('\n');
	}
	return 0;
}



int f(char d[],char key[][25],int k)
{
	int number=0;
	char w[75];
	char *p=d,*q=d;
	int j;
	while(1)
	{
		int i=0;
		for(p=q;!isalpha(*p)&&(*p)!='\0';p++);
		for(q=p+1;isalpha(*q)&&(*q)!='\0';q++);
		if((*p)=='\0') break;
		while(p!=q)
		{
			w[i++]=*p;
			p++;
		}
		w[i]='\0';	
		//puts(w);
		//puts("123");
		for(j=0;j<k;j++)
		{
			if(strcmp(w,key[j])==0)
			{
				number++;
				//cout<<number<<endl;
				//printf("%s\n",w);
				break;
			}
		}
		if((*p)=='\0'||(*q)=='\0')
			break;
	}
	return number;
}