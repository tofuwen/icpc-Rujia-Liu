//哈哈！这个算法竟然真的可以啊！！！
//但是我还是不会构造二叉树啊，用这题的输入构造二叉树感觉好麻烦···
//但是好在有些时候根本不需要构造二叉树出来！比如这题我用的就是stack嘛！

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int n;
bool ok;
char c[10000];
int s[10000];
int sum[10000];
bool nnum[10000];
bool leaf[10000];

int f(int hold);

int main()
{
    //freopen("data.in","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        memset(s,0,sizeof(s));
        memset(nnum,0,sizeof(nnum));
        memset(leaf,1,sizeof(leaf));
        ok = false;
        int start = 0;
        int num = 0;
        scanf("%s",c);
        while(1)
        {
            int d = strlen(c+start);
            for(int i=0;i<d;i++)
            {
                if(c[start+i]=='(')
                    num++;
                if(c[start+i]==')')
                    num--;
            }
            if(num==0)
                break;
            scanf("%s",c+start+d);
            start += d;
        }
        if(strcmp(c,"()")==0)
        {
            cout<<"no"<<endl;
            continue;
        }
        int d = strlen(c);
        int hold;
        int count = -1;
        int i = 0;
        while(i<d)
        {
            if((c[i]>='0'&&c[i]<='9')||c[i]=='-')//第一次WA是因为没考虑'0'···
            {
                sscanf(c+i,"%d",&hold);
                if(count>=0)
                    leaf[count] = false;
                s[++count] = hold;
               // for(int i=0;i<=count;i++)
                //    cout<<s[i]<<' ';
               // cout<<endl;
                sum[count] = count>0?sum[count-1]+hold:hold;
                if(c[i]=='-')
                    i += f(abs(hold))+1;
                else
                    i += f(hold);
            }
            else
            {
                if(c[i]==')')
                {
                    if(nnum[count]==false)
                        nnum[count] = true;
                    else
                    {
                        nnum[count] = false;
                        if(leaf[count]==true)
                        {
                            if(sum[count]==n)
                            {
                                cout<<"yes"<<endl;
                                ok = true;
                                break;
                            }
                        }
                        else
                            leaf[count] = true;
                        count--;
                    }
                }
                i++;
            }
        }
        if(ok)
            continue;
        cout<<"no"<<endl;
    }
    return 0;
}

int f(int hold)
{
    if(hold==0)
        return 1;
    int num = 0;
    while(hold>0)
    {
        hold /= 10;
        num++;
    }
    return num;
}










