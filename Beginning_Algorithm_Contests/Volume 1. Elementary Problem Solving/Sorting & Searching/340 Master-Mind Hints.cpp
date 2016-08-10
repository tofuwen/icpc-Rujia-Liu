/*
Master-Mind Hints 

MasterMind is a game for two players. One of them, Designer, selects a secret code. The other, Breaker, tries to break it. A code is no more than a row of colored dots. At the beginning of a game, the players agree upon the length N that a code must have and upon the colors that may occur in a code.

In order to break the code, Breaker makes a number of guesses, each guess itself being a code. After each guess Designer gives a hint, stating to what extent the guess matches his secret code.

In this problem you will be given a secret code   and a guess   , and are to determine the hint. A hint consists of a pair of numbers determined as follows.

A match is a pair (i,j),   and   , such that   . Match (i,j) is called strong when i = j, and is called weak otherwise. Two matches (i,j) and (p,q) are called independent when i = p if and only if j = q. A set of matches is called independent when all of its members are pairwise independent.

Designer chooses an independent set M of matches for which the total number of matches and the number of strong matches are both maximal. The hint then consists of the number of strong followed by the number of weak matches in M. Note that these numbers are uniquely determined by the secret code and the guess. If the hint turns out to be (n,0), then the guess is identical to the secret code.

Input

The input will consist of data for a number of games. The input for each game begins with an integer specifying N (the length of the code). Following these will be the secret code, represented as N integers, which we will limit to the range 1 to 9. There will then follow an arbitrary number of guesses, each also represented as N integers, each in the range 1 to 9. Following the last guess in each game will be N zeroes; these zeroes are not to be considered as a guess.

Following the data for the first game will appear data for the second game (if any) beginning with a new value for N. The last game in the input will be followed by a single zero (when a value for N would normally be specified). The maximum value for N will be 1000.

Output

The output for each game should list the hints that would be generated for each guess, in order, one hint per line. Each hint should be represented as a pair of integers enclosed in parentheses and separated by a comma. The entire list of hints for each game should be prefixed by a heading indicating the game number; games are numbered sequentially starting with 1. Look at the samples below for the exact format.

Sample Input

4
1 3 5 5
1 1 2 3
4 3 3 5
6 5 5 1
6 1 3 5
1 3 5 5
0 0 0 0
10
1 2 2 2 4 5 6 6 6 9
1 2 3 4 5 6 7 8 9 1
1 1 2 2 3 3 4 4 5 5
1 2 1 3 1 5 1 6 1 9
1 2 2 5 5 5 6 6 6 7
0 0 0 0 0 0 0 0 0 0
0
Sample Output

Game 1:
    (1,1)
    (2,0)
    (1,2)
    (1,2)
    (4,0)
Game 2:
    (2,4)
    (3,2)
    (5,0)
    (7,0)
	*/

#include<cstdio>
#include<iostream>
using namespace std;
int a[1010],b[1010],c[1010];
int main()
{
	int n;
	int i,j;
	int count=1;
	while(cin>>n)
	{
		if(!n)
			break;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		printf("Game %d:\n",count++);
		while(1)
		{
			for(i=0;i<n;i++)
				c[i]=a[i];
			int identical=0,similar=0;
			for(i=0;i<n;i++)
				cin>>b[i];
			if(!b[0])
				break;
			for(i=0;i<n;i++)
				if(a[i]==b[i])
					identical++;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(b[i]==c[j])
					{
						similar++;
						c[j]=0;
						break;
					}
				}
			}
			similar-=identical;
			printf("    (%d,%d)\n",identical,similar);
		}
	}
	return 0;
}