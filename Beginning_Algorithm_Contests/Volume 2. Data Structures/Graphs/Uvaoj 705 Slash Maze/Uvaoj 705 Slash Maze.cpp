#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 80;

struct point{
	int x, y;
	point(int x, int y):x(x),y(y){}
	point(){}
};

int w, h;
int cycle;

char slashMaze[maxn][maxn];
bool maze[2*maxn+1][maxn+1];

bool outOfBound(point p){
	int i = p.x;
	int j = p.y;
	if(i<0 || i>2*h)
		return true;
	if(j<0)
		return true;
	if(i%2 == 0 && j>=w)
		return true;
	if(i%2 == 1 && j>w)
		return true;
	return false;
}

bool slashOutOfBound(point slash){
	if(slash.x < 0 || slash.x >= h || slash.y < 0 || slash.y >= w)
		return true;
	return false;
}

char get(point slash){
	return slashMaze[slash.x][slash.y];
}

bool bfs(int i, int j, int& num){
	bool ans = true;
	num = 1;
	queue<point> q;
	maze[i][j] = true;
	q.push(point(i,j));
	while(!q.empty()){
		point now = q.front();
		q.pop();
		int x = now.x;
		int y = now.y;
		point slash1, slash2;
		if(x%2 == 0){
			slash1 = point(x/2-1, y);
			slash2 = point(x/2, y);
			if(!slashOutOfBound(slash1)){
				char c = get(slash1);
				if(c == '/'){
					point next = point(x-1, y+1);
					if(outOfBound(next))
						ans = false;
					else{
						if(!maze[next.x][next.y]){
							maze[next.x][next.y] = true;
							num++;
							q.push(next);
						}
					}
				}
				else{
					point next = point(x-1, y);
					if(outOfBound(next))
						ans = false;
					else{
						if(!maze[next.x][next.y]){
							maze[next.x][next.y] = true;
							num++;
							q.push(next);
						}
					}
				}
			}
			else
				ans = false;
			if(!slashOutOfBound(slash2)){
				char c = get(slash2);
				if(c == '/'){
					point next = point(x+1, y);
					if(outOfBound(next))
						ans = false;
					else{
						if(!maze[next.x][next.y]){
							maze[next.x][next.y] = true;
							num++;
							q.push(next);
						}
					}
				}
				else{
					point next = point(x+1, y+1);
					if(outOfBound(next))
						ans = false;
					else{
						if(!maze[next.x][next.y]){
							maze[next.x][next.y] = true;
							num++;
							q.push(next);
						}
					}
				}
			}
			else
				ans = false;
		}
		else{
			slash1 = point(x/2, y-1);
			slash2 = point(x/2, y);
			if(!slashOutOfBound(slash1)){
				char c = get(slash1);
				if(c == '/'){
					point next = point(x+1, y-1);
					if(outOfBound(next))
						ans = false;
					else{
						if(!maze[next.x][next.y]){
							maze[next.x][next.y] = true;
							num++;
							q.push(next);
						}
					}
				}
				else{
					point next = point(x-1, y-1);
					if(outOfBound(next))
						ans = false;
					else{
						if(!maze[next.x][next.y]){
							maze[next.x][next.y] = true;
							num++;
							q.push(next);
						}
					}
				}
			}
			else
				ans = false;
			if(!slashOutOfBound(slash2)){
				char c = get(slash2);
				if(c == '/'){
					point next = point(x-1, y);
					if(outOfBound(next))
						ans = false;
					else{
						if(!maze[next.x][next.y]){
							maze[next.x][next.y] = true;
							num++;
							q.push(next);
						}
					}
				}
				else{
					point next = point(x+1, y);
					if(outOfBound(next))
						ans = false;
					else{
						if(!maze[next.x][next.y]){
							maze[next.x][next.y] = true;
							num++;
							q.push(next);
						}
					}
				}
			}
			else
				ans = false;
		}
	}
	return ans;
}

int ans;

int main()
{
	//freopen("data.txt","r",stdin);
	int kase = 0;
	while(scanf("%d%d",&w, &h) && w){
		for(int i=0;i<h;i++)
			scanf("%s", slashMaze[i]);
		memset(maze, 0, sizeof(maze));
		int num;
		ans = cycle = 0;
		for(int i=0;i<2*h+1;i++)
			for(int j=0;j<w+1;j++)
				if(!outOfBound(point(i,j)) && !maze[i][j]){
					bool ok = bfs(i,j,num);
					if(ok){
						ans = max(ans, num);
						cycle++;
					}
				}
		if(cycle)
			printf("Maze #%d:\n%d Cycles; the longest has length %d.\n\n",++kase, cycle, ans);
		else
			printf("Maze #%d:\nThere are no cycles.\n\n",++kase);
	}
	return 0;
}