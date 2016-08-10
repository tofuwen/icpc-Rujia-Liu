#include<cstdio>
#include<cstring>
#define MAXN 55
using namespace std;

char s[10];

typedef struct card
{
    char num;
    char suit;
}Card;

Card makeCard(char s[])
{
    Card n;
    n.num = s[0];
    n.suit = s[1];
    return n;
}

bool isMatch(Card a, Card b)
{
    return (a.num==b.num)||(a.suit==b.suit);
}

int numPiles;
int numCards[MAXN];
int indexPiles[MAXN];
Card g[MAXN][MAXN];
int current;

void Move(int from, int to)
{
    g[indexPiles[to]][numCards[to]] = g[indexPiles[from]][numCards[from]-1];
    numCards[to]++;
    numCards[from]--;
    if(numCards[from]==0)
    {
        for(int i=from;i<numPiles-1;i++)
        {
            numCards[i] = numCards[i+1];
            indexPiles[i] = indexPiles[i+1];
        }
        numPiles--;
    }
}

bool check()
{
    for(int i=1;i<numPiles;i++)
    {
        if(i>=3)
        {
            if(isMatch(g[indexPiles[i]][numCards[i]-1],g[indexPiles[i-3]][numCards[i-3]-1]))
            {
                Move(i,i-3);
                return true;
            }
        }
        if(isMatch(g[indexPiles[i]][numCards[i]-1],g[indexPiles[i-1]][numCards[i-1]-1]))
        {
            Move(i,i-1);
            return true;
        }
    }
    return false;
}

void show()
{
    for(int i=0;i<numPiles;i++)
    {
        for(int j=0;j<numCards[i];j++)
            printf("%c%c ",g[indexPiles[i]][j].suit,g[indexPiles[i]][j].num);
        putchar('\n');
    }
}

int main()
{
    //freopen("data.txt","r",stdin);
    //freopen("dataout.txt","w",stdout);
    while(1)
    {
        scanf("%s",s);
        if(s[0]=='#') break;
        numPiles = current = 0;
        memset(numCards,0,sizeof(numCards));
        Card newOne = makeCard(s);
        g[current][0] = newOne;
        indexPiles[numPiles] = current;
        numCards[numPiles]++;
        numPiles++;
        current++;
        for(int i=0;i<51;i++)
        {
            scanf("%s",s);
            newOne = makeCard(s);
            g[current][0] = newOne;
            indexPiles[numPiles] = current;
            numCards[numPiles]++;
            numPiles++;
            current++;
            //if(i<10)
           // {
            //    printf("%d turn:\n",i+2);
           //     show();
           // }

          //  while(check());
        }
        while(check());
        if(numPiles>1)
            printf("%d piles remaining:",numPiles);
        else
            printf("%d pile remaining:",numPiles);
        for(int i=0;i<numPiles;i++)
            printf(" %d",numCards[i]);
        putchar('\n');
    }
    return 0;
}
















