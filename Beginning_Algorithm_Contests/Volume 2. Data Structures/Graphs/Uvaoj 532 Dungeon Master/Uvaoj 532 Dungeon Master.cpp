#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 35;

int L, R, C;
int sx, sy, sz, dx, dy, dz;
char h[maxn][maxn][maxn];
int maze[maxn][maxn][maxn];

int ina[6] = {0,0,0,0,1,-1};
int inb[6] = {1,-1,0,0,0,0};
int inc[6] = {0,0,1,-1,0,0};

struct point{
	int x, y, z, t;
	point(int x, int y, int z, int t):x(x),y(y),z(z),t(t){}
};

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d%d%d",&L, &R, &C) && L){
		for(int i=0;i<L;i++)
			for(int j=0;j<R;j++)
				scanf("%s",h[i][j]);
		memset(maze, -1, sizeof(maze));
		for(int i=0;i<L;i++)
			for(int j=0;j<R;j++)
				for(int k=0;k<C;k++){
					if(h[i][j][k] == '.')
						maze[i+1][j+1][k+1] = 0;
					if(h[i][j][k] == 'S'){
						sx = i+1;
						sy = j+1;
						sz = k+1;
						maze[i+1][j+1][k+1] = 0;
					}
					if(h[i][j][k] == 'E'){
						dx = i+1;
						dy = j+1;
						dz = k+1;
						maze[i+1][j+1][k+1] = 0;
					}
				}
		queue<point> q;
		q.push(point(sx,sy,sz,0));
		maze[sx][sy][sz] = -1;
		bool ok = false;
		while(!q.empty()){
			point now = q.front();
			q.pop();
			if(now.x == dx && now.y == dy && now.z == dz){
				ok = true;
				printf("Escaped in %d minute(s).\n", now.t);
			}
			for(int i=0;i<6;i++){
				point next = point(now.x+ina[i], now.y+inb[i], now.z+inc[i], now.t+1);
				if(maze[next.x][next.y][next.z] == 0){
					maze[next.x][next.y][next.z] = -1;
					q.push(next);
				}
			}
		}
		if(!ok)
			printf("Trapped!\n");
	}
	return 0;
}