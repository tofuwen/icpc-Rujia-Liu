#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;


vector<int> g[30];
int current[30];
char command[100];
int n;

void do1(int a,int b);
void do2(int a,int b);
void do3(int a,int b);
void do4(int a,int b);
void ans();

int main()
{
    //freopen("data.in","r",stdin);
    cin>>n;
    getchar();
    for(int i=0;i<n;i++)
    {
        g[i].push_back(i);
        current[i] = i;
    }
    while(1)
    {
        gets(command);
        //cout<<command<<endl;
        if(command[0]=='q')
            break;
        int a,b;
        char c1[10],c2[10];
        sscanf(command,"%s %d %s %d",c1,&a,c2,&b);
        //ans();
        if(current[a]==current[b])
            continue;
        if(c1[0]=='m'&&c2[1]=='n')
        {
            do1(a,b);
        }
        if(c1[0]=='m'&&c2[1]=='v')
        {
            do2(a,b);
        }
        if(c1[0]=='p'&&c2[1]=='n')
        {
            do3(a,b);
        }
        if(c1[0]=='p'&&c2[1]=='v')
        {
            do4(a,b);
        }
        //cout<<c1<<' '<<a<<' '<<c2<<' '<<b<<endl;
    }
    ans();
    return 0;
}

void do1(int a,int b)
{
    bool ok = false;
    int p;
    for(int i=0;i<g[current[a]].size();i++)
    {
        int x = g[current[a]][i];
        if(ok)
        {
            g[x].push_back(x);
            current[x] = x;
        }
        if(x==a)
        {
            ok = true;
            p=i;
        }
    }
    g[current[a]].erase(g[current[a]].begin()+p,g[current[a]].begin()+g[current[a]].size());
    ok =false;
    for(int i=0;i<g[current[b]].size();i++)
    {
        int x = g[current[b]][i];
        if(ok)
        {
            g[x].push_back(x);
            current[x] = x;
        }
        if(x==b)
        {
            ok = true;
            p=i;
        }
    }
    g[current[b]].erase(g[current[b]].begin()+p+1,g[current[b]].begin()+g[current[b]].size());
    g[current[b]].push_back(a);
    current[a] = current[b];
}



void do2(int a,int b)
{
    bool ok = false;
    int p;
    for(int i=0;i<g[current[a]].size();i++)
    {
        int x = g[current[a]][i];
        if(ok)
        {
            g[x].push_back(x);
            current[x] = x;
        }
        if(x==a)
        {
            ok = true;
            p=i;
        }
    }
    g[current[a]].erase(g[current[a]].begin()+p,g[current[a]].begin()+g[current[a]].size());
    g[current[b]].push_back(a);
    current[a] = current[b];
}


void do3(int a,int b)
{
    bool ok = false;
    int p;
    for(int i=0;i<g[current[b]].size();i++)
    {
        int x = g[current[b]][i];
        if(ok)
        {
            g[x].push_back(x);
            current[x] = x;
        }
        if(x==b)
        {
            ok = true;
            p=i;
        }
    }
    g[current[b]].erase(g[current[b]].begin()+p+1,g[current[b]].begin()+g[current[b]].size());
    ok = false;
    int m = current[a];
    for(int i=0;i<g[m].size();i++)
    {
        int x = g[m][i];
        if(x==a)
        {
            ok = true;
            p=i;
        }
        if(ok)
        {
            g[current[b]].push_back(x);
            current[x] = current[b];
        }
    }
    g[m].erase(g[m].begin()+p,g[m].begin()+g[m].size());
}


void do4(int a,int b)
{
    bool ok = false;
    int p;
    int m = current[a];
    for(int i=0;i<g[m].size();i++)
    {
        int x = g[m][i];
        if(x==a)
        {
            ok = true;
            p=i;
        }
        if(ok)//current[a]改变了！这样的bug真是不好找···
        {
            g[current[b]].push_back(x);
            current[x] = current[b];
        }
    }
    g[m].erase(g[m].begin()+p,g[m].begin()+g[m].size());
}


void ans()
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<":";
        for(int j=0;j<g[i].size();j++)
            cout<<' '<<g[i][j];
        cout<<endl;
    }
}




















