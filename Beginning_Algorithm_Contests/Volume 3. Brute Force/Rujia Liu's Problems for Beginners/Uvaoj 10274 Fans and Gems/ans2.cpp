#include <stdio.h>  
#include <string.h>  
  
const int MAXN = 100005;  
const int R = 15;  
const int C = 22;  
const int dir[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};  
const char sign[5] = "DLRU";  
  
struct Map {  
    char state[R][C];  
    char order[C];  
    int cnt;  
}aid, begin;  
int sumPace, sumGem;  
int r, c;  

void print(Map m){
    for(int i=0;i<m.cnt;i++)
        printf("%c", m.order[i]);
    printf("\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%c", m.state[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
  
bool isGem(char c) {  
    if (c > '0' && c < '4' || c == '@')  
    return true;  
    return false;  
}  
  
void flyGem(Map now, int& x, int& y, int d) {  
    do {  
    x += dir[d][0];  
    y += dir[d][1];  
    }while (!isGem(now.state[x][y]) && now.state[x][y] != '#');  
    x -= dir[d][0];  
    y -= dir[d][1];  
}  
  
void moveGem(Map& now, int d) {  
    int x, y;  
    if (d == 0) {  
    for (int i = r - 1; i >= 0; i--) {  
        for (int j = 0; j < c; j++) {  
        if (isGem(now.state[i][j])) {  
            x = i, y = j;  
            flyGem(now, x, y, d);  
            now.state[x][y] = now.state[i][j];  
            if (x != i || y != j)  
            now.state[i][j] = ' ';  
        }  
        }  
    }  
    }  
    else {  
    for (int i = 0; i < r; i++) {  
        if (d == 1) {  
        for (int j = 0; j < c; j++) {  
            if (isGem(now.state[i][j])) {  
            x = i, y = j;  
            flyGem(now, x, y, d);  
            now.state[x][y] = now.state[i][j];  
            if (x != i || y != j)  
                now.state[i][j] = ' ';  
            }  
        }  
        }  
        else {  
        for (int j = c - 1; j >= 0; j--) {  
            if (isGem(now.state[i][j])) {  
            x = i, y = j;  
            flyGem(now, x, y, d);  
            now.state[x][y] = now.state[i][j];  
            if (x != i || y != j)  
                now.state[i][j] = ' ';  
            }  
        }  
        }  
    }  
    }  
}  
///////////////////////////////////////////////////////////  
Map que[MAXN];  
int head[MAXN], next[MAXN], dist[MAXN];  
  
void inInit() {  
    memset(head, 0, sizeof(head));  
    memset(que, 0, sizeof(que));  
    memcpy(que[1].state, begin.state, sizeof(begin.state));  
    dist[1] = 0;  
}  
  
inline int hash(Map &cur){    
    int seed = 131, v = 0;    
    for(int i = 0; i < r; ++i){    
    for(int j = 0; j < c; ++j)    
        v = (v * seed + cur.state[i][j]) & 0x7FFFFFFF;    
    }    
    return v % MAXN;    
}   
  
bool tryInsert(int cur) {  
    int h = hash(que[cur]);  
    int u = head[h];  
    while (u) {  
    if (memcmp(que[cur].state, que[u].state, sizeof(que[u].state)) == 0)  
        return false;  
    u = next[u];  
    }  
    next[cur] = head[h];  
    head[h] = cur;  
    return true;  
}  
  
int dfs(Map& now, int x, int y, int ch) {  
    int sum = 0;  
    for (int i = 0; i < 4; i++)  
    if (ch == now.state[x + dir[i][0]][y + dir[i][1]]) {  
        now.state[x + dir[i][0]][y + dir[i][1]] = ' ';  
        sum += dfs(now, x + dir[i][0], y + dir[i][1], ch);  
    }  
    return sum + 1;   
}  
  
int delGem(Map& now) {  
    int sum = 0;  
    char ch;  
    for (int x = 0; x < r; x++) {  
    for (int y = 0; y < c; y++) {  
        int flag = 0;  
        for (int i = 0; i < 4; i++) {  
        if (now.state[x][y] == now.state[x + dir[i][0]][y + dir[i][1]] && isGem(now.state[x][y]) && now.state[x][y] != '@') {  
            flag = 1;  
            ch = now.state[x][y];  
            now.state[x][y] = ' ';  
            break;  
        }  
        }  
  
        if (flag)  
        sum += dfs(now, x, y, ch);  
    }  
    }  
    return sum;  
}  
  
bool bfs() {  
    int front = 1, rear = 2, k;  
    inInit();  
  
    while (front < rear) {  
    Map& now = que[front];  
  
    if (dist[front] > 18)  
        return false;  
    if (now.cnt == sumGem) {  
        aid = que[front];  
        sumPace = dist[front];  
        return true;  
    }  
  
    for (int i = 0; i < 4; i++) {  
        Map& net = que[rear];  
        net = now;  
  
        net.order[dist[front]] = sign[i];  
        while (1) {  
        moveGem(net, i);  
        print(net);
        k = delGem(net);  
        if (k == 0) break;  
        else net.cnt += k;  
        }  
  
  
        if (tryInsert(rear)) {  
        dist[rear] = dist[front]  + 1;  
        rear++;  
        }  
    }  
    front++;  
    }  
    return false;  
}  
  
int main() {  
    freopen("input1.txt", "r",stdin);
    freopen("datainput1out.txt", "w", stdout);
    int cas;  
    char str[1000];  
    scanf("%d", &cas);  
    while (cas--) {  
    // Init;  
    sumPace = sumGem = 0;  
  
    // Read;  
    scanf("%d%d%*c", &r, &c);  
    for (int i = 0; i < r; i++) {  
        gets(begin.state[i]);  
        int len = strlen(begin.state[i]);  
        for (int j = 0; j < len; j++)  
        if (begin.state[i][j] > '0' && begin.state[i][j] < '4')  
            sumGem++;  
    }  
    gets(str);  
  
    if (bfs()) {  
        aid.order[sumPace] = '\0';  
        puts(aid.order);  
    }  
    else  
        printf("-1\n");  
    }  
    return 0;  
}  