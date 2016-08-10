#include<cstdio>
#include<iostream>
using namespace std;


int a[60];

int main()
{
    //freopen("data.in","r",stdin);
    int n;
    cin>>n;
    for(int cc=0;cc<n;cc++)
    {
        int L;
        cin>>L;
        int count=0;
        for(int i=0;i<L;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<L;i++)
        {
            for(int j=i+1;j<L;j++)
                if(a[i]>a[j])
                    count++;
        }
        printf("Optimal train swapping takes %d swaps.\n",count);
    }
}
