/*
Problem A: So you want to be a 2n-aire?

The player starts with a prize of $1, and is asked a sequence of n questions. For each question, he may
quit and keep his prize.
answer the question. If wrong, he quits with nothing. If correct, the prize is doubled, and he continues with the next question.
After the last question, he quits with his prize. The player wants to maximize his expected prize.
Once each question is asked, the player is able to assess the probability p that he will be able to answer it. For each question, we assume that p is a random variable uniformly distributed over the range t .. 1.

Input is a number of lines, each with two numbers: an integer 1 ≤ n ≤ 30, and a real 0 ≤ t ≤ 1. Input is terminated by a line containing 0 0. This line should not be processed.

For each input n and t, print the player's expected prize, if he plays the best strategy. Output should be rounded to three fractional digits.

Sample input

1 0.5
1 0.3
2 0.6
24 0.25
0 0
Output for sample input

1.500
1.357
2.560
230.138
*/

/*
//This is totally wrong!
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	freopen("data.txt","r",stdin);
	int n;
	double t;
	while(scanf("%d%lf",&n,&t)&&n)
	{
		if(t>=0.5)
		{
			printf("%.3lf\n",pow(1+t,n));
			continue;
		}
		double p1 = 0.5/(1-t);
		//printf("p1:%lf\n",p1);
		double p2 = 1-p1;
		p1 *= 0.75;
		if(t<1e-10)
		{
			printf("%.3lf\n",n*p2+0.75);
			continue;
		}
		//printf("%d\n", n);
		double hold = pow(2*p1,n);
		//printf("hold:%lf\n",hold);
		printf("%.3lf\n",p2*(1-hold)/(1-1.5*p1)+hold);
	}
	return 0;
}
*/


#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 35;

double a[maxn];
//a[i]: when having finished i-th question, the maximum expected money

int main()
{
	//freopen("data.txt","r",stdin);
	int n;
	double t;
	while(scanf("%d%lf",&n,&t)&&n)
	{
		if(fabs(1-t)<1e-20)
		{
			printf("%.3lf\n",double(1<<n));
			continue;
		}
		a[n] = 1<<n;
		//printf("a[n]:%lf\n",a[n]);
		for(int i=n-1;i>=0;i--)
		{
			double pCritical = double(1<<i)/a[i+1];
			//printf("pC:%lf\n",pCritical);
			double pChoose = (1-pCritical)/(1-t);
			if(pChoose>1)
			{
				pChoose = 1;
				pCritical = t;
			}
			double pNot = 1-pChoose;
			a[i] = pNot*(1<<i)+pChoose*(1+pCritical)/2*a[i+1];
		}
		printf("%.3lf\n",a[0]);
	}
	return 0;
}