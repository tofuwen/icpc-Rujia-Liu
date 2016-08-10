// Problem K

// KTV

// One song is extremely popular recently, so you and your friends decided to sing it in KTV. The song has 3 characters, so exactly 3 people should sing together each time (yes, there are 3 microphones in the room). There are exactly 9 people, so you decided that each person sings exactly once. In other words, all the people are divided into 3 disjoint groups, so that every person is in exactly one group.



// However, some people don't want to sing with some other people, and some combinations perform worse than others combinations. Given a score for every possible combination of 3 people, what is the largest possible score for all the 3 groups?

// Input

// The input consists of at most 1000 test cases. Each case begins with a line containing a single integer n (0 < n < 81), the number of possible combinations. The next n lines each contains 4 positive integers a, b, c, s (1 <= a < b < c <= 9, 0 < s < 10000), that means a score of s is given to the combination (a,b,c). The last case is followed by a single zero, which should not be processed.
// Output

// For each test case, print the case number and the largest score. If it is impossible, print -1.
// Sample Input

// 3
// 1 2 3 1
// 4 5 6 2
// 7 8 9 3
// 4
// 1 2 3 1
// 1 4 5 2
// 1 6 7 3
// 1 8 9 4
// 0
// Output for the Sample Input

// Case 1: 6
// Case 2: -1

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int cases;
int data[90][5];
int M;

int isNotOkay(bool v[])
{
	for(int i=1;i<10;i++)
		if(!v[i])
			return i;
	return 0;
}

void solution(bool v[], int s, int b)
{
	if(!isNotOkay(v))
		M = max(M,b);
	bool vv[10];
	for(int i=0;i<10;i++)
		vv[i] = v[i];
	for(int i=s;i<n;i++)
	{
		if(vv[data[i][0]]||vv[data[i][1]]||vv[data[i][2]])
			continue;
		vv[data[i][0]] = vv[data[i][1]] = vv[data[i][2]] = true;
		solution(vv,i+1,b+data[i][3]);
		vv[data[i][0]] = vv[data[i][1]] = vv[data[i][2]] = false;
	}
}

void solve()
{
	M = -1;
	bool visited[10];
	memset(visited,0,sizeof(visited));
	solution(visited,0,0);
	printf("Case %d: %d\n",++cases,M);
}

int main()
{
	//freopen("data.txt","r",stdin);
	cases = 0;
	while(scanf("%d",&n)&&n)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<4;j++)
				scanf("%d",&data[i][j]);
		solve();
	}
	return 0;
}