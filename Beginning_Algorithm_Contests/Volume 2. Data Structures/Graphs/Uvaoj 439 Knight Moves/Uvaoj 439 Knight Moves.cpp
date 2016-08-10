#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

struct point
{
    int x;
    int y;
    int step;
};

char start[10];
char destination[10];
bool visited[10][10];
int a[8] = {2,2,-2,-2,1,1,-1,-1};
int b[8] = {1,-1,1,-1,2,-2,2,-2};
point s;
point d;

queue<point> q;

bool out(int x, int y)
{
    if(x<1||x>8||y<1||y>8)
        return true;
    if(visited[x][y])
        return true;
    return false;
}

bool equals(point a, point b)
{
    return a.x==b.x&&a.y==b.y;
}

int main()
{
   // freopen("data.txt","r",stdin);
    while(scanf("%s%s",start,destination)!=EOF)
    {
        memset(visited,0,sizeof(visited));
        s.x = start[0]-'a'+1;
        s.y = start[1]-'0';
        s.step = 0;
        d.x = destination[0]-'a'+1;
        d.y = destination[1]-'0';
        while(!q.empty())
            q.pop();
        q.push(s);
        visited[s.x][s.y] = true;
        while(!q.empty())
        {
            point h = q.front();
            q.pop();
            if(equals(h,d))
            {
                printf("To get from %s to %s takes %d knight moves.\n",start,destination,h.step);
                break;
            }
            for(int i=0;i<8;i++)
            {
                point hold;
                hold.x = h.x+a[i];
                hold.y = h.y+b[i];
                hold.step = h.step+1;
                if(!out(hold.x,hold.y))
                {
                    q.push(hold);
                    visited[hold.x][hold.y] = true;
                }

            }
        }
    }
    return 0;
}

























