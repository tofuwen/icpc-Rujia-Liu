#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int n;
char s[100];
bool isExist[10];
int ans[1000][8];
int nAns;
char sss[3][10] = {"divine","human","evil"};
char ss[2][10] = {"day","night"};

struct statement
{
    int speaker;
    int person;
    int describe;
    bool isNot;
    //0: divine 1: human 2: evil 3: lying -1: 不是这个类型的statement
    int day;
    //0: day 1: night -1: 不是这个类型的statement
};

statement st[60];


void operate(char *s, int index)
{
    bool isTime = false;
    char name = s[0];
    st[index].speaker = s[0]-'A';
    isExist[st[index].speaker] = true;
 //   cout<<"s"<<st[index].speaker<<endl;
    char *h = strchr(s,' ');
    h++;
    char person = h[0];
    char hold = h[1];
    if(person>='A'&&person<='E')
    {
        st[index].person = person-'A';
        isExist[st[index].person] = true;
    }
    else
    {
        if(hold!='t')
            st[index].person = st[index].speaker;
        else
        {
            st[index].person = -1;
            isTime = true;
        }
    }
    char* hh = strchr(h,' ');
    hh++;
    h = strchr(hh,' ');
    hold = h[1];
    h++;
    if(isTime)
    {
        st[index].describe = -1;
        if(hold=='d')
            st[index].day = 0;
        else
            st[index].day = 1;
    }
    else
    {
        st[index].day = -1;
        if(hold=='d')
        {
            st[index].describe = 0;
            st[index].isNot = false;
        }
        if(hold=='h')
        {
            st[index].describe = 1;
            st[index].isNot = false;
        }
        if(hold=='e')
        {
            st[index].describe = 2;
            st[index].isNot = false;
        }
        if(hold=='l')
        {
            st[index].describe = 3;
            st[index].isNot = false;
        }
        if(hold=='n')
        {
            st[index].isNot = true;
            hh = strchr(h,' ');
            char des = hh[1];
            if(des=='d')
                st[index].describe = 0;
            if(des=='h')
                st[index].describe = 1;
            if(des=='e')
                st[index].describe = 2;
            if(des=='l')
                st[index].describe = 3;
        }
    }
}

bool isValid(int* people, int time)
{
    bool truth;
    for(int i=0;i<n;i++)
    {
        if(people[st[i].speaker]==0||(people[st[i].speaker]==1&&time==0))
            truth = true;
        else
            truth = false;
        if(truth)
        {
            if(st[i].day!=-1)
            {
                if(st[i].day!=time)
                    return false;
            }
            else
            {
                if(st[i].isNot==false)
                {
                    if(st[i].describe==3)
                    {
                        if(people[st[i].person]==0||(people[st[i].person]==1&&time==0))
                            return false;
                    }
                    else
                    {
                        if(st[i].describe!=people[st[i].person])
                            return false;
                    }
                }
                else
                {
                    if(st[i].describe==3)
                    {
                        if(people[st[i].person]==2||(people[st[i].person]==1&&time==1))
                            return false;
                    }
                    else
                    {
                        if(st[i].describe==people[st[i].person])
                            return false;
                    }
                }

            }
        }
        else
        {
            if(st[i].day!=-1)
            {
                if(st[i].day==time)
                    return false;
            }
            else
            {
                if(st[i].isNot==false)
                {
                     if(st[i].describe==3)
                    {
                        if(people[st[i].person]==2||(people[st[i].person]==1&&time==1))
                            return false;
                    }
                    else
                    {
                        if(st[i].describe==people[st[i].person])
                            return false;
                    }
                }
                else
                {
                    if(st[i].describe==3)
                    {
                        if(people[st[i].person]==0||(people[st[i].person]==1&&time==0))
                            return false;
                    }
                    else
                    {
                        if(st[i].describe!=people[st[i].person])
                            return false;
                    }
                }
            }
        }
    }
    for(int i=0;i<5;i++)
        ans[nAns][i] = people[i];
    ans[nAns][5] = time;
    nAns++;
    return true;
}

int main()
{
    //freopen("data.txt","r",stdin);
    int nCase = 0;
    while(scanf("%d",&n)&&n)
    {
       // cout<<n<<endl;
        nAns = 0;
        getchar();
        memset(isExist,0,sizeof(isExist));
        for(int i=0;i<n;i++)
        {
        //    cout<<s<<endl;
            gets(s);
            operate(s,i);
        }
        int people[7];
        for(people[0]=0;people[0]<3;people[0]++)
            for(people[1]=0;people[1]<3;people[1]++)
                for(people[2]=0;people[2]<3;people[2]++)
                    for(people[3]=0;people[3]<3;people[3]++)
                        for(people[4]=0;people[4]<3;people[4]++)
                            for(int time=0;time<2;time++)
                                isValid(people,time);
        if(nAns==0)
        {
            printf("Conversation #%d\nThis is impossible.\n\n",++nCase);
            continue;
        }
        printf("Conversation #%d\n",++nCase);
        bool okay = false;
        for(int i=0;i<5;i++)
        {
            if(isExist[i])
            {
                bool ok = true;
                for(int j=1;j<nAns;j++)
                {
                    if(ans[j][i]!=ans[0][i])
                    {
                        ok = false;
                        break;
                    }
                }
                if(ok)
                {
                    printf("%c is %s.\n",i+'A',sss[ans[0][i]]);
                    okay = true;
                }
            }
        }
        bool ok = true;
        for(int j=1;j<nAns;j++)
            if(ans[j][5]!=ans[0][5])
            {
                ok = false;
                break;
            }
        if(ok)
        {
            printf("It is %s.\n",ss[ans[0][5]]);
            okay = true;
        }
        if(!okay)
        {
            printf("No facts are deducible.\n\n");
        }
        else
        {
            putchar('\n');
        }
       // cout<<n<<endl;
      //  for(int i=0;i<n;i++)
      //      printf("speaker: %d\nperson: %d\ndes: %d\ntime: %d\n\n",st[i].speaker,st[i].person,st[i].describe,st[i].day);
    }
    return 0;
}























