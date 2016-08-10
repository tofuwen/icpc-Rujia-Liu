#include<cstdio>
using namespace std;

int N;

int cherry[110][2];

int main()
{
  //  freopen("data.txt","r",stdin);
    while(scanf("%d",&N)&&N)
    {
        bool ok = false;
        for(int i=0;i<2*N;i++)
            scanf("%d%d",&cherry[i][0],&cherry[i][1]);
        for(int i=-500;i<=500;i++)
        {
            for(int j=-500;j<=500;j++)
            {
                int negative=0, positive = 0;
                for(int k=0;k<2*N;k++)
                {
                    int h = i*cherry[k][0]+j*cherry[k][1];
                    if(h==0)
                        break;
                    if(h<0)
                        negative++;
                    else
                        positive++;
                }
                if(positive==N&&negative==N)
                {
                    printf("%d %d\n",i,j);
                    ok = true;
                    break;
                }
            }
            if(ok)
                break;
        }
    }
    return 0;
}
