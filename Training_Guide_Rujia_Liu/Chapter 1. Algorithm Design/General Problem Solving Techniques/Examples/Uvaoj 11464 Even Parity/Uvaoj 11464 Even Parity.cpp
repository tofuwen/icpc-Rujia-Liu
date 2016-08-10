#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 20;

int n;

int data[maxn][maxn];
int myData[maxn][maxn];

int minTran;

void makeList(int* a, int num){
	for(int i=n;i>=1;i--){
		//printf("num %d\n", num);
		a[i] = num % 2;
		num /= 2;
	}
}

int make(int i, int j){
	int want = (myData[i-1][j-1] + myData[i-1][j+1] + myData[i-2][j]) % 2;
	return want;
}

void make(){
	for(int i=2;i<=n;i++)
		for(int j=1;j<=n;j++)
			myData[i][j] = make(i,j);
}

bool check(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(data[i][j] && !myData[i][j])
				return false;
	int i = n;
	for(int j=1;j<=n;j++){
		int want = myData[i-1][j] + myData[i+1][j] + myData[i][j-1] + myData[i][j+1];
		if(want % 2)
			return false;
	}
	return true;
}

int d(){
	int ans = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(data[i][j]+myData[i][j] == 1)
				ans++;
	return ans;
}

void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ", myData[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d", &T);
	for(int cc=1;cc<=T;cc++){
		scanf("%d", &n);
		minTran = 500;
		memset(data, 0, sizeof(data));
		memset(myData, 0, sizeof(myData));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d", &data[i][j]);
		int maxV = (1<<n)-1;
		for(int i=0;i<=maxV;i++){
			makeList(myData[1], i);
			make();
		//	print();
			if(check())
				minTran = min(minTran, d());
		}
		printf("Case %d: %d\n", cc, minTran==500?-1:minTran);
	}
	
	return 0;
}