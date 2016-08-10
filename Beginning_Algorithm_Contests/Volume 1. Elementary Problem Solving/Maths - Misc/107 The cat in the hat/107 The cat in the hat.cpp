/*The Cat in the Hat 

Background

(An homage to Theodore Seuss Geisel)

The Cat in the Hat is a nasty creature,
But the striped hat he is wearing has a rather nifty feature.

With one flick of his wrist he pops his top off.

Do you know what's inside that Cat's hat?
A bunch of small cats, each with its own striped hat.

Each little cat does the same as line three,
All except the littlest ones, who just say ``Why me?''

Because the littlest cats have to clean all the grime,
And they're tired of doing it time after time!

The Problem

A clever cat walks into a messy room which he needs to clean. Instead of doing the work alone, it decides to have its helper cats do the work. It keeps its (smaller) helper cats inside its hat. Each helper cat also has helper cats in its own hat, and so on. Eventually, the cats reach a smallest size. These smallest cats have no additional cats in their hats. These unfortunate smallest cats have to do the cleaning.

The number of cats inside each (non-smallest) cat's hat is a constant, N. The height of these cats-in-a-hat is   times the height of the cat whose hat they are in.

The smallest cats are of height one; 
these are the cats that get the work done.
All heights are positive integers.
Given the height of the initial cat and the number of worker cats (of height one), find the number of cats that are not doing any work (cats of height greater than one) and also determine the sum of all the cats' heights (the height of a stack of all cats standing one on top of another).

The Input

The input consists of a sequence of cat-in-hat specifications. Each specification is a single line consisting of two positive integers, separated by white space. The first integer is the height of the initial cat, and the second integer is the number of worker cats.

A pair of 0's on a line indicates the end of input.

The Output

For each input line (cat-in-hat specification), print the number of cats that are not working, followed by a space, followed by the height of the stack of cats. There should be one output line for each input line other than the ``0 0'' that terminates input.

Sample Input

216 125
5764801 1679616
0 0
Sample Output

31 671
335923 30275911
*/


#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int height,amount,h;
//	int i,j,n;
	int i,j,n;
	//double a,guai;
	double a,b,guai;
	//long long height,amount,h;
	while(cin>>height>>amount)
	{
		double sum=0;
		if(!height) break;
		if(amount==1)
		{
			int mi=0;
			h=height;
			while(h!=1)
			{
				mi++;
				h/=2;
			}
			height=2*height-1;
			cout<<mi<<" "<<height<<endl;
			continue;
		}
	//	int ok=0;
		a=log((double)height/amount);
		for(j=1;j<65;j++)
		{
			b=a/j;
			b=exp(b)-1;
			b=1/b;
			if((b-floor(b))<1e-9||floor(b)+1-b<1e-9)
			{
				if(b-floor(b)<1e-9)
					i=floor(b);
				else
					i=floor(b)+1;
				break;
			}
		}
		//cout<<a<<endl;
		/*
		for(i=2;i<=pow(2,31)-1;i++)
		{
			for(j=1;j<=70;j++)
			{
				if(j*log(i+1)>32*log(2))
					break;
				guai=fabs(a-j*(log(i+1)-log(i)));
				if(guai<0.00000001)
				{
				//	cout<<guai<<endl;
					ok=1;
					break;
				}
			}
			if(ok) break;
		}
		*/
		//cout<<i<<endl<<j<<endl;
		guai=(pow(i,j)-1)/(i-1);
		for(n=0;n<=j;n++)
		{
			sum+=pow(i,n)*pow(i+1,j-n);
		}
		printf("%.0lf %.0lf\n",guai,sum);
		
	}
	return 0;
}