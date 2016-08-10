#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int mod = 9789;

vector<long long> v[mod];
char s[10][10];
long long want;
int a[8] = {2,2,-2,-2,1,1,-1,-1};
int b[8] = {1,-1,1,-1,2,-2,2,-2};

struct chessboard
{
	long long v;
	int c[7][7];
	int spaceRow;
	int spaceCol;
	int degree;
};

queue<chessboard> q;

chessboard makeChess(int d)
{
	chessboard h;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			if(s[i][j]==' ')
			{
				h.c[i][j] = 2;
				h.spaceRow = i;
				h.spaceCol = j;
			}
			else
				h.c[i][j] = s[i][j]-'0';
	long long hold = 0;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
		{
			hold *= 3;
			hold += h.c[i][j];
		//	printf("v:%lld\n",hold);
		}
	h.v = hold;
	h.degree = d;
	//printf("value: %lld\n",h.v);
	return h;
}

bool outOfRange(int row, int col)
{
	if(row<0||row>4||col<0||col>4)
		return true;
	return false;
}

void pre()
{
	for(int i=0;i<mod;i++)
		v[i].clear();
	while(!q.empty())
		q.pop();
	char hold[100] = "1111101111002110000100000";
	want = 0;
	for(int i=0;i<25;i++)
	{
		want *= 3;
		want += hold[i]-'0';
	}
}

void insertHash(chessboard h)
{
	long long va = h.v;
//	printf("VaMod%d\n",va%mod);
	v[va%mod].push_back(va);
}

bool isExist(chessboard h)
{
	long long va = h.v;
	int w = va%mod;
	for(int i=0;i<v[w].size();i++)
		if(v[w][i]==va)
			return true;
	return false;
}

void nextStep(chessboard h)
{
	int newRow, newCol;
	for(int i=0;i<8;i++)
	{
		newRow = h.spaceRow + a[i];
		newCol = h.spaceCol + b[i];
		if(outOfRange(newRow,newCol))
			continue;
		for(int j=0;j<5;j++)
			for(int k=0;k<5;k++)
				s[j][k] = h.c[j][k]+'0';
		s[h.spaceRow][h.spaceCol] = s[newRow][newCol];
		s[newRow][newCol] = ' ';
		chessboard hold = makeChess(h.degree+1);
		if(!isExist(hold))
		{
			q.push(hold);
			insertHash(hold);
		}
	}
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d\n",&T);
	for(int cc=0;cc<T;cc++)
	{
		pre();
		for(int i=0;i<5;i++)
			gets(s[i]);
       // for(int i=0;i<5;i++)
         //   printf("%s\n",s[i]);
		chessboard hold = makeChess(0);
		q.push(hold);
		insertHash(hold);
		while(!q.empty())
		{
			chessboard h = q.front();
			q.pop();
			if(h.v==want)
			{
				printf("Solvable in %d move(s).\n",h.degree);
				break;
			}
			if(h.degree>=11)
			{
				printf("Unsolvable in less than 11 move(s).\n");
				break;
			}
			nextStep(h);
		}
	}
	return 0;
}
