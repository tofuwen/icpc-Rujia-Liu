#include <cstdio>
using namespace std;

const int maxn = 13;

int n;

struct view
{		
	char c[maxn][maxn];
};

view v[10];
char cube[maxn][maxn][maxn];

void process(int indexV){
	switch(indexV){
		case 0:{
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(v[indexV].c[i][j] == '.')
						for(int k=0;k<n;k++)
							cube[k][j][n-i-1] = '.';
			break;
		}
		case 1:{
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(v[indexV].c[i][j] == '.')
						for(int k=0;k<n;k++)
							cube[j][k][n-i-1] = '.';
			break;
		}
		case 2:{
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(v[indexV].c[i][j] == '.')
						for(int k=0;k<n;k++)
							cube[k][n-j-1][n-i-1] = '.';
			break;
		}
		case 3:{
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(v[indexV].c[i][j] == '.')
						for(int k=0;k<n;k++)
							cube[n-j-1][k][n-i-1] = '.';
			break;
		}
		case 4:{
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(v[indexV].c[i][j] == '.')
						for(int k=0;k<n;k++)
							cube[i][j][k] = '.';
			break;
		}
		default:{
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(v[indexV].c[i][j] == '.')
						for(int k=0;k<n;k++)
							cube[n-i-1][j][k] = '.';
			break;
		}
	}
}

bool dye(int indexV){
	int k;
	switch(indexV){
		case 0:{
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(v[indexV].c[i][j] != '.'){
						for(k=n-1;k>=0;k--)
							if(cube[k][j][n-i-1] != '.')
								break;
						char &h = cube[k][j][n-i-1];
						if(h == v[indexV].c[i][j])
							continue;
						if(h == ' ')
							h = v[indexV].c[i][j];
						else{
							h = '.';
							return false;
						}
					}
			break;
		}
		case 1:{
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(v[indexV].c[i][j] != '.'){
						for(k=0;k<n;k++)
							if(cube[j][k][n-i-1] != '.')
								break;
						char &h = cube[j][k][n-i-1];
						if(h == v[indexV].c[i][j])
							continue;
						if(h == ' ')
							h = v[indexV].c[i][j];
						else{
							h = '.';
							return false;
						}
					}
			break;
		}
		case 2:{
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(v[indexV].c[i][j] != '.'){
						for(k=0;k<n;k++)
							if(cube[k][n-j-1][n-i-1] != '.')
								break;
						char &h = cube[k][n-j-1][n-i-1];
						if(h == v[indexV].c[i][j])
							continue;
						if(h == ' ')
							h = v[indexV].c[i][j];
						else{
							h = '.';
							return false;
						}
					}
			break;
		}
		case 3:{
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(v[indexV].c[i][j] != '.'){
						for(k=n-1;k>=0;k--)
							if(cube[n-j-1][k][n-i-1] != '.')
								break;
						char &h = cube[n-j-1][k][n-i-1];
						if(h == v[indexV].c[i][j])
							continue;
						if(h == ' ')
							h = v[indexV].c[i][j];
						else{
							h = '.';
							return false;
						}
					}
			break;
		}
		case 4:{
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(v[indexV].c[i][j] != '.'){
						for(k=n-1;k>=0;k--)
							if(cube[i][j][k] != '.')
								break;
						char &h = cube[i][j][k];
						if(h == v[indexV].c[i][j])
							continue;
						if(h == ' ')
							h = v[indexV].c[i][j];
						else{
							h = '.';
							return false;
						}
					}
			break;
		}
		default:{
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(v[indexV].c[i][j] != '.'){
						for(k=0;k<n;k++)
							if(cube[n-i-1][j][k] != '.')
								break;
						char &h = cube[n-i-1][j][k];
						if(h == v[indexV].c[i][j])
							continue;
						if(h == ' ')
							h = v[indexV].c[i][j];
						else{
							h = '.';
							return false;
						}
					}
			break;
		}
	}
	return true;
}

bool solve(){
	for(int indexV=0;indexV<6;indexV++){
		bool ok = dye(indexV);
		if(!ok)
			return true;
	}
	return false;
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d",&n) && n){
		for(int i=0;i<n;i++)
			for(int j=0;j<6;j++)
				scanf("%s", v[j].c[i]);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
					cube[i][j][k] = ' ';
		for(int i=0;i<6;i++)
			process(i);
		int num = 0;
		while(solve());
		// while(solve()){
		// 	if(num > n*n*n){
		// 		printf("wanle\n");
		// 		break;
		// 	}
		// 	num++;
		// }
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<n;j++){
		// 		for(int k=0;k<n;k++)
		// 			printf("%c",cube[i][j][k]);
		// 		printf("\n");
		// 	}
		// 	printf("\n");
		// }
		int ans = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
					if(cube[i][j][k] == '.')
						ans++;
		printf("Maximum weight: %d gram(s)\n", n*n*n-ans);
	}
	return 0;
}