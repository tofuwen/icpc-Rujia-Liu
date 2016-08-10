/*
//注意：此题是大数！最大能到到10^50次方左右！
//这个小程序就是个demo，来试验一下算法对不对···
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int f(int n);
int g(int n);
int n;
int needle3[30];
int needle4[30];
int main()
{
    for(int i=0;i<30;i++)
        needle3[i] = f(i);
    needle4[0] = 0;
    needle4[1] = 1;
    for(int i=2;i<30;i++)
    {
        needle4[i] = g(i);
    }

    while(1)
    {
        cin>>n;
        if(!n) break;
        int min = 1<<30;
        int h;
        for(int i=0;i<=n;i++)
        {
            if(min>2*needle4[i]+needle3[n-i])
            {
                min=2*needle4[i]+needle3[n-i];
                h = i;
            }

        }
        cout<<min<<' '<<h<<endl;
    }

    return 0;
}

int f(int n)
{
    return (1<<n)-1;
}

int g(int n)
{
    int min = 1<<30;
    for(int i=0;i<n;i++)
    {
        if(min>2*(needle3[i]+needle4[n-1-i])+1)
            min = 2*(needle3[i]+needle4[n-1-i])+1;
    }
    return min;
}
*/


/*
//demo revised
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int f(int n);
int g(int n);
int n;
int needle3[30];
int needle4[30];
int pre3[30];
int pre4[30];
int main()
{
    freopen("data.in","r",stdin);
    for(int i=0;i<30;i++)
        needle3[i] = f(i);
    needle4[0] = 0;
    pre3[0] = 0;
    pre4[0] = 0;
    needle4[1] = 1;
    pre3[1] = 0;
    pre4[1] = 1;
    needle4[2] = 3;
    pre3[2] = 1;
    pre4[2] = 1;
    for(int i=3;i<30;i++)
    {
        needle4[i] = g(i);
    }
    for(int i=0;i<30;i++)
        cout<<pre4[i]<<endl;
    while(scanf("%d",&n)!=EOF)
    {
        cout<<needle4[n]<<endl;
    }

    return 0;
}

int f(int n)
{
    return (1<<n)-1;
}

int g(int n)
{
    int a1 = needle3[pre3[n-1]]+2*needle4[pre4[n-1]+1];
    int a2 = needle3[pre3[n-1]+1]+2*needle4[pre4[n-1]];
    if(a1<a2)
    {
        pre3[n] = pre3[n-1];
        pre4[n] = pre4[n-1]+1;
        return a1;
    }
    else
    {
        pre3[n] = pre3[n-1]+1;
        pre4[n] = pre4[n-1];
        return a2;
    }
}
*/



//正式写code！大数！！
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void g(int n);
int n;
int needle3[10010][60];
int needle4[10010][60];//60个int存一个数
int pre3[10010];
int pre4[10010];
void Plus(int a[], int b[], int c[]);//c = a+b
void Times(int m,int a[], int b[]);//b = m*a
void show(int a[]);
bool isGreater(int a1[], int a2[]);
int main()
{
   // freopen("data.in","r",stdin);
    memset(needle3,0,sizeof(needle3));
    memset(needle4,0,sizeof(needle4));
    needle3[1][0] = 1;
    for(int i=2;i<150;i++)
    {
        Times(2,needle3[i-1],needle3[i]);
        needle3[i][0]++;
    }
    //for(int i=0;i<150;i++)
      //  show(needle3[i]);
    needle4[1][0] = 1;
    pre3[0] = 0;
    pre4[0] = 0;
    pre3[1] = 0;
    pre4[1] = 1;
    needle4[2][0] = 3;
    pre3[2] = 1;
    pre4[2] = 1;
    for(int i=3;i<10005;i++)
    {
        g(i);
    }
    while(scanf("%d",&n)!=EOF)
    {
        show(needle4[n]);
    }
    return 0;
}

void g(int n)
{
    int a1[60];
    memset(a1,0,sizeof(a1));
    int hold[60];
    memset(hold,0,sizeof(hold));
    Times(2,needle4[pre4[n-1]+1],hold);
    Plus(needle3[pre3[n-1]],hold,a1);
    int a2[60];
    memset(a2,0,sizeof(a2));
    memset(hold,0,sizeof(hold));
    Times(2,needle4[pre4[n-1]],hold);
    Plus(needle3[pre3[n-1]+1],hold,a2);
    if(isGreater(a2,a1))
    {
        pre3[n] = pre3[n-1];
        pre4[n] = pre4[n-1]+1;
        for(int i=0;i<60;i++)
            needle4[n][i] = a1[i];
    }
    else
    {
        pre3[n] = pre3[n-1]+1;
        pre4[n] = pre4[n-1];
        for(int i=0;i<60;i++)
            needle4[n][i] = a2[i];
    }
}

void Plus(int a[], int b[], int c[])//c = a+b;
{
    int h=0;
    for(int i=0;i<60;i++)
    {
        int hold = a[i]+b[i]+h;
        c[i] = hold%10;
        h = hold/10;
    }
}

void show(int a[])
{
    int i = 59;
    while(a[i]==0&&i>=0)
        i--;
    for(int j=i;j>=0;j--)
            cout<<a[j];
    if(i==-1)
        cout<<0;
    cout<<endl;
}


void Times(int m,int a[], int b[])//b = m*a
{
    int h=0;
    for(int i=0;i<60;i++)
    {
        int hold = a[i]*m+h;
        b[i] = hold%10;
        h = hold/10;
    }
}

bool isGreater(int a1[], int a2[])
{
    for(int i=59;i>=0;i--)
    {
        if(a1[i]>a2[i])
            return true;
        if(a1[i]<a2[i])
            return false;
    }
    return true;
}


















