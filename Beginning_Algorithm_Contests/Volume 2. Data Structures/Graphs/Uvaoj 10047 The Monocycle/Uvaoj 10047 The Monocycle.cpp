#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 30;
const int modr = 4;
char tem[maxn][maxn];
int maze[maxn][maxn];
bool v[maxn][maxn][4][5];

int m, n;
int sx, sy, tx, ty;
int a[4] = {-1,0,1,0};
int b[4] = {0,-1,0,1};

struct state
{
	int x;
	int y;
	int t; // time for rotate
	int r; // time for ride
	int dir;// 0: north 1:west 2:south 3:east
	state(int x, int y, int t, int r, int dir):x(x),y(y),t(t),r(r),dir(dir){}
	state(){}
};

queue<state> q;

bool isOk(state now){
	if(maze[now.x][now.y] == -1)
		return false;
	if(v[now.x][now.y][now.dir][now.r%5])
		return false;
	v[now.x][now.y][now.dir][now.r%5] = true;
	return true;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int kase = 0;
	while(scanf("%d%d",&m,&n) && m){
		if(kase)
			printf("\n");
		printf("Case #%d\n",++kase);
		while(!q.empty())
			q.pop();
		for(int i=0;i<m;i++)
			scanf("%s", tem[i]);
		memset(maze,-1,sizeof(maze));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++){
				if(tem[i][j] == '.')
					maze[i+1][j+1] = 0;
				if(tem[i][j] == 'S'){
					maze[i+1][j+1] = 0;
					sx = i+1;
					sy = j+1;
				}
				if(tem[i][j] == 'T'){
					maze[i+1][j+1] = 0;
					tx = i+1;
					ty = j+1;
				}
			}
		memset(v,0,sizeof(v));
		state s = state(sx,sy,0,0,0);
		q.push(s);
		v[sx][sy][0][0] = true;
		int ans;
		bool okay = false;
		while(!q.empty()){
			state now = q.front();
			q.pop();
			if(now.x == tx && now.y == ty && now.r%5 == 0){
				ans = now.r+now.t;
				okay = true;
				break;
			}
			state next[3];
			next[0] = state(now.x, now.y, now.t+1, now.r, (now.dir+1)%modr);
			next[1] = state(now.x, now.y, now.t+1, now.r, (now.dir+3)%modr);
			next[2] = state(now.x+a[now.dir], now.y+b[now.dir], now.t, now.r+1, now.dir);
			for(int i=0;i<3;i++){
				if(isOk(next[i]))
					q.push(next[i]);
			}
		}
		if(okay)
			printf("minimum time = %d sec\n", ans);
		else
			printf("destination not reachable\n");
	}
	return 0;
}