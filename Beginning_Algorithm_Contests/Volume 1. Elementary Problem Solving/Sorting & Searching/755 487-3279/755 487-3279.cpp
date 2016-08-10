/*487-3279 
Businesses like to have memorable telephone numbers. One way to make a telephone number memorable is to have it spell a memorable word or phrase. For example, you can call the University of Waterloo by dialing the memorable TUT-GLOP. Sometimes only part of the number is used to spell a word. When you get back to your hotel tonight you can order a pizza from Gino's by dialing 310-GINO. Another way to make a telephone number memorable is to group the digits in a memorable way. You could order your pizza from Pizza Hut by calling their ``three tens'' number 3-10-10-10.


The standard form of a telephone number is seven decimal digits with a hyphen between the third and fourth digits (e.g. 888-1200). The keypad of a phone supplies the mapping of letters to numbers, as follows:


A, B, and C map to 2

D, E, and F map to 3

G, H, and I map to 4

J, K, and L map to 5

M, N, and O map to 6

P, R, and S map to 7

T, U, and V map to 8

W, X, and Y map to 9


There is no mapping for Q or Z. Hyphens are not dialed, and can be added and removed as necessary. The standard form of TUT-GLOP is 888-4567, the standard form of 310-GINO is 310-4466, and the standard form of 3-10-10-10 is 310-1010.


Two telephone numbers are equivalent if they have the same standard form. (They dial the same number.)


Your company is compiling a directory of telephone numbers from local businesses. As part of the quality control process you want to check that no two (or more) businesses in the directory have the same telephone number.

Input 

The first line of the input contains the number of datasets in the input. A blank line follows. The first line of each dataset specifies the number of telephone numbers in the directory (up to 100,000) as a positive integer alone on the line. The remaining lines list the telephone numbers in the directory, with each number alone on a line. Each telephone number consists of a string composed of decimal digits, uppercase letters (excluding Q and Z) and hyphens. Exactly seven of the characters in the string will be digits or letters. There's a blank line between datasets.
Output 

Generate a line of output for each telephone number that appears more than once in any form. The line should give the telephone number in standard form, followed by a space, followed by the number of times the telephone number appears in the directory. Arrange the output lines by telephone number in ascending lexicographical order. If there are no duplicates in the input print the line:
No duplicates.
Print a blank line between datasets.

Sample Input 

1

12
4873279
ITS-EASY
888-4567
3-10-10-10
888-GLOP
TUT-GLOP
967-11-11
310-GINO
F101010
888-1200
-4-8-7-3-2-7-9-
487-3279
Sample Output 

310-1010 2
487-3279 4
888-4567 3


  */




#include<iostream>
#include<cstdio>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
using namespace std;

int cmp_string(const void *_a,const void *_b)
{
	char *a=(char*)_a;
	char *b=(char*)_b;
	return strcmp(a,b);
}




#define MAX 100000
char a[MAX][15];
//int m[MAX];
void f(char c[],char d[]);
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int cases;
	cin>>cases;
	for(int geshu=0;geshu<cases;geshu++)
	{
		int i,n;
		cin>>n;
		getchar();
	//	for(i=0;i<n;i++)
	//	{
	//		a[i][9]='0';
	//		a[i][0]='0';
	//		a[i][1]='\0';
	//	}
		char c[210],d[15];
		for(i=0;i<n;i++)
		{
	//		int ok=1;
			gets(c);
			f(c,d);
			strcpy(a[i],d);
		}
		//	for(j=0;j<number;j++)
		//	{
		//		if(strcmp(a[j],d)>0) break;
		//		if(strcmp(a[j],d)==0)
		//		{
		//			a[j][9]++;
		//			ok=0;
		//			break;
		//		}
		//	}
		//	if(ok)
		//	{
		//		a[number][9]++;
		//		strcpy(a[number++],d);
		//		qsort(a,number,sizeof(a[0]),cmp_string);
		//	}
	//	}
		qsort(a,n,sizeof(a[0]),cmp_string);
		int ok=1;
		i=0;
//		if(n>1)
//		{
			while(i<n-1)
			{
				int number=1;
				while(strcmp(a[i],a[i+1])==0)
				{
					number++;
					i++;
				}
				if(number!=1)
				{
				//	puts(a[i]);
				//	cout<<number<<endl;
					printf("%s %d\n",a[i],number);
					ok=0;
				}
				i++;
			}
	//	}
		if(ok)
			printf("No duplicates.\n");
	//	for(i=0;i<number;i++)
	//	{
	//		if(a[i][9]-'0'>max)
	//			max=a[i][9]-'0';
		//	a[i][8]=' ';
		//	a[i][9]=m[i]+'0';
		//	a[i][10]='\0';
		//	for(j=i+1;j<number;j++)
		//	{
		//		if(strcmp(a[i],a[j])>0)
		//		{
		//			strcpy(d,a[i]);
		//			strcpy(a[i],a[j]);
		//			strcpy(a[j],d);
		//			t=m[i];
		//			m[i]=m[j];
		//			m[j]=t;
		//		}
		//	}
	//	}
	//	qsort(a,number,sizeof(a[0]),cmp_string);
	//	if(max>1)
	//	{
	//		for(i=0;i<number;i++)
	//		{
	//			if(a[i][9]!='1')
	//			{
	//				puts(a[i]);
					//putchar(a[i][9]);
		//		}
		//	}
	//	}
	//	else
	//		cout<<"No duplicates."<<endl;
		if(geshu!=cases-1)
			putchar('\n');
	}
	return 0;
}


void f(char c[],char d[])
{
	char z[60]="ABCDEFGHIJKLMNOPRSTUVWXY222333444555666777888999";
	int i,j,count=0;
	for(i=0;i<strlen(c);i++)
	{
		if(isupper(c[i]))
		{
			for(j=0;c[i]!=z[j]&&z[j];j++);
			d[count++]=z[j+24];
			if(count==3)
				d[count++]='-';
		}
		else
		{
			if(isdigit(c[i]))
			{
				d[count++]=c[i];
				if(count==3)
					d[count++]='-';
			}
		}
	}
	d[count]='\0';
}