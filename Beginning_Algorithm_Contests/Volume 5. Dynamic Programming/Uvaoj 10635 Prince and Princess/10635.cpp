#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 255;
int n, p, q;

int occupied[maxn * maxn];

int LIS(const vector<int> & v) {
	vector<int> ans;
	int size = v.size();
	/// for(int i=0;i<size;i++)
		// printf("%d ", v[i]);
	for(int i=0;i<size;i++) {
		auto iter = lower_bound(ans.begin(), ans.end(), v[i]);
		if(iter == ans.end())
			ans.push_back(v[i]);
		else
			*iter = v[i];
	}
	return ans.size();
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=1;cc<=T;cc++) {
		scanf("%d%d%d", &n, &p, &q);
		memset(occupied, -1, sizeof(occupied));
		for(int i=0;i<p+1;i++) {
			int temp;
			scanf("%d", &temp);
			// printf("temp: %d\n", temp);
			occupied[temp] = i;
		}
		vector<int> v;
		for(int i=0;i<q+1;i++) {
			int temp;
			scanf("%d", &temp);
			if(occupied[temp] != -1)
				v.push_back(occupied[temp]);
		}
		printf("Case %d: %d\n",cc, LIS(v));
	}
	return 0;
}