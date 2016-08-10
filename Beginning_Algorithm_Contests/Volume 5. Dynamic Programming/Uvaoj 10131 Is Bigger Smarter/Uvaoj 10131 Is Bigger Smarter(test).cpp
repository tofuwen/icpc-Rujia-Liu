#include<stdio.h>
#include<stdlib.h>
const int MAX = 1001 ;
struct eleph
{
  int w , s , a ;
} ;
eleph es[MAX] ;
int b[MAX] ;
int father[MAX] ;
int cmp(const void *a , const void *b)
{
    return ((eleph *)a)->w - ((eleph *)b)->w ;
}
void print_result(int end)
{
    if(father[end] == 0)
    {
        printf("%d\n" , es[end].a) ;
        return ;
    }
    print_result(father[end]) ;
    printf("%d\n" , es[end].a) ;
}
int main()
{
    freopen("data.txt" , "r" ,stdin) ;
    int p = 1 ;
    while(~scanf("%d %d", &es[p].w , &es[p].s))
    {
        b[p] = 1;
        es[p].a = p;
        p++;
    }
    p-- ;
    qsort(es+1 , p , sizeof(eleph) ,cmp) ;
    int len = 0 ,end=0;
    for(int i = 1 ; i <= p ;i++)
    {
        for(int j = 1 ;j<i;j++)
        {
            if(es[j].w < es[i].w && es[j].s > es[i].s &&b[j]+1>b[i])
            {
                b[i] = b[j] + 1 ;
                father[i] = j ;
            }
            if(b[i] > len)
            {
                len = b[i] ;
                end = i ;
            }
        }
    }
    printf("%d\n" , len) ;
    print_result(end) ;
    return 0;
}