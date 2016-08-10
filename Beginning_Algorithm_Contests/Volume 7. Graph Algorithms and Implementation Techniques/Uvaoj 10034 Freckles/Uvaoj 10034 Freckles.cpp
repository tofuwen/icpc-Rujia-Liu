#include<cmath>
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef struct point
{
    double x;
    double y;
}Point;
Point p[105];
int start[10000];//边的起始位置
int end[10000];
double weight[10000];
int r[10000];//第i小的边的序号
int fa[105];//并查集的父亲
double cal(int n);
bool compare(const int i,const  int j)
{
    return weight[i]<weight[j];
}
int find(int x)//找并查集的父亲
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main()
{
    //freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
    int N;
    cin>>N;
    for(int cc=0;cc<N;cc++)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>p[i].x>>p[i].y;
        printf("%.2f\n",cal(n));
        if(cc!=N-1)
            cout<<endl;
    }
    return 0;
}

double cal(int n)
{
    double ans = 0;
    int m = n*(n-1)/2;
    for(int i=0;i<n;i++)
    {
        fa[i] = i;
    }
    for(int i=0;i<m;i++)
    {
        r[i] = i;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            int h = i*(i-1)/2+j;
            start[h] = i;
            end[h] = j;
            weight[h] = sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
           // cout<<"s "<<start[h]<<endl;
           // cout<<"e "<<end[i]<<endl;
        }
    }
    sort(r,r+m,compare);
   // for(int i=0;i<m;i++)
       // cout<<"r "<<r[i]<<endl;
    for(int i=0;i<m;i++)
    {
        int x = find(start[r[i]]);
        int y = find(end[r[i]]);
       // cout<<"x y"<<x<<" "<<y<<endl;
        if(x!=y)
        {
            ans += weight[r[i]];
          //  cout<<ans<<endl;
            fa[x] = y;
        }
    }
    return ans;
}

















