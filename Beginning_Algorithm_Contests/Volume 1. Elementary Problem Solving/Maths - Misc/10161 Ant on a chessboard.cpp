/*Problem A.Ant on a Chessboard 
 
Background

  One day, an ant called Alice came to an M*M chessboard. She wanted to go around all the grids. So she began to walk along the chessboard according to this way: (you can assume that her speed is one grid per second)
  At the first second, Alice was standing at (1,1). Firstly she went up for a grid, then a grid to the right, a grid downward. After that, she went a grid to the right, then two grids upward, and then two grids to the left¡­in a word, the path was like a snake.
  For example, her first 25 seconds went like this:
  ( the numbers in the grids stands for the time when she went into the grids)
 
25
24
23
22
21
10
11
12
13
20
9
8
7
14
19
2
3
6
15
18
1
4
5
16
17
5
4
3
2
1
 
1          2          3           4           5
At the 8th second , she was at (2,3), and at 20th second, she was at (5,4).
Your task is to decide where she was at a given time.
(you can assume that M is large enough)
 
 
Input

  Input file will contain several lines, and each line contains a number N(1<=N<=2*10^9), which stands for the time. The file will be ended with a line that contains a number 0.
 
 
Output

  For each input situation you should print a line with two numbers (x, y), the column and the row number, there must be only a space between them.
 
 
Sample Input

8
20
25
0
 
 
Sample Output

2 3
5 4
1 5
*/



#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n;
	int i;
	while(cin>>n)
	{
		if(!n) break;
		i=floor(sqrt(n)+1e-9);
		if(i%2==0)
		{
			if(i*i==n)
				printf("%d 1\n",i);
			else
			{
				if(i*i+i+1>n)
					printf("%d %d\n",i+1,n-i*i);
				else
					printf("%d %d\n",i*i+2*i+2-n,i+1);
			}
		}
		else
		{
			if(i*i==n)
				printf("1 %d\n",i);
			else
			{
				if(i*i+i+1>n)
					printf("%d %d\n",n-i*i,i+1);
				else
					printf("%d %d\n",i+1,i*i+2*i+2-n);
			}
		}
	}
	return 0;
}
