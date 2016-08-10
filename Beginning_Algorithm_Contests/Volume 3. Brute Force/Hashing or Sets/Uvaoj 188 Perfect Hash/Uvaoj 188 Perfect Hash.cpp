#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

char s[1000];
char hold[100];
int w[20];
int n;
int v[20];
//int vv[20];
//int nv;

int make(char hold[])
{
    int d = strlen(hold);
    int ans = 0;
    for(int i=0;i<d;i++)
    {
        ans *= 32;
        ans += hold[i]-'a'+1;
    }
    return ans;
}

/*
int check(int h)
{
    for(int i=0;i<nv;i++)
        if(vv[i]==h)
            return v[i];
    return -1;
}
*/

int main()
{
    //freopen("data.txt","r",stdin);
    while(gets(s))
    {
        n = 0;
        memset(v,0,sizeof(v));
        int d = strlen(s);
        char* h = s;
        while(h<s+d)
        {
            sscanf(h,"%s",hold);
            w[n++] = make(hold);
            h += strlen(hold);
            while(s[h-s]==' ')
                h++;
        }
        sort(w,w+n);
   //     for(int i=0;i<n;i++)
     //       printf("%d\n",w[i]);
        int c = w[0];
        while(1)
        {
            bool ok = false;
            memset(v,-1,sizeof(v));
           // nv = 0;
            for(int i=0;i<n;i++)
            {
                int h = (c/w[i])%n;
               // int hh = check(h);
                if(v[h]==-1)
                {
                    //vv[nv] = h;
                    v[h] = w[i];
                }
                else
                {
                    int a1 = (c/w[i]+1)*w[i];
                    int a2 = (c/v[h]+1)*v[h];
                    c = min(a1,a2);
                    ok = true;
                    break;
                }
            }
            if(ok)
                continue;
            puts(s);
            printf("%d\n\n",c);
            break;
        }
    }
    return 0;
}

















