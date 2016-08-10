/*
Artificial Intelligence? 
Physics teachers in high school often think that problems given as text are more demanding than pure computations. After all, the pupils have to read and understand the problem first!

So they don't state a problem like ``U=10V, I=5A, P=?" but rather like ``You have an electrical circuit that contains a battery with a voltage of U=10V and a light-bulb. There's an electrical current of I=5A through the bulb. Which power is generated in the bulb?".

However, half of the pupils just don't pay attention to the text anyway. They just extract from the text what is given: U=10V, I=5A. Then they think: ``Which formulae do I know? Ah yes, P=U*I. Therefore P=10V*5A=500W. Finished."

OK, this doesn't always work, so these pupils are usually not the top scorers in physics tests. But at least this simple algorithm is usually good enough to pass the class. (Sad but true.)

Today we will check if a computer can pass a high school physics test. We will concentrate on the P-U-I type problems first. That means, problems in which two of power, voltage and current are given and the third is wanted.


Your job is to write a program that reads such a text problem and solves it according to the simple algorithm given above.

Input 

The first line of the input file will contain the number of test cases.
Each test case will consist of one line containing exactly two data fields and some additional arbitrary words. A data field will be of the form I=xA, U=xV or P=xW, where x is a real number.

Directly before the unit (A, V or W) one of the prefixes m (milli), k (kilo) and M (Mega) may also occur. To summarize it: Data fields adhere to the following grammar:

DataField ::= Concept '=' RealNumber [Prefix] Unit
Concept   ::= 'P' | 'U' | 'I'
Prefix    ::= 'm' | 'k' | 'M'
Unit      ::= 'W' | 'V' | 'A'
Additional assertions:

The equal sign (`=') will never occur in an other context than within a data field.
There is no whitespace (tabs,blanks) inside a data field.
Either P and U, P and I, or U and I will be given.
Output 

For each test case, print three lines:
a line saying ``Problem #k" where k is the number of the test case
a line giving the solution (voltage, power or current, dependent on what was given), written without a prefix and with two decimal places as shown in the sample output
a blank line
Sample Input 

3
If the voltage is U=200V and the current is I=4.5A, which power is generated?
A light-bulb yields P=100W and the voltage is U=220V. Compute the current, please.
bla bla bla lightning strike I=2A bla bla bla P=2.5MW bla bla voltage?
Sample Output 

Problem #1
P=900.00W

Problem #2
I=0.45A

Problem #3
U=1250000.00V
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n;
	int i,j,z;
	char c[200];
	char I[20],U[20],P[20];
	double cu,u,p;
	cin>>n;
	getchar();
	for(int y=1;y<=n;y++)
	{
		int oki=0,oku=0,okp=0;
		gets(c);
		for(i=0;i<strlen(c)&&c[i]!='=';i++);
		for(j=i+1;j<strlen(c)&&c[j]!='=';j++);

		if(c[i-1]=='I')
		{
			oki=1;
			for(z=i+1;c[z]!='A';z++)
				I[z-i-1]=c[z];
			I[z-i-1]='\0';
			if(isdigit(I[z-2-i]))
			{
				sscanf(I,"%lf",&cu);

			 //   cout<<cu<<endl;

			}
			else
			{
				if(I[z-2-i]=='m')
				{
					sscanf(I,"%lfm",&cu);
					cu*=0.001;
				}
				if(I[z-2-i]=='k')
				{
					sscanf(I,"%lfk",&cu);
					cu*=1000;
				}
				if(I[z-2-i]=='M')
				{
					sscanf(I,"%lfM",&cu);
					cu*=1000000;
				}
			}
		}

		if(c[j-1]=='I')
		{
			oki=1;
			for(z=j+1;c[z]!='A';z++)
				I[z-j-1]=c[z];
			I[z-j-1]='\0';
			if(isdigit(I[z-2-j]))
				sscanf(I,"%lf",&cu);
			else
			{
				if(I[z-2-j]=='m')
				{
					sscanf(I,"%lfm",&cu);
					cu*=0.001;
				}
				if(I[z-2-j]=='k')
				{
					sscanf(I,"%lfk",&cu);
					cu*=1000;
				}
				if(I[z-2-j]=='M')
				{
					sscanf(I,"%lfM",&cu);
					cu*=1000000;
				}
			}
		}

		if(c[i-1]=='U')
		{
			oku=1;
			for(z=i+1;c[z]!='V';z++)
				U[z-i-1]=c[z];
			U[z-i-1]='\0';
			if(isdigit(U[z-2-i]))
				sscanf(U,"%lf",&u);
			else
			{
				if(U[z-2-i]=='m')
				{
					sscanf(U,"%lfm",&u);
					u*=0.001;
				}
				if(U[z-2-i]=='k')
				{
					sscanf(U,"%lfk",&u);
					u*=1000;
				}
				if(U[z-2-i]=='M')
				{
					sscanf(U,"%lfM",&u);
					u*=1000000;
				}
			}
		}

		if(c[j-1]=='U')
		{
			oku=1;
			for(z=j+1;c[z]!='V';z++)
				U[z-j-1]=c[z];
			U[z-j-1]='\0';
			if(isdigit(U[z-2-j]))
			{
				sscanf(U,"%lf",&u);

			//	cout<<u<<endl;
			}
			else
			{
				if(U[z-2-j]=='m')
				{
					sscanf(U,"%lfm",&u);
					u*=0.001;
				}
				if(U[z-2-j]=='k')
				{
					sscanf(U,"%lfk",&u);
					u*=1000;
				}
				if(U[z-2-j]=='M')
				{
					sscanf(U,"%lfM",&u);
					u*=1000000;
				}
			}
		}

		if(c[i-1]=='P')
		{
			okp=1;
			for(z=i+1;c[z]!='W';z++)
				P[z-i-1]=c[z];
			P[z-i-1]='\0';
			if(isdigit(P[z-2-i]))
				sscanf(P,"%lf",&p);
			else
			{
				if(P[z-2-i]=='m')
				{
					sscanf(P,"%lfm",&p);
					p/=1000;
				}
				if(P[z-2-i]=='k')
				{
					sscanf(P,"%lfk",&p);
					p*=1000;
				}
				if(P[z-2-i]=='M')
				{
					sscanf(P,"%lfM",&p);
					p*=1000000;
				}
			}
		}

		if(c[j-1]=='P')
		{
			okp=1;
			for(z=j+1;c[z]!='W';z++)
				P[z-j-1]=c[z];
			P[z-j-1]='\0';
			if(isdigit(P[z-2-j]))
				sscanf(P,"%lf",&p);
			else
			{
				if(P[z-2-j]=='m')
				{
					sscanf(P,"%lfm",&p);
					p*=0.001;
				}
				if(P[z-2-j]=='k')
				{
					sscanf(P,"%lfk",&p);
					p*=1000;
				}
				if(P[z-2-j]=='M')
				{
					sscanf(P,"%lfM",&p);
					p*=1000000;
				}
			}
		}

		if(!oki)
		{
			cu=p/u;
			cout<<"Problem #"<<y<<endl;
			printf("I=%.2lfA\n",cu);
		}
		if(!oku)
		{
			u=p/cu;
			cout<<"Problem #"<<y<<endl;
			printf("U=%.2lfV\n",u);
		}
		if(!okp)
		{
			p=cu*u;
			cout<<"Problem #"<<y<<endl;
			printf("P=%.2lfW\n",p);
		}
	//	if(y!=n)
			putchar('\n');
	}
	return 0;
}