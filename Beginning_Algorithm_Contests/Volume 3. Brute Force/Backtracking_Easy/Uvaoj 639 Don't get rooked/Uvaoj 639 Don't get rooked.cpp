#include<cstdio>
#include<algorithm>
using namespace std;

struct rook
{
    int row;
    int col;
};

int n;
char s[10][10];
rook r[20];
int mm;

bool valid(int row, int col, int nRook)
{
    if(s[row][col]=='X')
        return false;
    for(int i=0;i<nRook;i++)
    {
        if(r[i].row==row&&r[i].col==col)
            return false;
        if(r[i].row==row)
        {
            int start = min(r[i].col,col);
            int finish = max(r[i].col,col);
            bool ok = true;
            for(int j=start+1;j<finish;j++)
                if(s[row][j]=='X')
                    ok = false;
            if(ok)
                return false;
        }
        if(r[i].col==col)
        {
            int start = min(r[i].row,row);
            int finish = max(r[i].row,row);
            bool ok = true;
            for(int j=start+1;j<finish;j++)
                if(s[j][col]=='X')
                    ok = false;
            if(ok)
                return false;
        }
    }
    return true;
}

void dfs(int nRook, int position)
{
    if(nRook>mm)
        mm = nRook;
    if(position>=n*n)
        return;
    for(int i=position+1;i<n*n;i++)
    {
        int row = i/n;
        int col = i-row*n;
        if(valid(row,col,nRook))
        {
            r[nRook].row = row;
            r[nRook].col = col;
            dfs(nRook+1,i);
        }
    }
}

int main()
{
    //freopen("data.txt","r",stdin);
    while(scanf("%d",&n)&&n)
    {
        mm = 0;
        for(int i=0;i<n;i++)
            scanf("%s",s[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(valid(i,j,0))
                {
                    r[0].row = i;
                    r[0].col = j;
                    dfs(1,i*n+j);
                }
        printf("%d\n",mm);
    }
    return 0;
}
