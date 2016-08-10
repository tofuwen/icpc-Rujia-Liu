/*Coin Change
Suppose there are 5 types of coins: 50-cent, 25-cent, 10-cent, 5-cent, and 1-cent. We want to make changes with these coins for a given amount of money.


For example, if we have 11 cents, then we can make changes with one 10-cent coin and one 1-cent coin, two 5-cent coins and one 1-cent coin, one 5-cent coin and six 1-cent coins, or eleven 1-cent coins. So there are four ways of making changes for 11 cents with the above coins. Note that we count that there is one way of making change for zero cent.


Write a program to find the total number of different ways of making changes for any amount of money in cents. Your program should be able to handle up to 7489 cents.

Input

The input file contains any number of lines, each one consisting of a number for the amount of money in cents.
Output

For each input line, output a line containing the number of different ways of making changes with the above 5 types of coins.
Sample Input

11
26
Sample Output

4
13
*/

#include<iostream>
#include<stdio.h>
using namespace std;
int a[7500][5];
int f(int n,int m);
int c[5];
int main(void)
{
    int n;
    int i,j;
    c[0] = 1;
    c[1] = 5;
    c[2] = 10;
    c[3] = 25;
    c[4] = 50;
    for(i=0;i<7500;i++)
    {
        for(j=0;j<5;j++)
        {
            a[i][j] = -1;
        }
    }
    for(i=0;i<7500;i++)
    {
        a[i][0] = 1;
    }
    for(i=0;i<5;i++)
    {
        a[0][i] = 1;
    }
    while(scanf("%d",&n)!=EOF)
    {
        //cout<<f(-8)<<endl;
       // cout<<n<<endl;
        cout<<f(n,4)<<endl;
    }
    return 0;
}


int f(int n,int m)
{
    if(n>=0&&a[n][m]!=-1)
        return a[n][m];
    if(n==0)
    {
         return 1;
    }
    if(n<0)
        return 0;
    a[n][m] = f(n,m-1)+f(n-c[m],m);
    //cout<<n<<"    "<<n-10<<"   "<<f(n-10)<<endl;
    //cout<<a[n]<<n<<f(n-10)<<f(n-5)<<endl;
   return a[n][m];
   //else
   // return 1;
}




/*
#include<cstdio>
#include<cstring>
const int maxn = 7490;
const int coin[5] = {1, 5, 10, 25, 50};

int dp[maxn];

int main(void)
{
    int n;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int k = 0; k < 5; ++k)
        for (int i = coin[k]; i < maxn; ++i)
            dp[i] += dp[i - coin[k]];///各种组合都叠加起来
    while (~scanf("%d", &n))
        printf("%d", dp[n]);
    return 0;
}
*/









