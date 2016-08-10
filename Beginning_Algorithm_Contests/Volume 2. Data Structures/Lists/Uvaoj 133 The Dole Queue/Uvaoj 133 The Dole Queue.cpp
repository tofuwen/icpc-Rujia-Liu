/*
In a serious attempt to downsize (reduce) the dole queue, The New National Green Labour Rhinoceros Party has decided on the following strategy. Every day all dole applicants will be placed in a large circle, facing inwards. Someone is arbitrarily chosen as number 1, and the rest are numbered counter-clockwise up to N (who will be standing on 1's left). Starting from 1 and moving counter-clockwise, one labour official counts off k applicants, while another official starts from N and moves clockwise, counting m applicants. The two who are chosen are then sent off for retraining; if both officials pick the same person she (he) is sent off to become a politician. Each official then starts counting again at the next available person and the process continues until no-one is left. Note that the two victims (sorry, trainees) leave the ring simultaneously, so it is possible for one official to count a person already selected by the other official.

Input

Write a program that will successively read in (in that order) the three numbers (N, k and m; k, m > 0, 0 < N < 20) and determine the order in which the applicants are sent off for retraining. Each set of three numbers will be on a separate line and the end of data will be signalled by three zeroes (0 0 0).

Output

For each triplet, output a single line of numbers specifying the order in which people are chosen. Each number should be in a field of 3 characters. For pairs of numbers list the person chosen by the counter-clockwise official first. Separate successive pairs (or singletons) by commas (but there should not be a trailing comma).

Sample input

10 4 3
0 0 0
Sample output

 tex2html_wrap_inline34 4 tex2html_wrap_inline34 8, tex2html_wrap_inline34 9 tex2html_wrap_inline34 5, tex2html_wrap_inline34 3 tex2html_wrap_inline34 1, tex2html_wrap_inline34 2 tex2html_wrap_inline34 6, tex2html_wrap_inline50 10, tex2html_wrap_inline34 7

where  tex2html_wrap_inline50 represents a space.

*/

#include<cstdio>
#include<cstring>
#define MAXN 25
using namespace std;

typedef struct trainee
{
    int clockwise;
    int counterclock;
    int id;
}Trainee;

Trainee t[MAXN];
bool visited[MAXN];

int n,k,m;
int num;

void print(int x)
{
    visited[x] = true;
   // if(num!=n)
  //      putchar(',');
    if(x>=10)
        printf(" %d",x);
    else
        printf("  %d",x);
    num--;
}

int findClock(int s)
{
    int ans = s;
    for(int i=1;i<m;i++)
        ans = t[ans].clockwise;
    return ans;
}

int findCounter(int s)
{
    int ans = s;
    for(int i=1;i<k;i++)
        ans = t[ans].counterclock;
    return ans;
}

int relation(int a, int b)
{
    if(a==b)
        return 0;
    if(t[a].clockwise==b)
        return 1;
    if(t[a].counterclock==b)
        return 2;
    return 3;
}

int make(int h)
{
    Trainee hold = t[h];
    t[hold.clockwise].counterclock = hold.counterclock;
    t[hold.counterclock].clockwise = hold.clockwise;
}

int main()
{
    //freopen("data.txt","r",stdin);
    while(scanf("%d%d%d",&n,&k,&m)&&n)
    {
        for(int i=1;i<=n;i++)
        {
            t[i].id = i;
            t[i].clockwise = i-1>0?i-1:n;
            t[i].counterclock = i+1>n?1:i+1;
        }
        num = n;
        memset(visited,0,sizeof(visited));
        int sclock = n;
        int scounter = 1;
        while(1)
        {
            if(num==0) break;
            if(num==1)
            {
                for(int i=1;i<=n;i++)
                    if(!visited[i])
                    {
                        if(num!=n)
                            putchar(',');
                        print(i);
                    }

                break;
            }
            int h1 = findClock(sclock);
            int h2 = findCounter(scounter);
            int r = relation(h1,h2);
            if(r==0)
            {
                if(num!=n)
                    putchar(',');
                print(h1);
                make(h1);
                sclock = t[h1].clockwise;
                scounter = t[h1].counterclock;
            }
            if(r==1)
            {
                if(num!=n)
                    putchar(',');
                print(h2);
                print(h1);
                Trainee hold = t[h1];
                t[hold.counterclock].clockwise = t[h2].clockwise;
                hold = t[h2];
                t[hold.clockwise].counterclock = t[h1].counterclock;
                sclock = t[h2].clockwise;
                scounter = t[h1].counterclock;
            }
            if(r==2)
            {
                if(num!=n)
                    putchar(',');
                print(h2);
                print(h1);
                Trainee hold = t[h2];
                t[hold.counterclock].clockwise = t[h1].clockwise;
                hold = t[h1];
                t[hold.clockwise].counterclock = t[h2].counterclock;
                sclock = t[h1].clockwise;
                scounter = t[h2].counterclock;
            }
            if(r==3)
            {
                if(num!=n)
                    putchar(',');
                print(h2);
                print(h1);
                make(h2);
                make(h1);
                sclock = t[h1].clockwise;
                scounter = t[h2].counterclock;
            }
        }
        putchar('\n');
    }
    return 0;
}



















