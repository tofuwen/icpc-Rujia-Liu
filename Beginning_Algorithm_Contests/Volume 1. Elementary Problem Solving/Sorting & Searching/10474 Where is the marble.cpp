/*Where is the Marble? 
Raju and Meena love to play with Marbles. They have got a lot of marbles with numbers written on them. At the beginning, Raju would place the marbles one after another in ascending order of the numbers written on them. Then Meena would ask Raju to find the first marble with a certain number. She would count 1...2...3. Raju gets one point for correct answer, and Meena gets the point if Raju fails. After some fixed number of trials the game ends and the player with maximum points wins. Today it's your chance to play as Raju. Being the smart kid, you'd be taking the favor of a computer. But don't underestimate Meena, she had written a program to keep track how much time you're taking to give all the answers. So now you have to write a program, which will help you in your role as Raju.

Input 

There can be multiple test cases. Total no of test cases is less than 65. Each test case consists begins with 2 integers: N the number of marbles and Q the number of queries Mina would make. The next N lines would contain the numbers written on the N marbles. These marble numbers will not come in any particular order. Following Q lines will have Q queries. Be assured, none of the input numbers are greater than 10000 and none of them are negative.

Input is terminated by a test case where N = 0 and Q = 0.

Output 

For each test case output the serial number of the case.

For each of the queries, print one line of output. The format of this line will depend upon whether or not the query number is written upon any of the marbles. The two different formats are described below:

`x found at y', if the first marble with number x was found at position y. Positions are numbered 1, 2,..., N.
`x not found', if the marble with number x is not present.
Look at the output for sample input for details.

Sample Input 

4 1
2
3
5
1
5
5 2
1
3
3
3
1
2
3
0 0
Sample Output 

CASE# 1:
5 found at 4
CASE# 2:
2 not found
3 found at 3
*/


#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;
int cmp(const void* a,const void* b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int number,query;
	int n[10010],q[10010];
	int i,j;
	int step=1;
	while(cin>>number>>query)
	{
		if(!number&&!query) break;
		for(i=0;i<number;i++)
			cin>>n[i];
		for(i=0;i<query;i++)
			cin>>q[i];
		qsort(n,number,sizeof(int),cmp);
		printf("CASE# %d:\n",step++);
		for(i=0;i<query;i++)
		{
			int ok=0;
			for(j=0;j<number;j++)
			{
				if(q[i]==n[j])
				{
					ok=1;
					break;
				}
			}
			if(ok)
				printf("%d found at %d\n",q[i],j+1);
			else
				printf("%d not found\n",q[i]);
		}
	}
	return 0;
}