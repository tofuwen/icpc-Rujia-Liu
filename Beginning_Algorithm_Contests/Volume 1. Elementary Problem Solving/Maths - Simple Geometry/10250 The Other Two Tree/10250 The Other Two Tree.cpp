/*
The Other Two Trees
Input: standard input
Output: standard output
Time Limit: 2 seconds
 
You have a quadrilateral shaped land whose opposite fences are of equal length. You have four neighbors whose lands are exactly adjacent to your four fences, that means you have a common fence with all of them. For example if you have a fence of length d in one side, this fence of length d is also the fence of the adjacent neighbor on that side. The adjacent neighbors have no fence in common among themselves and their lands also don¡¯t intersect. The main difference between their land and your land is that their lands are all square shaped. All your neighbors have a tree at the center of their lands. Given the Cartesian coordinates of trees of two opposite neighbors, you will have to find the Cartesian coordinates of the other two trees.
 
Input
The input file contains several lines of input. Each line contains four floating point or integer numbers x1, y1, x2, y2, where (x1, y1), (x2, y2) are the coordinates of the trees of two opposite neighbors. Input is terminated by end of file.
 
Output
For each line of input produce one line of output which contains the line ¡°Impossible.¡± without the quotes, 
if you cannot determine the coordinates of the other two trees. 
Otherwise, print four floating point numbers separated by a single space with ten digits after the decimal point ax1, ay1, ax2, ay2, 
where (ax1, ay1)  and (ax2, ay2) are the coordinates of the other two trees. The output will be checked with special judge program,
so don¡¯t worry about the ordering of the points or small precision errors. The sample output will make it clear.
 
Sample Input
10 0 -10 0
10 0 -10 0
10 0 -10 0
 
Sample Output
0.0000000000 10.0000000000 0.0000000000 -10.0000000000
0.0000000000 10.0000000000 -0.0000000000 -10.0000000000
0.0000000000 -10.0000000000 0.0000000000 10.0000000000
*/

#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double a,b,c,d,x,y,p,q;
	while(cin>>a>>b>>c>>d)
	{
		if(a==c&&b==d)
			cout<<"Impossible."<<endl;
		else
		{
			x=(a+c)/2;
			y=(b+d)/2;
			p=x+(d-b)/2;
			q=y+(a-c)/2;
			a=2*x-p;
			b=2*y-q;
			printf("%.10lf %.10lf %.10lf %.10lf\n",p,q,a,b);
		}
	}
	return 0;
}