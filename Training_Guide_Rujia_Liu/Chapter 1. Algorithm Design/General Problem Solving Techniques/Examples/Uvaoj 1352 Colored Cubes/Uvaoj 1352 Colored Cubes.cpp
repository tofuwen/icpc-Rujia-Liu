/*
//TLE!

#include <cstdio>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 8;
const int INF = 1<<30;

int n;
int cube[maxn][10];
int ans;

int choice[10][10] = {{1,2,3,5,4,6},{6,3,2,4,5,1},{2,3,1,4,6,5},{5,3,6,4,1,2},{3,2,6,5,1,4},{4,2,1,5,6,3}};

map<string, int> m;

int solveNum(int* final, int* t){
	int aans = 0;
	for(int i=0;i<6;i++)
		if(final[i] != t[i])
			aans++;
	return aans;
}

int solve(int* final, int* now){
	int hold[10];
	int t[10];
	int aans = 100;
	for(int i=0;i<6;i++){
		hold[0] = choice[i][0];
		hold[5] = choice[i][5];
		for(int j=0;j<4;j++){
			for(int k=1;k<=4;k++)
				hold[k] = choice[i][(j+k)>4?j+k-4:j+k];
			for(int k=0;k<6;k++)
				t[k] = now[hold[k]-1];
			aans = min(aans, solveNum(final, t));
		}
	}
	return aans;
}

void solve(int* final){
	int now = 0;
	for(int i=0;i<n;i++)
		now += solve(final, cube[i]);
	ans = min(ans, now);
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d", &n) && n){
		m.clear();
		int num = 0;
		ans = INF;
		for(int i=0;i<n;i++){
			string s;
			for(int j=0;j<6;j++){
				cin>>s;
				map<string, int>::iterator iter = m.find(s);
				if(iter == m.end()){
					m[s] = num;
					cube[i][j] = num;
					num++;
				}
				else
					cube[i][j] = iter->second;
			}
		}
		int final[10];
		//printf("%d\n", num);
		for(final[0]=0;final[0]<num;final[0]++)
			for(final[1]=0;final[1]<num;final[1]++)
				for(final[2]=0;final[2]<num;final[2]++)
					for(final[3]=0;final[3]<num;final[3]++)
						for(final[4]=0;final[4]<num;final[4]++)
							for(final[5]=0;final[5]<num;final[5]++)
								solve(final);
		printf("%d\n",ans);
	}
	return 0;
}
*/

#include <cstdio>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 8;
const int INF = 1<<30;

int n;
int cube[maxn][10];

int choice[10][10] = {{1,2,3,5,4,6},{6,3,2,4,5,1},{2,3,1,4,6,5},{5,3,6,4,1,2},{3,2,6,5,1,4},{4,2,1,5,6,3}};

map<string, int> m;

void pose(int* final, int choose){
	int nChoice = choose / 4;
	int nn = choose % 4 ;
	final[0] = choice[nChoice][0] -1;
	final[5] = choice[nChoice][5] -1;
	for(int k=1;k<=4;k++)
		final[k] = choice[nChoice][(nn+k)>4?nn+k-4:nn+k] -1;
}

void finalColor(int* finalColor, int* originalColor, int choose){
	int final[10];
	pose(final, choose);
	for(int i=0;i<6;i++)
		finalColor[i] = originalColor[final[i]];
}

int solve(int* array){
	int num[30];
	memset(num, 0, sizeof(num));
	for(int i=0;i<n;i++)
		num[array[i]]++;
	int ans = 0;
	for(int i=0;i<30;i++)
		ans = max(ans, num[i]);
	//printf("%d\n",ans);
	return n-ans;
}

int solve(int final[][10]){
	int hold[10];
	int ans = 0;
	for(int i=0;i<6;i++){
		for(int j=0;j<n;j++)
			hold[j] = final[j][i];
		ans += solve(hold);
	}
	//printf("%d\n", ans);
	return ans;
}

int solve(){
	if(n == 1)
		return 0;
	int ans = INF;
	int final[maxn][10];
	for(int i=0;i<(int)(pow(24, n-1)+0.5);i++){
		int choose[10];
		choose[1] = i % 24;
		choose[2] = (i / 24) %24;
		choose[3] = (i / 24 / 24) % 24;
		finalColor(final[0], cube[0], 0);
		for(int j=1;j<n;j++)
			finalColor(final[j], cube[j], choose[j]);
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<6;j++)
		// 		printf("%d ", final[i][j]);
		// 	printf("\n");
		// }
		ans = min(ans, solve(final));
	}
	return ans;
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d", &n) && n){
		m.clear();
		int num = 0;
		for(int i=0;i<n;i++){
			string s;
			for(int j=0;j<6;j++){
				cin>>s;
				map<string, int>::iterator iter = m.find(s);
				if(iter == m.end()){
					m[s] = num;
					cube[i][j] = num;
					num++;
				}
				else
					cube[i][j] = iter->second;
			}
		}
		int ans = solve();
		printf("%d\n",ans);
	}
	return 0;
}