#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

struct ls
{
    char s[70];
    friend bool operator < (const ls& a, const ls& b)
    {
        return strcmp(a.s,b.s)<0;
    }
};

ls filename[110];

char s[110][70];
int n;
int longest;

int main()
{
   // freopen("data.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<110;i++)
            for(int j=0;j<70;j++)
                s[i][j] = ' ';
        longest = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",filename[i].s);
            int d = strlen(filename[i].s);
            longest = max(longest,d);
        }
        sort(filename,filename+n);
        int num = 62/(longest+2);
        int row = (n+num-1)/num;
       // cout<<row<<endl;
        for(int i=0;i<60;i++)
            s[0][i] = '-';
        s[0][60] = '\0';
        int now;
        int f = n-num*(row-1);
        for(int i=1;i<=row;i++)
        {
            now = i-1;
            for(int j=0;j<num;j++)
            {
                if(now<n)
                {
                    strcpy(s[i]+j*(longest+2),filename[now].s);
                  //  if(j!=num-1&&(!(i==row&&j==f-1)))
                        s[i][j*(longest+2)+strlen(filename[now].s)] = ' ';
                        //最后一行可能没有'\0'。单独判断
                }
                now += row;
            }
        }
        for(int i=0;i<=row;i++)
            s[i][61] = '\0';
        for(int i=0;i<=row;i++)
            puts(s[i]);
    }
    return 0;
}
