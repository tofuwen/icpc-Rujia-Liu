#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int n,m;
long long f[23];
long long c[25][25];
long long fal[25];

int main()
{
    //freopen("data.txt","r",stdin);
    f[0] = 1;
    for(int i=1;i<21;i++)
        f[i] = i*f[i-1];
    c[0][1] = c[1][1] = 1;
    for(int i=0;i<=20;i++)
    {
        c[0][i] = 1;
        c[i][i] = 1;
    }
    for(int i=2;i<=20;i++)
    {
        for(int j=1;j<=i-1;j++)
            c[j][i] = c[j-1][i-1]+c[j][i-1];
    }
    //cout<<c[15][15]<<endl;
    fal[0] = 1;
    fal[1] = 0;
    for(int i=2;i<=20;i++)
    {
        long long h = 0;
        int flag = 1;
        int stage = 1;
        while(stage<=i)
        {
            h += c[stage][i]*f[i-stage]*flag;
            flag = -flag;
            stage++;
        }
        fal[i] = f[i]-h;
    }
//    for(int i=1;i<=20;i++)
  //      for(int j=0;j<=i;j++)
  //          printf("c(%d,%d) = %lld\n",j,i,c[j][i]);
   // for(int i=0;i<=20;i++)
    //    printf("fac %d is %lld\n",i,f[i]);
  //  for(int i=0;i<=20;i++)
  //      printf("fal %d is %lld\n",i,fal[i]);
 //   printf("%lld\n",f[20]);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        long long ans = 0;
        for(int i=0;i<=m;i++)
        {
            ans += c[i][n]*fal[n-i];
            //printf("%lld\n",ans);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
