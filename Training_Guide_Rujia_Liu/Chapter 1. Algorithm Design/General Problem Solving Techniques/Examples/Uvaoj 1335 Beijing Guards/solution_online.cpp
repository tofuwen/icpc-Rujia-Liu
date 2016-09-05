#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
  
using namespace std;  
  
const int MAXN = 100010;  
  
int arr[MAXN], front[MAXN], back[MAXN];  
int n;  
  
int judge(int num) {  
    int x = arr[1], y = num - arr[1];  
    front[1] = x;  
    back[1] = 0;  
    for (int i = 2; i <= n; i++) {  
        if (i % 2 == 1) {  
            back[i] = min(y - back[i - 1], arr[i]); //尽量往后取  
            front[i] = arr[i] - back[i];   
        }   
        else {  
            front[i] = min(x - front[i - 1], arr[i]); //尽量往前取  
            back[i] = arr[i] - front[i];  
        }    
    }  
    return front[n] == 0;   
}  
  
int main() {  
    freopen("data.txt", "r", stdin);
    // freopen("solution_out.txt", "w", stdout);
    while (scanf("%d", &n) == 1 && n) {  
        for (int i = 1; i <= n; i++)   
            scanf("%d", &arr[i]);  
  
        if (n == 1) {  
            printf("%d\n", arr[1]);  
            continue;    
        }   
  
        arr[n + 1] = arr[1];   
        int L = 0, R = 0;  
        for (int i = 1; i <= n; i++)   
            L = max(L, arr[i] + arr[i + 1]);  
  
        memset(front, 0,sizeof(front));  
        memset(back, 0,sizeof(back));  
        if (n % 2 == 1) {  
            for (int i = 1; i <= n; i++)   
                R = max(R, arr[i] * 3);  
            while (L < R) {  
                int mid = L + (R - L) / 2;  
                if (judge(mid))   
                    R = mid;  
                else  
                    L = mid + 1;   
            }   
        }  
        printf("%d\n", L);   
    }  
    return 0;  
}  