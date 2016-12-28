#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 6;

struct Tree {
	double L, R;
	Tree(double L, double R):L(L), R(R){}
	Tree(){}
};

vector<Tree> v[(1<<maxn)+5];
int w[maxn+5];
int sum[(1<<maxn)+5];
double width;
double ans;
int s;
bool vis[1<<maxn];

void solve(int node) {
	if (vis[node])
		return;
	vis[node] = true;
	bool have_child = false;
	// enumerate subset!
	for (int left = node & (node-1); left > 0; left = (left-1) & node) {
		have_child = true;
		int right = left ^ node;
		solve(left);
		solve(right);
		double L = (double)sum[right] / sum[node];
		double R = (double)sum[left] / sum[node];
		for (int i = 0; i < v[left].size(); ++i) {
			for (int j = 0; j < v[right].size(); ++j) {
				// Have to consider two cases! Since we have (< width) constraint!
				// We are not finding the largest width.
				double curL = max(v[left][i].L + L, v[right][j].L - R);
				double curR = max(v[right][j].R + R, v[left][i].R - L);
				double L = curL + curR;
				// subtree width still needs to be (< width)!
				if (L < width) {
					if (node != (1<<s)-1)
						v[node].push_back(Tree(curL, curR));
					else
						ans = max(ans, curR + curL);
				}
			}
		}
	}
	if (!have_child)
		v[node].push_back(Tree(0, 0));
}

int main()
{
	// freopen("data.txt", "r", stdin);
	// freopen("output_my.txt", "w", stdout);
	int T;
	cin >> T;
	for (int cc = 0; cc < T; ++cc) {
		ans = -1;
		cin >> width;
		cin >> s;
		for (int i = 0; i < (1<<maxn)+5; ++i)
			v[i].clear();
		memset(sum, 0, sizeof(sum));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < s; ++i) {
			cin >> w[i];
		}
		for (int i = 0; i < 1<<s; ++i) {
			for (int j = 0; j < s; ++j) {
				if (1<<j & i)
					sum[i] += w[j];
			}
		}
		solve((1<<s)-1);
		if (s == 1)
			ans = 0.0;
		printf("%.10lf\n", ans);
	}
	return 0;
}