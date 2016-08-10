#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    //freopen("data.txt","r",stdin);
    int n,m;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0) break;
        double ans = 1;
        for(int i=1;i<=m;i++)
        {
            ans *= n-i+1;
            ans /= i;
        }
        long long a = floor(ans+0.5);
        printf("%d things taken %d at a time is %lld exactly.\n",n,m,a);
    }
    return 0;
}
