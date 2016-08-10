/*Overflow 

Write a program that reads an expression consisting of two non-negative integer and an operator. Determine if either integer or the result of the expression is too large to be represented as a ``normal'' signed integer (type integer if you are working Pascal, type int if you are working in C).

Input

An unspecified number of lines. Each line will contain an integer, one of the two operators + or *, and another integer.

Output

For each line of input, print the input followed by 0-3 lines containing as many of these three messages as are appropriate: ``first number too big'', ``second number too big'', ``result too big''.

Sample Input

300 + 3
9999999999999999999999 + 11
Sample Output

300 + 3
9999999999999999999999 + 11
first number too big
result too big
*/


#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define M 500
using namespace std;
void jiafa(char a[],char b[]);
void p(char e[],char c[],char t);
void chengfa(char sum[],char a[],char b[]);
void chu1(char a[]);
void chu2(char a[]);
void chu3(char a[]);
void fa(char a[],int n);
int bi(char a[],char b[]);
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	char a[M],b[M],s[M],o,yi[M];
	int q=pow(2,31)-1;
	sprintf(yi,"%d",q);
//	puts(yi);
	while(scanf("%s %c %s",a,&o,b)==3)
	{
		for(int i=0;i<M;i++)
			s[i]='0';
		printf("%s %c %s\n",a,o,b);
		chu3(a);
		chu3(b);
	//	puts(a);
		if(bi(a,yi)>0&&bi(b,yi)>0)
		{
			cout<<"first number too big"<<endl;
			cout<<"second number too big"<<endl;
			cout<<"result too big"<<endl;
			continue;
		}
		if(bi(a,yi)>0)
		{
			cout<<"first number too big"<<endl;
			if(b[0]!='0'||o=='+')
				cout<<"result too big"<<endl;
			continue;
		}
		if(bi(b,yi)>0)
		{
			cout<<"second number too big"<<endl;
			if(a[0]!='0'||o=='+')
				cout<<"result too big"<<endl;
			continue;
		}
		chu1(a);
		chu1(b);
		if(o=='+')
		{
			jiafa(a,b);
			chu2(b);
			if(bi(b,yi)>0)
				cout<<"result too big"<<endl;
			continue;
		}
		//putchar(o);
		if(o=='*')
		{
		//	putchar(o);
			chengfa(s,a,b);
		//	putchar(o);
			chu2(s);
		//	putchar(o);
			if(bi(s,yi)>0)
				cout<<"result too big"<<endl;
			continue;
		}
	}
	return 0;
}


void jiafa(char a[],char b[])//加法,b存结果，已经过处理
{
	int f=0,i;
	char t;
	for(i=0;i<M;i++)
	{
		t=b[i];
		b[i]=((b[i]-'0')+(a[i]-'0')+f)%10+'0';
		f=((t-'0')+(a[i]-'0')+f)/10;
	}
}


void p(char e[],char c[],char t)//乘法初步，已经过处理
{
	int a=t-'0';
	int i,f=0,w;
	for(i=0;i<M;i++)
	{
		w=c[i]-'0';
		e[i]=((c[i]-'0')*a+f)%10+'0';
		f=(w*a+f)/10;
	}
}


void fa(char a[],int n)//乘法需要用的
{
	 int i;
	 for(i=M-1;i>=n;i--)
		 a[i]=a[i-n];
	 for(i=0;i<n;i++)
		 a[i]='0';
}


void chengfa(char sum[],char a[],char b[])//乘法，sum存结果，已经过处理
{
	int i,j;
	char e[M];
	for(i=0;i<M;i++)
		e[i]='0';
//	putchar('1');
	for(j=0;j<M;j++)
	{
		p(e,a,b[j]);
		fa(e,j);
		jiafa(e,sum);
		for(i=0;i<M;i++)			
			e[i]='0';		
	}
//	putchar('1');
}



int bi(char a[],char b[])//a大，返回值大于0；b大，返回值小于0；相等返回值等于0，给的参数是字符串，未经过处理
{
	if(strlen(a)>strlen(b))
		return 1;
	if(strlen(a)<strlen(b))
		return -1;
	return strcmp(a,b);
}



void chu1(char a[])//处理成可加乘
{
	int i;
	char t;
	for(i=0;i<strlen(a)/2;i++)
	{
		t=a[strlen(a)-i-1];
		a[strlen(a)-i-1]=a[i];
		a[i]=t;
	}
	for(i=strlen(a);i<M;i++)
		a[i]='0';
}



void chu2(char a[])//处理成字符串,可比较
{
	int i;
	char t;
	for(i=M-1;i>=0;i--)
		if(a[i]!='0') break;
	if(i==-1)
	{
		a[0]='0';
		a[1]='\0';
	}
	else
		a[i+1]='\0';
	for(i=0;i<strlen(a)/2;i++)
	{
		t=a[strlen(a)-i-1];
		a[strlen(a)-i-1]=a[i];
		a[i]=t;
	}
}


void chu3(char a[])//把输入的0003变为3
{
	int i;
	while(a[0]=='0')
	{
		for(i=1;i<=strlen(a);i++)
			a[i-1]=a[i];
	}
	if(a[0]=='\0')
	{
		a[0]='0';
		a[1]='\0';
	}
}