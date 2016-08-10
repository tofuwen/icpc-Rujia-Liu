#include<cstdio>
#include<iostream>
using namespace std;

typedef struct tofu
{
    int max;
    int start;
    int end;
}Tofu;

int s[20010];
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int cases;
    cin>>cases;
    for(int cc=1;cc<=cases;cc++)
    {
        int stop;
        cin>>stop;
        int n = stop-1;
        for(int i=0;i<n;i++)
            cin>>s[i];
        int start =0 ;
        int end = 0;
        int current = 0;
        Tofu t;
        t.max = 0;
        t.start = 0;
        t.end = 0;
        for(int i=0;i<n;i++)
        {
            current += s[i];
            end = i+1;
            if((current>t.max)||(current==t.max&&end-start>t.end-t.start))
            {
                t.max = current;
                t.start = start;
                t.end = i+1;
            }
            if(current<0)
            {
                start = i+1;
                current = 0;
            }
        }
        if(t.max<=0)
            printf("Route %d has no nice parts\n",cc);
        else
            printf("The nicest part of route %d is between stops %d and %d\n",cc,t.start+1,t.end+1);
    }
    return 0;
}
