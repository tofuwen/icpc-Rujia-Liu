#include<cstdio>
#include<algorithm>
#include<cmath>
#define INF 1<<30
using namespace std;

struct point
{
    int x;
    int y;
};

double dis[10][10];

point p[10];
int n;
int ans[10];
int cur[10];
double Ans;
char star[100];

double calDis(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double getDis(int index1, int index2)
{
    if(index1>index2)
        return dis[index2][index1];
    return dis[index1][index2];
}

int main()
{
  //  freopen("data.txt","r",stdin);
    int caseN = 0;
    for(int i=0;i<58;i++)
        star[i] = '*';
    star[58] = '\0';
    while(scanf("%d",&n)&&n)
    {
        Ans = INF;
        for(int i=0;i<n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                dis[i][j] = calDis(p[i],p[j])+16;
        for(int i=0;i<n;i++)
            cur[i] = i;
        do
        {
            double h = 0;
            for(int i=0;i<n-1;i++)
            {
                h += getDis(cur[i],cur[i+1]);
                if(h>Ans)
                    break;
            }
            if(h<Ans)
            {
                Ans = h;
                for(int i=0;i<n;i++)
                    ans[i] = cur[i];
            }
        }while(next_permutation(cur,cur+n));
        printf("%s\n",star);
        printf("Network #%d\n",++caseN);
        for(int i=0;i<n-1;i++)
        {
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",p[ans[i]].x,p[ans[i]].y,p[ans[i+1]].x,p[ans[i+1]].y,getDis(ans[i],ans[i+1]));
        }
        printf("Number of feet of cable required is %.2f.\n",Ans);
    }
    return 0;
}
