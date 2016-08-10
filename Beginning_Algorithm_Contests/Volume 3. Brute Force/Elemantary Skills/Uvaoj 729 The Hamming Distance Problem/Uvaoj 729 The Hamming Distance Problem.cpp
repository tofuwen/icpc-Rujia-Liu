#include<cstdio>
using namespace std;

int a[20];
int n,m;
int ans[20];
int anss[20000][20];


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

void print(int index)
{
    int k = 0;
    for(int i=0;i<n;i++)
    {
        if(k<m&&i==a[k])
        {
            ans[i] = 1;
            k++;
        }
        else
            ans[i] = 0;
    }
    for(int i=0;i<n;i++)
        anss[index][i] = ans[i];
}


int main()
{
    freopen("data.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int cc=0;cc<T;cc++)
    {
        scanf("%d%d",&n,&m);
        makeFirstCom(m);
        int index = 0;
        do
        {
            print(index++);
        }while(nextCom(n,m));
        for(int i=index-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
                printf("%d",anss[i][j]);
            putchar('\n');
        }
        if(cc<T-1)
            putchar('\n');
    }
    return 0;
}

























