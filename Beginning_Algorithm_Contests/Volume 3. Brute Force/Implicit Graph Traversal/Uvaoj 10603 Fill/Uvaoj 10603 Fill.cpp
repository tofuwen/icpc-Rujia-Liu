/*
//靠，没仔细看题···都做完了，答案不对，发现题目看错了···
#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;

int a,b,c,d;
bool visited[41000];
int dd;
int ddtimes;

struct bottle
{
    int a;
    int b;
    int c;
    int times;
};

queue<bottle> q;

bool isVisited(bottle h)
{
    int aa = h.a*201+h.b;
    if(visited[aa])
        return true;
    visited[aa] = true;
    return false;
}

bool make(bottle hold)
{
    if(hold.a==d||hold.b==d||hold.c==d)
    {
        printf("%d %d\n",hold.times,d);
        return true;
    }
    int close = 0;
    if(hold.a>close&&hold.a<d)
        close = hold.a;
    if(hold.b>close&&hold.b<d)
        close = hold.b;
    if(hold.c>close&&hold.c<d)
        close = hold.c;
    if(close>dd)
    {
        dd = close;
        ddtimes = hold.times;
    }
    bottle h1;
    if(hold.a)
    {
        if(hold.b<b)
        {
            if(hold.a<b-hold.b)
            {
                h1.a = 0;
                h1.b = hold.b+hold.a;
                h1.c = hold.c;
                h1.times = hold.times+1;
                if(!isVisited(h1))
                    q.push(h1);
            }
            else
            {
                h1.a = hold.a-(b-hold.b);
                h1.b = b;
                h1.c = hold.c;
                h1.times = hold.times+1;
                if(!isVisited(h1))
                    q.push(h1);
            }
        }
        if(hold.c<c)
        {
            if(hold.a<c-hold.c)
            {
                h1.a = 0;
                h1.b = hold.b;
                h1.c = hold.c+hold.a;
                h1.times = hold.times+1;
                if(!isVisited(h1))
                    q.push(h1);
            }
            else
            {
                h1.a = hold.a-(c-hold.c);
                h1.b = hold.b;
                h1.c = c;
                h1.times = hold.times+1;
                if(!isVisited(h1))
                    q.push(h1);
            }
        }
    }
    if(hold.b)
    {
        if(hold.a<a)
        {
            if(hold.b<a-hold.a)
            {
                h1.a = hold.a + hold.b;
                h1.b = 0;
                h1.c = hold.c;
                h1.times = hold.times+1;
                if(!isVisited(h1))
                    q.push(h1);
            }
            else
            {
                h1.b = hold.b-(a-hold.a);
                h1.a = a;
                h1.c = hold.c;
                h1.times = hold.times+1;
                if(!isVisited(h1))
                    q.push(h1);
            }
        }
        if(hold.c<c)
        {
            if(hold.b<c-hold.c)
            {
                h1.b = 0;
                h1.a = hold.a;
                h1.c = hold.c+hold.b;
                h1.times = hold.times+1;
                if(!isVisited(h1))
                    q.push(h1);
            }
            else
            {
                h1.b = hold.b-(c-hold.c);
                h1.a = hold.a;
                h1.c = c;
                h1.times = hold.times+1;
                if(!isVisited(h1))
                    q.push(h1);
            }
        }
    }
    if(hold.c)
    {
        if(hold.b<b)
        {
            if(hold.c<b-hold.b)
            {
                h1.c = 0;
                h1.b = hold.b+hold.c;
                h1.a = hold.a;
                h1.times = hold.times+1;
                if(!isVisited(h1))
                    q.push(h1);
            }
            else
            {
                h1.c = hold.c-(b-hold.b);
                h1.b = b;
                h1.a = hold.a;
                h1.times = hold.times+1;
                if(!isVisited(h1))
                    q.push(h1);
            }
        }
        if(hold.a<a)
        {
            if(hold.c<a-hold.a)
            {
                h1.c = 0;
                h1.b = hold.b;
                h1.a = hold.c+hold.a;
                h1.times = hold.times+1;
                if(!isVisited(h1))
                    q.push(h1);
            }
            else
            {
                h1.c = hold.c-(a-hold.a);
                h1.b = hold.b;
                h1.a = a;
                h1.times = hold.times+1;
                if(!isVisited(h1))
                    q.push(h1);
            }
        }
    }
    return false;
}

int main()
{
    freopen("data.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int cc=0;cc<T;cc++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        memset(visited,0,sizeof(visited));
        while(!q.empty())
            q.pop();
        bool ok = false;
        visited[0] = true;
        bottle h;
        h.a = h.b = 0;
        h.c = c;
        h.times = 0;
        dd = 0;
        ddtimes = 0;
        q.push(h);
       // cout<<"kao"<<endl;
        while(!q.empty())
        {
          //  cout<<"kao"<<endl;
            bottle hold = q.front();
            q.pop();
            bool okay = make(hold);
            if(okay)
            {
                ok = true;
                break;
            }
        }
        if(!ok)
            printf("%d %d\n",ddtimes,dd);
    }
    return 0;
}
*/



#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;

int a,b,c,d;
bool visited[41000];
int dd;
int ddtimes;

struct bottle
{
    int a;
    int b;
    int c;
    int times;
    friend bool operator < (bottle a, bottle b)
    {
        return a.times>b.times;
    }
};

priority_queue<bottle> q;

bool isVisited(bottle h)
{
    int aa = h.a*201+h.b;
    if(visited[aa])
        return true;
    visited[aa] = true;
    return false;
}

bool make(bottle hold)
{
    if(hold.a==d||hold.b==d||hold.c==d)
    {
        printf("%d %d\n",hold.times,d);
        return true;
    }
    int close = 0;
    if(hold.a>close&&hold.a<d)
        close = hold.a;
    if(hold.b>close&&hold.b<d)
        close = hold.b;
    if(hold.c>close&&hold.c<d)
        close = hold.c;
    if(close>dd)
    {
        dd = close;
        ddtimes = hold.times;
    }
    bottle h1;
    if(hold.a)
    {
        if(hold.b<b)
        {
            if(hold.a<b-hold.b)
            {
                h1.a = 0;
                h1.b = hold.b+hold.a;
                h1.c = hold.c;
                h1.times = hold.times+hold.a;
                if(!isVisited(h1))
                    q.push(h1);
            }
            else
            {
                h1.a = hold.a-(b-hold.b);
                h1.b = b;
                h1.c = hold.c;
                h1.times = hold.times+b-hold.b;
                if(!isVisited(h1))
                    q.push(h1);
            }
        }
        if(hold.c<c)
        {
            if(hold.a<c-hold.c)
            {
                h1.a = 0;
                h1.b = hold.b;
                h1.c = hold.c+hold.a;
                h1.times = hold.times+hold.a;
                if(!isVisited(h1))
                    q.push(h1);
            }
            else
            {
                h1.a = hold.a-(c-hold.c);
                h1.b = hold.b;
                h1.c = c;
                h1.times = hold.times+c-hold.c;
                if(!isVisited(h1))
                    q.push(h1);
            }
        }
    }
    if(hold.b)
    {
        if(hold.a<a)
        {
            if(hold.b<a-hold.a)
            {
                h1.a = hold.a + hold.b;
                h1.b = 0;
                h1.c = hold.c;
                h1.times = hold.times+hold.b;
                if(!isVisited(h1))
                    q.push(h1);
            }
            else
            {
                h1.b = hold.b-(a-hold.a);
                h1.a = a;
                h1.c = hold.c;
                h1.times = hold.times+a-hold.a;
                if(!isVisited(h1))
                    q.push(h1);
            }
        }
        if(hold.c<c)
        {
            if(hold.b<c-hold.c)
            {
                h1.b = 0;
                h1.a = hold.a;
                h1.c = hold.c+hold.b;
                h1.times = hold.times+hold.b;
                if(!isVisited(h1))
                    q.push(h1);
            }
            else
            {
                h1.b = hold.b-(c-hold.c);
                h1.a = hold.a;
                h1.c = c;
                h1.times = hold.times+c-hold.c;
                if(!isVisited(h1))
                    q.push(h1);
            }
        }
    }
    if(hold.c)
    {
        if(hold.b<b)
        {
            if(hold.c<b-hold.b)
            {
                h1.c = 0;
                h1.b = hold.b+hold.c;
                h1.a = hold.a;
                h1.times = hold.times+hold.c;
                if(!isVisited(h1))
                    q.push(h1);
            }
            else
            {
                h1.c = hold.c-(b-hold.b);
                h1.b = b;
                h1.a = hold.a;
                h1.times = hold.times+b-hold.b;
                if(!isVisited(h1))
                    q.push(h1);
            }
        }
        if(hold.a<a)
        {
            if(hold.c<a-hold.a)
            {
                h1.c = 0;
                h1.b = hold.b;
                h1.a = hold.c+hold.a;
                h1.times = hold.times+hold.c;
                if(!isVisited(h1))
                    q.push(h1);
            }
            else
            {
                h1.c = hold.c-(a-hold.a);
                h1.b = hold.b;
                h1.a = a;
                h1.times = hold.times+a-hold.a;
                if(!isVisited(h1))
                    q.push(h1);
            }
        }
    }
    return false;
}

int main()
{
    //freopen("data.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int cc=0;cc<T;cc++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        memset(visited,0,sizeof(visited));
        while(!q.empty())
            q.pop();
        bool ok = false;
        visited[0] = true;
        bottle h;
        h.a = h.b = 0;
        h.c = c;
        h.times = 0;
        dd = 0;
        ddtimes = 0;
        q.push(h);
       // cout<<"kao"<<endl;
        while(!q.empty())
        {
          //  cout<<"kao"<<endl;
            bottle hold = q.top();
            q.pop();
            bool okay = make(hold);
            if(okay)
            {
                ok = true;
                break;
            }
        }
        if(!ok)
            printf("%d %d\n",ddtimes,dd);
    }
    return 0;
}


