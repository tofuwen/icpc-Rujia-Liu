#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;


char s[100];

int main()
{
    while(1)
    {
        for(int i=0;i<100;i++)
            s[i] = '\0';
        int p = 0;
        bool ok = false;
        gets(s);
        int d = strlen(s);
        //cout<<d<<endl;
       // cout<<s[0]<<endl;
        if(s[0]=='#')
        {
            //cout<<"ni"<<endl;
            break;
        }

        for(int i=0;i<d-1;i++)
        {
            if(s[i]<s[i+1])
                ok = true;
        }
        if(!ok)
        {
            cout<<"No Successor"<<endl;
            continue;
        }
        //cout<<p<<endl;
        for(int i=d-1;i>0;i--)
        {
            if(s[i-1]<s[i])
            {
                p = i-1;
                break;
            }
        }
        //cout<<p<<endl;
        char h = s[p+1];
        int hold = p+1;
       // cout<<s<<endl;
        for(int i=p+1;i<d;i++)
        {
            if(s[i]<h&&s[i]>s[p])
            {
                h = s[i];
                hold = i;
            }
        }
        s[hold] = s[p];
        s[p] = h;
        //cout<<s<<endl;
        //cout<<p+1<<" "<<d<<endl;
        sort(s+p+1,s+d);
        cout<<s<<endl;
    }
    return 0;
}
