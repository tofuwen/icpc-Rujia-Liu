#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int dp[maxn][maxn];
string s;

int DP(int i, int j) {
	if(dp[i][j] != -1)
		return dp[i][j];
	if(j <= i)
		return dp[i][j] = 0;
	if(s[i] == s[j])
		return dp[i][j] = DP(i+1, j-1);
	return dp[i][j] = min(1+DP(i+1, j), 1+DP(i, j-1));
}

string make_string() {
	string s1 = "", s2 = "";
	int i = 0, j = s.length()-1;
	while(1) {
		if(j == i) {
			s1.append(1, s[i]);
			break;
		}
		if(j < i)
			break;
		if(s[i] == s[j]) {
			s1.append(1, s[i]);
			s2.append(1, s[i]);
			++i;
			--j;
			continue;
		}
		if(DP(i, j) == 1+DP(i+1, j)) {
			s1.append(1, s[i]);
			s2.append(1, s[i]);
			++i;
		}
		else {
			s1.append(1, s[j]);
			s2.append(1, s[j]);
			--j;
		}
	}
	reverse(s2.begin(), s2.end());
	s1.append(s2);
	return s1;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	while(cin >> s) {
		memset(dp, -1, sizeof(dp));
		cout << DP(0, s.length()-1) << " " << make_string() << endl;
	}
	return 0;
}