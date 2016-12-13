#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;


const int maxn = 64010;
const int replacement = 32005;
const int maxp = 110;
bool dp[maxp][maxn];
int arr[maxp];

bool is_in(int v) {
	return v >= -32000 && v <= 32000;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	cin >> T;
	for (int cc=0; cc<T; cc++) {
		int n;
		cin >> n;
		for (int i=0;i<n;i++) {
			cin >> arr[i];
		}
		int want;
		cin >> want;
		memset(dp, 0, sizeof(dp));
		dp[1][arr[0] + replacement] = 1;
		for (int i=1;i<n;i++) {
			for (int j=0;j<maxn;j++) {
				if (dp[i][j]) {
					int value = j - replacement;
					int next = arr[i];
					// cout << value << endl;
					// cout << next << endl;
					if (is_in(value + next))
						dp[i+1][value + next + replacement] = 1;
					if (is_in(value - next))
						dp[i+1][value - next + replacement] = 1;
					if (is_in(value * next))
						dp[i+1][value * next + replacement] = 1;
					if (next && value % next == 0 && is_in(value / next))
						dp[i+1][value / next + replacement] = 1;
				}
			}
		}
		if (dp[n][want + replacement]) {
			vector<char> vchar;
			int cur = want;
			for (int i = n-1;i >= 1;i--) {
				int v = arr[i];
				if (is_in(cur * v) && dp[i][v*cur+replacement]) {
					vchar.push_back('/');
					cur *= v;
					continue;
				}
				if (v && cur % v == 0 && is_in(cur / v) && dp[i][cur/v+replacement]) {
					vchar.push_back('*');
					cur /= v;
					continue;
				}
				if (is_in(cur + v) && dp[i][cur+v+replacement]) {
					vchar.push_back('-');
					cur += v;
					continue;
				}
				if (is_in(cur - v) && dp[i][cur-v+replacement]) {
					vchar.push_back('+');
					cur -= v;
					continue;
				}
			}
			reverse(vchar.begin(), vchar.end());
			for (int i=0;i<n-1;i++) {
				cout << arr[i];
				cout << vchar[i];
			}
			cout << arr[n-1] << "=" << want << endl;
		} else {
			cout << "NO EXPRESSION" << endl;
		}
	}
	return 0;
}