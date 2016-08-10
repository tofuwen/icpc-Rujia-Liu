#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 100010;

char s[100];

struct dic
{
    char eng[100];
    char dia[100];
    friend bool operator < (dic a, dic b)
    {
        return strcmp(a.dia,b.dia)<0;
    }
};

int n;
dic d[maxn];

void makeDic(char* s)
{
    sscanf(s,"%s",d[n].eng);
    //printf("%s\n",d[n].eng);
    char *c = s;
    c += strlen(d[n].eng)+1;
    sscanf(c,"%s",d[n].dia);
   // printf("%s\n",d[n].dia);
    n++;
}

int bs(int lo, int hi, char* c)
{
    int mid = (lo+hi)/2;
    if(lo==hi)
        return -1;
    int hold = strcmp(d[mid].dia,c);
    if(hold==0)
        return mid;
    if(hold<0)
        return bs(mid+1,hi,c);
    return bs(lo,mid,c);
}

void solve()
{
    int index = bs(0,n,s);
    if(index==-1)
        printf("eh\n");
    else
        printf("%s\n",d[index].eng);
}

int main()
{
    //freopen("data.txt","r",stdin);
    n = 0;
    while(1)
    {
        gets(s);
       // printf("%s\n",s);
        if(s[0]<='z'&&s[0]>='a')
        {
      //      printf("lao\n");
            makeDic(s);
        }
        else
            break;
    }
   // for(int i=0;i<n;i++)
   //     printf("%s\n",d[i].dia);
    sort(d,d+n);
    //for(int i=0;i<n;i++)
    //    printf("%s\n",d[i].dia);
    while(scanf("%s",s)!=EOF)
    {
        solve();
    }
    return 0;
}
