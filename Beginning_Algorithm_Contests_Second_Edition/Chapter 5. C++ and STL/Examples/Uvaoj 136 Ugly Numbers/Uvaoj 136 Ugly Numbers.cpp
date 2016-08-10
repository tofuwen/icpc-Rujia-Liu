/*
//这个直白的算法估计要TLE
#include<cstdio>
#include<iostream>
using namespace std;


bool isUgly(long long a);
int main()
{
    int count = 0;
    long long a = 1;
    while(count<1500)
    {
        if(isUgly(a))
        {
            count++;
        }
        a++;
    }
    printf("The 1500'th ugly number is %ld.\n",--a);
    //859963392
}

bool isUgly(long long a)
{
    while(a%2==0)
        a /= 2;
    while(a%3==0)
        a /= 3;
    while(a%5==0)
        a /= 5;
    return a==1;
}
*/

/*
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    printf("The 1500'th ugly number is 859963392.\n");
    return 0;
}
*/

#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

long long b[50000];

int main()
{
    long long a = 1<<30;
    long long ans;
    a = a*a;
    //cout<<a;
    int countt = 0;
    for(int i=0;i<50;i++)
    {
        long long h = pow(2,i);
        if(h>a)
            break;
        for(int j=0;j<40;j++)
        {
            long long ho = h*pow(3,j);
            if(ho>a)
                break;
            for(int k=0;k<20;k++)
            {
                long long hold = ho*pow(5,k);
                if(hold>a)
                    break;
                b[countt++] = hold;
            }
        }
    }
    //cout<<countt<<endl;
    sort(b,b+countt);
   // for(int i=0;i<10;i++)
   //     cout<<b[i]<<endl;
    printf("The 1500'th ugly number is %ld.\n",b[1499]);
    return 0;
}
