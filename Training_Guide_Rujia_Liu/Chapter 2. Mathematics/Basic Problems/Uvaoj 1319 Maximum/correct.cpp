#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <algorithm>  
using namespace std;  
  
void work(int m,int p,int a,int b)  
{  
    double res=0;  
    for(int i=0;i<m;i++)  
    {  
        int last=a*b+i-(m-i-1)*a;  
        if(last>=-1 && last<=a)  
        {  
            res+=i;  
            res+=pow((double)last,p);  
            res+=(double)(m-i-1)*pow((double)a,p);  
            res/=pow((double)a, p/2.0);  
            break;  
        }  
    }  
    printf("%d\n", (int)(res+0.5));  
}  
  
int main()  
{  
    freopen("data.txt", "r", stdin);
    int m,p,a,b;
  
    while(~scanf("%d%d%d%d",&m,&p,&a,&b))  
        work(m,p,a,b);  
}  
