/*
//如此直白的傻算TLE是肯定的了！
//算法复杂度O(n^6)
#include<iostream>
#include<cstdio>
using namespace std;
int matrix[105][105];
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                cin>>matrix[i][j];
        int max = 0;
        for(int i=1;i<=N;i++){//行
            for(int j=1;j<=N;j++){//列
                for(int k=0;k<=N-i;k++){
                    for(int z=0;z<=N-j;z++){
                        int sum = 0;
                        for(int y=0;y<i;y++){
                            for(int v=0;v<j;v++){
                                sum += matrix[k+y][z+v];
                            }
                        }
                        if(sum>max)
                            max = sum;
                    }
                }
            }
        }
        cout<<max<<endl;
    }
}
*/

//每个坐标存左上矩形的总和,算法复杂度O(n^4)。可行
#include<iostream>
#include<cstdio>
using namespace std;
int matrix[105][105];
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                cin>>matrix[i][j];
                if(j>1)
                    matrix[i][j] += matrix[i][j-1];
            }
        }
        for(int i=2;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
                matrix[i][j] += matrix[i-1][j];
        }
        for(int i=0;i<=N+1;i++)
        {
            matrix[0][i] = 0;
            matrix[N+1][i] = 0;
            matrix[i][0] = 0;
            matrix[i][N+1] = 0;
        }
        int big = 1<<30;
        int max = -big;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                for(int z=i;z<=N;z++)
                {
                    for(int k=j;k<=N;k++)
                    {
                        int hold = matrix[z][k]+matrix[i-1][j-1] - matrix[i-1][k] - matrix[z][j-1];
                        if(hold>max)
                            max = hold;
                    }
                }
            }
        }
        cout<<max<<endl;
    }
}
