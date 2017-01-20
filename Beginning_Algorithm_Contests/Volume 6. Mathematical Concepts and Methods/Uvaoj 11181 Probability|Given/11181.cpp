#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1000;

int com[maxn];

bool next_Com(int num, int k){ //0,1...num-1 choose k
	if(k == 0)
		return false;
	if(com[k-1]!=num-1){
		com[k-1]++;
		return true;
	}
	int i;
	for(i=k-1;i>=0;i--)
		if(com[i]!=num-k+i)
			break;
	if(i==-1)
		return false;
	com[i]++;
	for(int j=i+1;j<k;j++)
		com[j] = com[i]+(j-i);
	return true;
}

void makeFirstCom(int k){
	for(int i=0;i<k;i++)
		com[i] = i;
}

int n, r;

double p[maxn];

int main()
{
	// freopen("data.txt", "r", stdin);
	int kase = 0;
	while (cin >> n >> r && n) {
		for (int i = 0; i < n; ++i)
			cin >> p[i];
		cout << "Case " << ++kase << ":" << endl;
		if (r == 0) {
			for (int i = 0; i < n; ++i)
				printf("%.6f\n", 0.0);
		} else {
			double total = 0.0;
			double ans[maxn];
			for (int i = 0; i < n; ++i)
				ans[i] = 0.0;
			makeFirstCom(r);
			do {
				double cur = 1.0;
				bool vis[maxn];
				memset(vis, 0, sizeof(vis));
				for (int i = 0; i < r; ++i) {
					cur *= p[com[i]];
					vis[com[i]] = true;
				}
				for (int i = 0; i < n; ++i) {
					if (!vis[i])
						cur *= (1 - p[i]);
				}
				total += cur;
				for (int i = 0; i < r; ++i)
					ans[com[i]] += cur;
			} while(next_Com(n, r));
			for (int i = 0; i < n; ++i)
				printf("%.6f\n", ans[i] / total);
		}
	}
	return 0;
}



