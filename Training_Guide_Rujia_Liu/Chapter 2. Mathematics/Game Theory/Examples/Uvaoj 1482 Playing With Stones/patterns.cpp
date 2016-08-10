#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 110;

int main()
{
	bool vis[maxn];
	int sg[maxn];
	sg[1] = 0;
	for(int i=2;i<30;i++) {
		int m = i/2;
		memset(vis, 0, sizeof(vis));
		for(int j=i-m;j<i;j++)
			vis[sg[j]] = true;
		int cur = 0;
		while(vis[cur]) { 
			cur++;
		}
		sg[i] = cur;
	}
	for(int i=1;i<30;i++)
		cout << sg[i] << " ";
	cout << endl;
	return 0;
}