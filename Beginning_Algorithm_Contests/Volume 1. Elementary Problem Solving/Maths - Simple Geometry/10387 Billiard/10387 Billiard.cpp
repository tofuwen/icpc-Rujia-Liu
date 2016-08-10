/*
Problem A: Billiard

In a billiard table with horizontal side a inches and vertical side b inches, a ball is launched from the middle of the table. After s > 0 seconds the ball returns to the point from which it was launched, after having made m bounces off the vertical sides and n bounces off the horizontal sides of the table. Find the launching angle A (measured from the horizontal), which will be between 0 and 90 degrees inclusive, and the initial velocity of the ball.
Assume that the collisions with a side are elastic (no energy loss), and thus the velocity component of the ball parallel to each side remains unchanged. Also, assume the ball has a radius of zero. Remember that, unlike pool tables, billiard tables have no pockets.

Input

Input consists of a sequence of lines, each containing five nonnegative integers separated by whitespace. The five numbers are: a, b, s, m, and n, respectively. All numbers are positive integers not greater than 10000.
Input is terminated by a line containing five zeroes.

Output

For each input line except the last, output a line containing two real numbers (accurate to two decimal places) separated by a single space. The first number is the measure of the angle A in degrees and the second is the velocity of the ball measured in inches per second, according to the description above.
Sample Input

100 100 1 1 1
200 100 5 3 4
201 132 48 1900 156
0 0 0 0 0
Sample Output

45.00 141.42
33.69 144.22
3.09 7967.81
*/

#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
	int a,b,s,m,n;
	double angle,v,p;
	double pi=acos(-1);
	while(cin>>a>>b>>s>>m>>n)
	{
		if(a==0)
			break;
		a*=m;
		b*=n;
		p=((double)a)*a+((double)b)*b;
		v=sqrt(p)/s;
		angle=atan((double)b/a);
		printf("%.2lf %.2lf\n",angle*180/pi,v);
	}
	return 0;
}










