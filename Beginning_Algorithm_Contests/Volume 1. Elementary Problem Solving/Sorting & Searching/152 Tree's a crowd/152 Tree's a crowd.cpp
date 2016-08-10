/*Tree's a Crowd 

Dr William Larch, noted plant psychologist and inventor of the phrase ``Think like a tree--Think Fig'' has invented a new classification system for trees. This is a complicated system involving a series of measurements which are then combined to produce three numbers (in the range [0, 255]) for any given tree. Thus each tree can be thought of as occupying a point in a 3-dimensional space. Because of the nature of the process, measurements for a large sample of trees are likely to be spread fairly uniformly throughout the whole of the available space. However Dr Larch is convinced that there are relationships to be found between close neighbours in this space. To test this hypothesis, he needs a histogram of the numbers of trees that have closest neighbours that lie within certain distance ranges.

Write a program that will read in the parameters of up to 5000 trees and determine how many of them have closest neighbours that are less than 1 unit away, how many with closest neighbours 1 or more but less than 2 units away, and so on up to those with closest neighbours 9 or more but less than 10 units away. Thus if   is the distance between the i'th point and its nearest neighbour(s) and   , with j and k integers and k = j+1, then this point (tree) will contribute 1 to the j'th bin in the histogram (counting from zero). For example, if there were only two points 1.414 units apart, then the histogram would be 0, 2, 0, 0, 0, 0, 0, 0, 0, 0.

Input and Output

Input will consist of a series of lines, each line consisting of 3 numbers in the range [0, 255]. The file will be terminated by a line consisting of three zeroes.

Output will consist of a single line containing the 10 numbers representing the desired counts, each number right justified in a field of width 4.

Sample input

10 10 0
10 10 0
10 10 1
10 10 3
10 10 6
10 10 10
10 10 15
10 10 21
10 10 28
10 10 36
10 10 45
0 0 0
Sample output

   2   1   1   1   1   1   1   1   1   1
   */


#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int tree[5010][4];
	int n=0;
	int i,j;
	double d;
	int distance;
	int b[15];
	memset(b,0,sizeof(b));
	while(cin>>tree[n][0]>>tree[n][1]>>tree[n][2])
	{
		if(!tree[n][0]&&!tree[n][1]&&!tree[n][2]) break;
		n++;
	}
	for(i=0;i<n;i++)
	{
		int min=100000000;
		for(j=0;j<n;j++)
		{
			if(i==j) continue;
			d=sqrt((tree[i][0]-tree[j][0])*(tree[i][0]-tree[j][0])+(tree[i][1]-tree[j][1])*(tree[i][1]-tree[j][1])+(tree[i][2]-tree[j][2])*(tree[i][2]-tree[j][2]));
			distance=floor(d+1e-9);
			if(distance<min)
				min=distance;
		}
		if(min>=0&&min<=9)
			b[min]++;
	}
	for(i=0;i<10;i++)
		printf("%4d",b[i]);
	putchar('\n');
	return 0;
}