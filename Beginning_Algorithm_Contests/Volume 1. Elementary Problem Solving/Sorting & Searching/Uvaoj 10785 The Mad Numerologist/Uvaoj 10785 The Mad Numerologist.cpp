#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char vowel[10] = {'A','U','E','O','I'};
char consonant[30] = {'J','S','B','K','T','C','L','D','M','V','N','W','F','X','G','P','Y','H','Q','Z','R'};
int n;
char ans[300];
char h1[300];
char h2[300];
int nh1;
int nh2;

char workv(int i)
{
    return vowel[i/21];
}

char workc(int i)
{
    return consonant[i/5];
}

void solve()
{
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
            ans[i] = workv(i/2);
        else
            ans[i] = workc((i-1)/2);
    }
    ans[n] = '\0';
}

void solve2()
{
    nh1 = nh2 = 0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
            h1[nh1++] = ans[i];
        else
            h2[nh2++] = ans[i];
    }
    sort(h1,h1+nh1);
    sort(h2,h2+nh2);
    nh1 = nh2 = 0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
            ans[i] = h1[nh1++];
        else
            ans[i] = h2[nh2++];
    }
}

int main()
{
    //freopen("data.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int cc=1;cc<=T;cc++)
    {
        scanf("%d",&n);
        solve();
        solve2();
        printf("Case %d: %s\n",cc,ans);
    }
    return 0;
}
