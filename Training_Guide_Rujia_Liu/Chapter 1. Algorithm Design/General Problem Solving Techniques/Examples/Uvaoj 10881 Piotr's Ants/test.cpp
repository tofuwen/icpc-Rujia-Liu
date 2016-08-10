#include <stdio.h>  
#include <algorithm>  
using namespace std;  
  
const int maxn = 10005;  
  
struct NODE  
{  
    int no;  
    int s;  
    int t;//朝向，-1为左，0中，1右  
}start[maxn],end[maxn];  
  
int cmp(NODE x,NODE y)  
{  
    return x.s < y.s;  
}  
  
char turn[][10] = {"L","Turning","R"};  
int order[maxn];  
  
int main()  
{  
    freopen("input.txt","r",stdin);
    freopen("outputtest.txt","w",stdout);
    int t,cas = 1;  
    scanf("%d",&t);  
    while(t--)  
    {  
        int L,T,N,i;  
        scanf("%d%d%d",&L,&T,&N);  
        for(i = 0;i<N;i++)  
        {  
            char c;  
            start[i].no = i;  
            scanf("%d %c",&start[i].s,&c);  
            start[i].t = (c == 'L'?-1:1);  
            end[i].no = 0;  
            end[i].s = start[i].s + T*start[i].t;  
            end[i].t = start[i].t;  
        }  
        sort(start,start+N,cmp);  
        for(i = 0;i<N;i++)  
        order[start[i].no] = i;  
        sort(end,end+N,cmp);  
        for(i = 0;i<N-1;i++)  
        {  
            if(end[i].s == end[i+1].s)  
            end[i].t = end[i+1].t = 0;  
        }  
        printf("Case #%d:\n",cas++);  
        for(i = 0;i<N;i++)  
        {  
            int a = order[i];  
            if(end[a].s < 0 || end[a].s>L)  
            printf("Fell off\n");  
            else  
            printf("%d %s\n",end[a].s,turn[end[a].t+1]);  
        }  
        printf("\n");  
    }  
    return 0;  
}  