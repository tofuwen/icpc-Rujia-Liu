#include <cstdio>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

const int mod = 9897;

int h[5][5];
vector<int> v[mod];

struct puzzle
{
	int p[5][5];
	int v;
	int spaceRow;
	int spaceCol;
	string s;
};

puzzle makePuzzle(string s)
{
	int v = 0;
	puzzle hold;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			v *= 9;
			v += h[i][j];
			hold.p[i][j] = h[i][j];
			if(h[i][j]==0)
			{
				hold.spaceRow = i;
				hold.spaceCol = j;
			}
		}
	hold.v = v;
	hold.s = s;
	return hold;
}

queue<puzzle> q;
puzzle previous;

void pre()
{
	while(!q.empty())
		q.pop();
	for(int i=0;i<mod;i++)
		v[i].clear();
}

void insertHash(puzzle p)
{
	int va = p.v%mod;
	v[va].push_back(p.v);
}

bool isExist(puzzle p)
{
	int va = p.v%mod;
	for(int i=0;i<v[va].size();i++)
		if(v[va][i]==p.v)
			return true;
	return false;
}

bool outOfRange(int row, int col)
{
	if(row<0||row>2||col<0||col>2)
		return true;
	return false;
}

void next_step(puzzle p)
{
	int a[4] = {0,0,1,-1};
	int b[4] = {1,-1,0,0};
	char c[4] = {'R','L','D','U'};
	for(int i=0;i<4;i++)
	{
		int newRow = p.spaceRow + a[i];
		int newCol = p.spaceCol + b[i];
		if(!outOfRange(newRow, newCol))
		{
			for(int j=0;j<3;j++)
				for(int k=0;k<3;k++)
					h[j][k] = p.p[j][k];
			h[p.spaceRow][p.spaceCol] = p.p[newRow][newCol];
			h[newRow][newCol] = 0;
			puzzle now = makePuzzle(p.s+c[i]);
			if(!isExist(now))
			{
				insertHash(now);
				q.push(now);
			}
		}
	}
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=1;cc<=T;cc++)
	{
		pre();
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				scanf("%d",&h[i][j]);
		puzzle f = makePuzzle("");
		insertHash(f);
		q.push(f);
		while(!q.empty())
		{
			puzzle now = q.front();
			previous = now;
			q.pop();
			next_step(now);
		}
		printf("Puzzle #%d\n",cc);
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(j)
					printf(" ");
				printf("%d",previous.p[i][j]);
			}
			printf("\n");
		}
		cout<<previous.s<<endl<<endl;
	}
	return 0;
}