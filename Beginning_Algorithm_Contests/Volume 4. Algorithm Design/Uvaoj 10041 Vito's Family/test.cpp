#include<stdio.h>
void Qsort(long *a,long begin,long end)
{
    long i=begin,j=end,mid=a[(begin+end)/2],t;
    do{
         while(a[i]<mid) i++;
         while(a[j]>mid) j--;
         if(i<=j)
         {
            t=a[i];a[i]=a[j];a[j]=t;
            i++;j--;
         }
    }while(i<=j);
    if(begin<j) Qsort(a,begin,j);
    if(i<end)   Qsort(a,i,end);
}
long Abs(long x)
{
    return (x>0?x:-x);
}
int main()
{
    
    freopen("data.txt","r",stdin);
    //freopen("data.out","w",stdout);
    
    const long maxn=507;
    long test;
    scanf("%ld",&test);
    while(test--)
    {
       long n,mid,ans,a[maxn];
       scanf("%ld",&n);
       for(long i=1;i<=n;i++) scanf("%ld",&a[i]);
       Qsort(a,1,n);
       mid=a[(1+n)/2];
     //  printf()
       ans=0;
       for(long i=1;i<=n;i++)
         ans+=Abs(mid-a[i]);
       printf("%ld\n",ans);
    }
return 0;
}