#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn = 100000;

struct Word
{
    char s[25];
    int id;
    friend bool operator< (const Word& a,const Word& b)
    {
        return strcmp(a.s,b.s)<0;
    }
};

Word w[maxn];
Word hold[maxn];
bool v[maxn];

char s[25];
int n;

void toUpperCase(char c[], int l)
{
    for(int i=0;i<l;i++)
    {
        if(c[i]>='a'&&c[i]<='z')
            c[i] = c[i]-'a'+'A';
    }
}

int main()
{
    //freopen("data.txt","r",stdin);
    n = 0;
    memset(v,0,sizeof(v));
    while(scanf("%s",s)&&s[0]!='#')
        strcpy(w[n++].s,s);
    sort(w,w+n);
    for(int i=0;i<n;i++)
        w[i].id = i;
    for(int i=0;i<n;i++)
    {
        hold[i] = w[i];
        toUpperCase(hold[i].s,strlen(hold[i].s));
        sort(hold[i].s,hold[i].s+strlen(hold[i].s));
    }
    sort(hold,hold+n);
 //   for(int i=0;i<n;i++)
 //       cout<<hold[i].s<<endl;
    for(int i=0;i<n-1;i++)
    {
        if(strcmp(hold[i].s,hold[i+1].s)==0)
        {
            v[hold[i].id] = v[hold[i+1].id] = true;
        }
    }
    for(int i=0;i<n;i++)
        if(!v[i])
            printf("%s\n",w[i].s);
    return 0;
}
