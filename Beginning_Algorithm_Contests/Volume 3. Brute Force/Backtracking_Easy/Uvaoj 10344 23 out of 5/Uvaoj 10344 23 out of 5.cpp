#include<cstdio>
#include<algorithm>
using namespace std;

int data[10];
int a[10];
int o[10];

int suan(int a1, int a2, int ope)
{
    if(ope==0)
        return a1+a2;
    if(ope==1)
        return a1-a2;
    return a1*a2;
}

int cal()
{
    int ans = data[a[0]];
    for(int i=0;i<4;i++)
        ans = suan(ans,data[a[i+1]],o[i]);
    return ans;
}

void solve()
{
    for(int i=0;i<5;i++)
        a[i] = i;
    do
    {
        for(o[0]=0;o[0]<3;o[0]++)
            for(o[1]=0;o[1]<3;o[1]++)
                for(o[2]=0;o[2]<3;o[2]++)
                    for(o[3]=0;o[3]<3;o[3]++)
                    {
                        int v = cal();
                        if(v==23)
                        {
                            printf("Possible\n");
                            return;
                        }
                    }
    }while(next_permutation(a,a+5));
    printf("Impossible\n");
}

int main()
{
  //  freopen("data.txt","r",stdin);
    while(scanf("%d",&data[0])&&data[0])
    {
        for(int i=1;i<5;i++)
            scanf("%d",&data[i]);
        solve();
    }
    return 0;
}
