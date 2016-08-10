#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

const int kase = 20;
const int maxn = 8;
const int maxm = 12;

char data[maxn][maxm];

int main()
{
	freopen("gData.txt", "w", stdout);
	srand(time(NULL));
	printf("%d\n", kase);
	for(int cc=0;cc<kase;cc++){
		int n = (rand() % maxn + maxn) % maxn;
		int m = (rand() % maxm + maxm) % maxm;
		if(n <= 2)
			n = maxn - n -1;
		if(m <= 2)
			m = maxm - m - 1;
		printf("%d %d\n", n, m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				int r = rand();
				if(r % 2 == 1)
					data[i][j] = ' ';
				else{
					if(r % 13 == 1)
						data[i][j] = '1';
					if(r % 13 == 3)
						data[i][j] = '2';
					if(r % 13 == 5)
						data[i][j] = '3';
					if(r % 13 == 7)
						data[i][j] = '@';
					if(r % 11 == 1)
						data[i][j] = '#';
				}

			}
		for(int i=0;i<n;i++)
			data[i][0] = data[i][m-1] = '#';
		for(int i=0;i<m;i++)
			data[0][i] = data[n-1][i] = '#';
		data[1][1] = '1';
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				printf("%c", data[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}