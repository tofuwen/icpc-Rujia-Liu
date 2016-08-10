#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 210;

int n;

char data[maxn][maxn];

bool isChar(char c){
	if(c != ' ' && c != '|' && c != '#' && c != '-')
		return true;
	return false;
}

bool isRoot(int line, int col){
	if(line >= n-1)
		return false;
	if(data[line+1][col] == '|'){
		//printf("kao\n");
		return true;
	}
	return false;
}

void solve(int line, int from, int to){
	//printf("\n from: %d to: %d\n",from, to);
	//printf("\n");
	//puts(data[line]);
	for(int i=from;i<min(to, (int)strlen(data[line]));i++){
		if(isChar(data[line][i])){
			printf("%c(", data[line][i]);
			if(isRoot(line, i)){
				int nextLine = line+2;
				//puts(data[nextLine]);
				int f=i, t=i;
				for(t=i;t<strlen(data[nextLine]);t++)
					if(data[nextLine][t] != '-')
						break;
				for(f=i;f>=0;f--)
					if(data[nextLine][f] != '-')
						break;
				solve(line+3, f+1, t);
			}
			printf(")");
		}
	}
}

void solve(){
	solve(0,0,strlen(data[0]));
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d", &T);
	getchar();
	for(int cc=0;cc<T;cc++){
		n = 0;
		while(1){
			gets(data[n]);
		//	puts(data[n]);
			if(data[n][0] == '#')
				break;
			n++;
		}
		printf("(");
		solve();
		printf(")\n");
	}
	return 0;
}