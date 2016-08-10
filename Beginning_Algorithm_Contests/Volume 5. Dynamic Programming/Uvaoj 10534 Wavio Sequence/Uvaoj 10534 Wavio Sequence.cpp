/* 靠！理解错题意了···我就觉得没有那么简单···
#include<cstdio>
#include<iostream>
using namespace std;

int f(int m);
int n;
int a[10010];

int main()
{
    freopen("data.in","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            cin>>a[i];
        int m = 1;
        for(int i=1;i<n-1;i++)
            if(f(i)>m)
                m = f(i);
        cout<<m<<endl;
    }
    return 0;
}

int f(int m)
{
    int i=1;
    while(m-i>=0&&m+i<=n-1&&a[m-i+1]>a[m-i]&&a[m+i]<a[m+i-1])
        i++;
    return 2*i-1;
}
*/


#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;


int a[10010];
int h[10010];
int in[10010];
int de[10010];
int b[10010];

void make(int* in, int *a);
int n;

int main()
{
    //freopen("data.in","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            cin>>a[i];
        make(in,a);
        for(int i=0;i<n;i++)
            h[i] = a[n-i-1];
        make(de,h);
        int max = 0;
        for(int i=0;i<n;i++)
        {
            int hold = 2*min(in[i],de[n-i-1])-1;
            if(hold>max)
                max = hold;
        }
        cout<<max<<endl;
        //for(int i=0;i<n;i++)
        //    cout<<in[i]<<' ';
       // cout<<endl;
    }
    return 0;
}

void make(int* in, int *a)
{
    int count = 0;
    b[0] = a[0];
    count++;
    in[0] = count;
    for(int i=1;i<n;i++)
    {
        if(a[i]>b[count-1])
        {
            b[count++] = a[i];
            in[i] = count;
        }
        else
        {
            int* s = lower_bound(b,b+count,a[i]);
            *s = a[i];
            in[i] = s-b+1;
        }
    }
}












