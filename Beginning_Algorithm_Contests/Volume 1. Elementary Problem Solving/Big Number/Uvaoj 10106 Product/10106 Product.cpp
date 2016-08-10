/*Product 

The Problem

The problem is to multiply two integers X, Y. (0<=X,Y<10^250)

The Input

The input will consist of a set of pairs of lines. Each line in pair contains one multiplyer.

The Output

For each input pair of lines the output line should consist one integer the product.

Sample Input

12
12
2
222222222222222222222222
Sample Output

144
444444444444444444444444
*/


#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
void papapa(char a[],char b[]);
void fa(char a[],int n);
void p(char e[],char c[],char t);
int main()
{
	char c[520],d[520],sum[520],t,e[520];
	int i,j;
	while(gets(c))
	{
		gets(d);
		int f=0;
		for(i=0;i<520;i++)
		{
			sum[i]='0';
			e[i]='0';
		}
		for(i=0;i<strlen(c)/2;i++)
		{
			t=c[i];
			c[i]=c[strlen(c)-i-1];
			c[strlen(c)-i-1]=t;
		}
		for(i=strlen(c);i<520;i++)
			c[i]='0';
		for(i=0;i<strlen(d)/2;i++)
		{
			t=d[i];
			d[i]=d[strlen(d)-i-1];
			d[strlen(d)-i-1]=t;
		}
		for(i=strlen(d);i<520;i++)
			d[i]='0';
		for(j=0;j<520;j++)
		{
			p(e,c,d[j]);
			fa(e,j);
			papapa(e,sum);
			for(i=0;i<520;i++)			
				e[i]='0';		
		}
		for(j=519;j>=0;j--)
			if(sum[j]!='0') break;
		if(j==-1)
			putchar('0');
		for(i=j;i>=0;i--)
			putchar(sum[i]);
		putchar('\n');
	}
	return 0;
}








void papapa(char a[],char b[])
{
	int f=0,i;
	char t;
	for(i=0;i<520;i++)
	{
		t=b[i];
		b[i]=((b[i]-'0')+(a[i]-'0')+f)%10+'0';
		f=((t-'0')+(a[i]-'0')+f)/10;
	}
}



void fa(char a[],int n)
{
	 int i;
	 for(i=519;i>=n;i--)
		 a[i]=a[i-n];
	 for(i=0;i<n;i++)
		 a[i]='0';
}


void p(char e[],char c[],char t)
{
	int a=t-'0';
	int i,f=0,w;
	for(i=0;i<520;i++)
	{
		w=c[i]-'0';
		e[i]=((c[i]-'0')*a+f)%10+'0';
		f=(w*a+f)/10;
	}
}