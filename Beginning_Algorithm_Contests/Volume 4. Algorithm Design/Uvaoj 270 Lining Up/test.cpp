#include<cstdio>  
#include<cmath>  
#include<algorithm>  
#define MAXN 705  
using namespace std;  
struct Node{  
    int x,y;  
}arr[MAXN];  
int nIndex;  
char str[1000];  
  
inline void input(){  
    nIndex=0;  
    while(gets(str)){  
        if(!str[0])break;  
        sscanf(str,"%d%d",&arr[nIndex].x,&arr[nIndex].y);  
        ++nIndex;  
    }  
}  
  
inline bool is_in_line(int X1,int Y1,int X2,int Y2,int X3,int Y3){  
    return (X1-X2)*(Y3-Y2)-(X3-X2)*(Y1-Y2)==0;  
}  
  
void solve(){  
    int maxNum=2;  
    for(int i=0; i<nIndex; ++i){  
        for(int j=i+1; j<nIndex; ++j){  
            int cnt=2;  
            for(int k=j+1; k<nIndex; ++k){  
                if(is_in_line(arr[i].x,arr[i].y,arr[j].x,arr[j].y,arr[k].x,arr[k].y))   
                    ++cnt;  
            }  
            if(cnt>maxNum) maxNum=cnt;  
        }  
    }  
    printf("%d\n", maxNum);  
}  
  
int main(){  
   // freopen("data.txt","r",stdin);
    int T;  
    scanf("%d%*c",&T);  
    gets(str);  
    while(T--){  
        input();  
        if(nIndex==1)printf("1\n");  
        else if(nIndex==2)printf("2\n");  
        else  solve();  
        if(T) printf("\n");  
    }  
    return 0;  
}  