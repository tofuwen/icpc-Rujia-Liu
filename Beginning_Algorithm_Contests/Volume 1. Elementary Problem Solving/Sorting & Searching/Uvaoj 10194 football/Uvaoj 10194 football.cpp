#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

char tournament[110];
int nTeam;
int G;
char hold[1000];

void toUpperCase(char c[], int l)
{
    for(int i=0;i<l;i++)
        if(c[i]>='a'&&c[i]<='z')
            c[i] = c[i]-'a'+'A';
}

struct team
{
    int teamRank;
    char name[35];
    int totalPoint = 0;
    int gamesPlayed = 0;
    int wins = 0;
    int ties = 0;
    int losses = 0;
    int goalDifference = 0;
    int goalScored = 0;
    int goalAgainst = 0;
    friend bool operator < (const team& a, const team& b)
    {
        if(a.totalPoint!=b.totalPoint)
            return a.totalPoint>b.totalPoint;
        if(a.wins!=b.wins)
            return a.wins>b.wins;
        if(a.goalDifference!=b.goalDifference)
            return a.goalDifference>b.goalDifference;
        if(a.goalScored!=b.goalScored)
            return a.goalScored>b.goalScored;
        if(a.gamesPlayed!=b.gamesPlayed)
            return a.gamesPlayed<b.gamesPlayed;
        char name1[35],name2[35];
        strcpy(name1,a.name);
        strcpy(name2,b.name);
        toUpperCase(name1,strlen(name1));
        toUpperCase(name2,strlen(name2));
        return strcmp(name1,name2)<0;
    }
};

team t[35];

void reset()
{
    for(int i=0;i<35;i++)
    {
        t[i].totalPoint = 0;
        t[i].gamesPlayed = 0;
        t[i].wins = 0;
        t[i].ties = 0;
        t[i].losses = 0;
        t[i].goalDifference = 0;
        t[i].goalScored = 0;
        t[i].goalAgainst = 0;
    }
}

int searchName(char name[])
{
    for(int i=0;i<nTeam;i++)
        if(strcmp(t[i].name,name)==0)
            return i;
    return -1;
}

void operate()
{
    char* h = strchr(hold,'#');
    char name1[35],name2[35];
    int l1 = h-hold;
    for(int i=0;i<l1;i++)
        name1[i] = hold[i];
    name1[l1] = '\0';
    h++;
    int score1,score2;
    sscanf(h,"%d",&score1);
    h = strchr(hold,'@');
    h++;
    sscanf(h,"%d",&score2);
    char* h2 = strchr(h,'#');
    h2++;
    int l2 = h2 - hold;
    int D =strlen(hold);
    for(int i=l2;i<D;i++)
        name2[i-l2] = hold[i];
    name2[D-l2] = '\0';
    int t1 = searchName(name1);
    int t2 = searchName(name2);
    t[t1].gamesPlayed++;
    t[t2].gamesPlayed++;
    t[t1].goalScored += score1;
    t[t2].goalScored += score2;
    t[t1].goalAgainst += score2;
    t[t2].goalAgainst += score1;
    t[t1].goalDifference += (score1-score2);
    t[t2].goalDifference += (score2-score1);
    if(score1>score2)
    {
        t[t1].totalPoint += 3;
        t[t1].wins++;
        t[t2].losses++;
    }
    if(score1==score2)
    {
        t[t1].totalPoint++;
        t[t1].ties++;
        t[t2].totalPoint++;
        t[t2].ties++;
    }
    if(score1<score2)
    {
        t[t2].totalPoint += 3;
        t[t2].wins++;
        t[t1].losses++;
    }
}
void print()
{
    puts(tournament);
    for(int i=0;i<nTeam;i++)
    {
        printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
        i+1,t[i].name,t[i].totalPoint,t[i].gamesPlayed,t[i].wins,t[i].ties,t[i].losses,
        t[i].goalDifference,t[i].goalScored,t[i].goalAgainst);
    }
}


int main()
{
   // freopen("data.txt","r",stdin);
    int T;
    scanf("%d",&T);
    getchar();
    for(int cc=1;cc<=T;cc++)
    {
        reset();
        gets(tournament);
        scanf("%d",&nTeam);
        getchar();
        for(int i=0;i<nTeam;i++)
            gets(t[i].name);
        scanf("%d",&G);
        getchar();
        for(int i=0;i<G;i++)
        {
            gets(hold);
            operate();
        }
        sort(t,t+nTeam);
        for(int i=0;i<nTeam;i++)
            t[i].teamRank = i+1;
        if(cc!=1)
            putchar('\n');
        print();
    }
    return 0;
}
