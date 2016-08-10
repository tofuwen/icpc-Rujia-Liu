/*
//accepted的代码
//但是有点乱···
//因为编程的时候没想清楚，花了很长时间debug！！
//错误的原因：一是一开始逻辑结构不对，二是改变了初始的矩阵的值！所以存一下就好了···
//这个代码有潜在的bug！！
//下面的代码才是好的！！

#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

int n;
int first[30];
int second[30];
int f[30];
int se[30];
char ex[1000];
bool ok;
int sum;
int cases = 0;
stack<char> s;

void make();

int main()
{
    //freopen("data.in","r",stdin);
    cin>>n;
    getchar();
    for(int i=0;i<n;i++)
    {
        char hold[100];
        fgets(hold,sizeof(hold),stdin);
        char h = hold[0];
        char hh;
        sscanf(hold,"%c %d %d",&hh,&f[h-'A'],&se[h-'A']);
    }
    while(fgets(ex,sizeof(ex),stdin)!=NULL)
    {
        for(int i=0;i<30;i++)
        {
            first[i] =  f[i];
            second[i] = se[i];
        }
        cases++;
        for(int i=0;i<s.size();i++)
            s.pop();
        ok = true;
        sum = 0;
        int d = strlen(ex);
        if(d==1)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<d;i++)
        {
            if(s.empty())
                s.push(ex[i]);
            else
            {
                if(ex[i]==')')
                {
                    char h = s.top();
                    s.pop();
                    s.pop();
                    s.push(h);
                    make();
                    if(!ok)
                        break;
                }
                if(ex[i]=='(')
                    s.push(ex[i]);
                if(ex[i]>='A'&&ex[i]<='Z')
                {
                    s.push(ex[i]);
                    make();
                    if(!ok)
                        break;

                    //if(s.top()=='(')
                  //      s.push(ex[i]);
                 //   if(s.top()>='A'&&s.top()<='Z')
                 //   {
                 //       char h = s.top();
                //        s.pop();
                 //       if(second[h-'A']!=first[ex[i]-'A'])
                  //      {
                  //          cout<<"error"<<endl;
                  //          ok = false;
                  //          break;
                   //     }
                   //     else
                   //     {
                   //         sum += first[h-'A']*first[ex[i]-'A']*second[ex[i]-'A'];
                  //          second[h-'A'] = second[ex[i]-'A'];
                 //           s.push(h);
                 //           make();
                 //       }
                 //   }

                }
            }
        }
        if(!ok)
            continue;
        cout<<sum<<endl;
    }
    return 0;
}

void make()
{
    char a = s.top();
    if(a>='A'&&a<='Z')
    {
        s.pop();
        if(!s.empty())
        {
            char b = s.top();
            if(b>='A'&&b<='Z')
            {
                if(first[a-'A']!=second[b-'A'])
                {
                    cout<<"error"<<endl;
                    ok = false;
                    return;
                }
                s.pop();
                sum += first[b-'A']*first[a-'A']*second[a-'A'];
                //cout<<cases<<" "<<first[b-'A']<<" "<<first[a-'A']<<" "<<second[a-'A']<<endl;
                //cout<<cases<<" "<<sum<<endl;
                first[a-'A'] = first[b-'A'];
            }
        }
        s.push(a);
    }
}
*/








#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

int n;
int first[30];
int second[30];
int f[30];
int se[30];
char ex[1000];
bool ok;
int sum;
stack<char> s;

void make();

int main()
{
    //freopen("data.in","r",stdin);
    cin>>n;
    getchar();
    for(int i=0;i<n;i++)
    {
        char hold[100];
        fgets(hold,sizeof(hold),stdin);
        char h = hold[0];
        sscanf(hold,"%c %d %d",&h,&f[h-'A'],&se[h-'A']);
    }
    while(fgets(ex,sizeof(ex),stdin)!=NULL)
    {
        for(int i=0;i<30;i++)
        {
            first[i] =  f[i];
            second[i] = se[i];
        }
        for(int i=0;i<s.size();i++)
            s.pop();
        ok = true;
        sum = 0;
        int d = strlen(ex);
        if(ex[d-1]=='\n')//fgets吸收到了换行！把换行扔掉！！
            d--;
        if(d==1)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<d;i++)
        {
            if(s.empty())
                s.push(ex[i]);
            else
            {
                if(ex[i]==')')
                {
                    char h = s.top();
                    s.pop();
                    s.pop();
                    s.push(h);
                    make();
                    if(!ok)
                        break;
                }
                else
                {
                    s.push(ex[i]);
                    make();
                    if(!ok)
                        break;
                }
            }
        }
        if(!ok)
            continue;
        cout<<sum<<endl;
    }
    return 0;
}

void make()
{
    char a = s.top();
    if(a>='A'&&a<='Z')
    {
        s.pop();
        if(!s.empty())
        {
            char b = s.top();
            if(b>='A'&&b<='Z')
            {
                if(first[a-'A']!=second[b-'A'])
                {
                    cout<<"error"<<endl;
                    ok = false;
                    return;
                }
                s.pop();
                sum += first[b-'A']*first[a-'A']*second[a-'A'];
                first[a-'A'] = first[b-'A'];
            }
        }
        s.push(a);
    }
}






