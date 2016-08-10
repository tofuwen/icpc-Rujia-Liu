#include <cstdio>
#include <iostream>
#include <sstream> 
#include <string>
using namespace std;

const int maxn = 10010;

int k;
int data[maxn];
int n;

int solve(int* data, int* ans, int degree)
{
	if(degree == n-1)
		return data[degree];
	ans[degree] = data[degree];
	data[degree+1] += k*ans[degree];
	return solve(data,ans,degree+1);
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d",&k)!=EOF)
	{
		getchar();
		string line;
		getline(cin,line);
		n = 0;
		stringstream ss(line);
		while(ss>>data[n]){
			n++;
		}
		int ans[maxn];
		int Ans = solve(data,ans,0);
		printf("q(x):");
		for(int i=0;i<n-1;i++)
			printf(" %d",ans[i]);
		printf("\n");
		printf("r = %d\n\n",Ans);
	}
}