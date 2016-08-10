#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 15;
const int maxm = 25;
const int mod = 100001;

struct point{
	int x, y;
	point(int x, int y):x(x),y(y){}
	point(){}
	friend bool operator < (const point& a, const point& b){
		if(a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	}
	friend point operator + (const point& a, const point& b){
		return point(a.x+b.x, a.y+b.y);
	}
	friend point operator - (const point& a, const point& b){
		return point(a.x-b.x, a.y-b.y);
	}
};

struct gem{
	point p;
	char color;
	gem(point p, char color):p(p),color(color){}
	friend bool operator < (const gem& a, const gem& b){
		if(a.color == b.color)
			return a.p < b.p;
		return a.color < b.color;
	}
	friend bool operator == (const gem& a, const gem& b){
		if(a < b || b < a)
			return false;
		return true;
	}
};

int n, m;

char choice[] = {'D','L','R','U'};

vector<char> ans;
vector<vector<gem> > hash[mod];

char ori[maxn][maxm];

queue<vector<char> > q;

void print(char data[][maxm]){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			printf("%c", data[i][j]);
		printf("\n");
	}
	printf("\n");
}

bool isMove(char c){
	if((c >= '1' && c <= '3') || (c == '@'))
		return true;
	return false;
}

bool isExist(char data[][maxm]){
	vector<gem> now;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(isMove(data[i][j]))
				now.push_back(gem(point(i,j), data[i][j]));
	int v = 0;
	for(int i=0;i<min((int)now.size(),8);i++){
		v *= 10;
		v += (now[i].p.x + 1)*(now[i].p.y + 1) % 10;
	}
	int k = v % mod;
	for(int i=0;i<hash[k].size();i++)
		if(hash[k][i] == now)
			return true;
	hash[k].push_back(now);
	return false;
}

// bool isOut(int x, int y){
// 	if(x<0 || x>=n || y<0 || y>=m)
// 		return true;
// 	return false;
// }

void move(char data[][maxm], char cha, point p, char dir){
	point step;
	switch(dir){
		case 'D':{
			step = point(1,0);
			break;
		}
		case 'L':{
			step = point(0,-1);
			break;
		}
		case 'R':{
			step = point(0,1);
			break;
		}
		default:{
			step = point(-1,0);
			break;
		}
	}
	point now = p + step;
	// if(data[now.x][now.y] != ' ') // 变为每次只走一步
	// 	now = now - step;
	while(data[now.x][now.y] == ' '){
		now = now + step;
	}
	now = now - step;
	data[p.x][p.y] = ' ';
	data[now.x][now.y] = cha;
	// if(p.x == now.x && now.y == p.y)
	// 	return false;
	// return true;
}

void move(char data[][maxm], char dir){
//	bool ok = false;
	switch(dir){
		case 'D':{
			for(int i=n-1;i>=0;i--)
				for(int j=0;j<m;j++)
					if(isMove(data[i][j])){
						// if(move(data, data[i][j], point(i,j), dir))
						// 	ok = true;
						move(data, data[i][j], point(i,j), dir);
					}
			break;
		}
		case 'L':{
			for(int j=0;j<m;j++)
				for(int i=0;i<n;i++)
					if(isMove(data[i][j])){
						// if(move(data, data[i][j], point(i,j), dir))
						// 	ok = true;
						move(data, data[i][j], point(i,j), dir);
					}
			break;
		}
		case 'R':{
			for(int j=m-1;j>=0;j--)
				for(int i=0;i<n;i++)
					if(isMove(data[i][j])){
						// if(move(data, data[i][j], point(i,j), dir))
						// 	ok = true;
						move(data, data[i][j], point(i,j), dir);
					}
			break;
		}
		default:{
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					if(isMove(data[i][j])){
						// if(move(data, data[i][j], point(i,j), dir))
						// 	ok = true;
						move(data, data[i][j], point(i,j), dir);
					}
			break;
		}
	}
	//return ok;
}

void bfs(int x, int y, bool vis[][maxm], char data[][maxm]){
	int a[] = {0,0,1,-1};
	int b[] = {1,-1,0,0};
	for(int i=0;i<4;i++){
		int nx = x + a[i];
		int ny = y + b[i];
		if(!vis[nx][ny] && data[nx][ny] == data[x][y]){
			vis[x][y] = vis[nx][ny] = true;
			bfs(nx, ny, vis, data);
		}
	}
}

bool check(char data[][maxm]){
	bool vis[maxn][maxm];
	memset(vis, 0, sizeof(vis));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!vis[i][j] && data[i][j] <= '3' && data[i][j] >= '1')
				bfs(i, j, vis, data);
	bool ok = false;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(vis[i][j]){
				ok = true;
				data[i][j] = ' ';
			}
	return ok;
}

void make(char after[][maxm], char pre[][maxm], char c){
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			after[i][j] = pre[i][j];
	move(after, c);
	while(check(after))
		move(after, c);
	// while(move(after, c)){
	// 	check(after);
	// }
}

void make(char after[][maxm], vector<char> v){
	if(v.size() > 1){
		char now = v[v.size()-1];
		v.pop_back();
		char hold[maxn][maxm];
		make(hold, v);
		make(after, hold, now);
	}
	else
		make(after, ori, v[0]);
}

bool isOk(char data[][maxm]){
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(data[i][j] == '1' || data[i][j] == '2' || data[i][j] == '3')
				return false;
	return true;
}

bool isNotOk(char data[][maxm]){
	int num[5];
	memset(num, 0, sizeof(num));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(data[i][j] >= '1' && data[i][j] <= '3')
				num[data[i][j]-'0']++;
	for(int i=1;i<=3;i++)
		if(num[i] == 1)
			return true;
	return false;
}

void print(vector<char> v){
	for(int i=0;i<v.size();i++)
		printf("%c", v[i]);
	printf("\n");
}

bool solve(vector<char> v){
	if(v.size() > 18)
		return false;
	char after[maxn][maxm];
	//print(v);
	make(after, v);
	//print(after);
	if(isOk(after)){
		ans = v;
		return true;
	}
	if(isNotOk(after))
		return false;
	if(isExist(after))
		return false;
	char pre = v[v.size()-1];
	for(int i=0;i<4;i++)
		if(choice[i] != pre){
			v.push_back(choice[i]);
			// bool ok = solve(v);
			// if(ok)
			// 	return true;
			q.push(v);
			v.pop_back();
		}
	return false;
}

bool solve(){
	isExist(ori);
	vector<char> now;
	for(int i=0;i<4;i++){
		now.push_back(choice[i]);
		// bool ok = solve(now);
		// if(ok)
		// 	return true;
		q.push(now);
		now.clear();
	}
	while(!q.empty()){
		vector<char> v = q.front();
		q.pop();
		if(solve(v))
			return true;
	}
	return false;
}

int main()
{
	freopen("data.txt", "r", stdin);
	//freopen("dataout.txt", "w", stdout);
	char str[100000];
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++){
		while(!q.empty())
			q.pop();
		ans.clear();
		for(int i=0;i<mod;i++)
			hash[i].clear();
		scanf("%d%d%*c", &n, &m);
		//getchar();
		for(int i=0;i<n;i++)
			gets(ori[i]);
		//print(ori);
		gets(str);
		if(solve()){
			for(int i=0;i<ans.size();i++)
				printf("%c", ans[i]);
			printf("\n");
		}
		else
			printf("-1\n");
	}
	return 0;
}