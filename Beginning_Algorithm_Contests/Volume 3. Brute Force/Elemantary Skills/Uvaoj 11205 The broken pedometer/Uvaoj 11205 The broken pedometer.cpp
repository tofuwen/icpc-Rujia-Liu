/*
The Broken Pedometer
The Problem

A marathon runner uses a pedometer with which he is having problems. In the pedometer the symbols are represented by seven segments (or LEDs):

But the pedometer does not work properly (possibly the sweat affected the batteries) and only some of the LEDs are active. The runner wants to know if all the possible symbols:

can be correctly identified. For example, when the active LEDs are:

numbers 2 and 3 are seen as:

so they cannot be distinguished. But when the active LEDs are:

the numbers are seen as:

and all of them have a different representation.
Because the runner teaches algorithms at University, and he has some hours to think while he is running, he has thought up a programming problem which generalizes the problem of his sweat pedometer. The problem consists of obtaining the minimum number of active LEDs necessary to identify each one of the symbols, given a number P of LEDs, and N symbols to be represented with these LEDs (along with the codification of each symbol).
For example, in the previous sample P = 7 and N = 10. Supposing the LEDs are numbered as:

The codification of the symbols is: "0" = 1 1 1 0 1 1 1; "1" = 0 0 1 0 0 1 0; "2" = 1 0 1 1 1 0 1; "3" = 1 0 1 1 0 1 1; "4" = 0 1 1 1 0 1 0; "5" = 1 1 0 1 0 1 1; "6" = 1 1 0 1 1 1 1; "7" = 1 0 1 0 0 1 1; "8" = 1 1 1 1 1 1 1; "9" = 1 1 1 1 0 1 1. In this case, LEDs 5 and 6 can be suppressed without losing information, so the solution is 5.
The Input

The input file consists of a first line with the number of problems to solve. Each problem consists of a first line with the number of LEDs (P), a second line with the number of symbols (N), and N lines each one with the codification of a symbol. For each symbol, the codification is a succession of 0s and 1s, with a space between them. A 1 means the corresponding LED is part of the codification of the symbol. The maximum value of P is 15 and the maximum value of N is 100. All the symbols have different codifications.
The Output

The output will consist of a line for each problem, with the minimum number of active LEDs necessary to identify all the given symbols.
Sample Input

2
7
10
1 1 1 0 1 1 1
0 0 1 0 0 1 0
1 0 1 1 1 0 1
1 0 1 1 0 1 1
0 1 1 1 0 1 0
1 1 0 1 0 1 1
1 1 0 1 1 1 1
1 0 1 0 0 1 0
1 1 1 1 1 1 1
1 1 1 1 0 1 1
6
10
0 1 1 1 0 0
1 0 0 0 0 0
1 0 1 0 0 0
1 1 0 0 0 0
1 1 0 1 0 0
1 0 0 1 0 0
1 1 1 0 0 0
1 1 1 1 0 0
1 0 1 1 0 0
0 1 1 0 0 0
Sample Output

5
4
*/



#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;

int P,N;
int g[110][20];
int a[20];
bool v[40000];

bool nextCom(int n, int k)
{
    if(a[k-1]!=n-1)
    {
        a[k-1]++;
        return true;
    }
    int h;
    for(h=k-1;h>=0;h--)
        if(a[h]!=n+h-k)
            break;
    if(h==-1)
        return false;
    a[h]++;
    for(int i=h+1;i<k;i++)
        a[i] = a[h]+i-h;
    return true;
}

void makeFirstCom(int k)
{
    for(int i=0;i<k;i++)
        a[i] = i;
}

int make(int k, int level)
{
    int ans = 0;
    for(int i=0;i<k;i++)
    {
        ans *= 2;
        ans += g[level][a[i]];
    }
    return ans;
}

bool isUnique(int k)
{
    memset(v,0,sizeof(v));
    for(int i=0;i<N;i++)
    {
        int h = make(k,i);
       // cout<<h<<endl;
        if(v[h])
            return false;
        v[h] = true;
    }
    return true;
}

int main()
{
   // freopen("data.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int cc=0;cc<T;cc++)
    {
        bool ok = false;
        scanf("%d%d",&P,&N);
        for(int i=0;i<N;i++)
            for(int j=0;j<P;j++)
                scanf("%d",&g[i][j]);
        int start = ceil(log(N)/log(2)-1e-10);
      //  cout<<start<<endl;
        for(int i=start;i<=P;i++)
        {
            makeFirstCom(i);
            do
            {
            //    for(int j=0;j<i;j++)
            //        cout<<a[j]<<' ';
            //    cout<<endl;
                if(isUnique(i))
                {
                    printf("%d\n",i);
                    ok = true;
                    break;
                }
            }while(nextCom(P,i));
            if(ok)
                break;
        }
    }
    return 0;
}



























