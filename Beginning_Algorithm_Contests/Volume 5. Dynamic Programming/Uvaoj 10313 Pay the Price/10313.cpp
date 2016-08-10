// TLE

#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 310;

long long dp[maxn][maxn][maxn];

long long DP(int money, int coin, int m) {
	if(money == 0)
		return 1;
	if(coin == 0) 
		return 0;
	if(dp[money][coin][m] != -1)
		return dp[money][coin][m];
	dp[money][coin][m] = 0;
	// cout << m << endl;
	for(int i=1;i<=m && i<=money;i++)
		dp[money][coin][m] += DP(money-i, coin-1, i);
	return dp[money][coin][m];
}

int main()
{
	// freopen("data.txt", "r", stdin);
	string s;
	memset(dp, -1, sizeof(dp));
	while(getline(cin, s)) {
		stringstream ss(s);
		int a;
		vector<int> input;
		while(ss >> a)
			input.push_back(a);
		// for(int  i=0;i<input.size();i++)
		// 	cout << "input: "<< input[i] << endl;
		if(input.size() == 1)
			cout << DP(input[0], input[0], input[0]) << endl;
		else {
			if(input.size() == 2) {
				cout << DP(input[0], min(input[0], input[1]), input[0]) << endl;
			}
			else {
				if(input[2] == 0) {
					if(input[0] == 0)
						cout << 1 << endl;
					else
						cout << 0 << endl;
					continue;
				}
				if(input[1] == 0)
					input[1] = 1;
				if(input[1] > input[0]) {
					cout << 0 << endl;
					continue;
				}
				cout << DP(input[0], min(input[0], input[2]), input[0]) - DP(input[0], min(input[0], input[1]-1), input[0])<< endl;
			}
		}
	}
	return 0;
}




// AC

// #include <cstdio>
// #include <cstring>
// #include <vector>
// using namespace std;

// const int maxn = 310;

// long long dp[maxn][maxn];

// long long DP(int money, int coins) {
// 	if(money < 0)
// 		return 0;
// 	if(coins == 1)
// 		return 1;
// 	if(money == 0)
// 		return 1;
// 	if(coins == 0)
// 		return 0;
// 	if(dp[money][coins] != -1)
// 		return dp[money][coins];
// 	return dp[money][coins] = DP(money-coins, coins) + DP(money, coins-1);
// }

// int main()
// {
// 	// freopen("data.txt", "r", stdin);
// 	// ios_base::sync_with_stdio(false);
// 	char s[1000];
// 	int input[3];
// 	memset(dp, -1, sizeof(dp));
// 	while(gets(s)) {
// 		int size = sscanf(s, "%d%d%d", &input[0], &input[1], &input[2]);
// 		if(size == 1)
// 			printf("%lld\n", DP(input[0], input[0]));
// 		else {
// 			if(size == 2) {
// 				printf("%lld\n", DP(input[0], min(input[0], input[1])));
// 			}
// 			else {
// 				if(input[2] == 0) {
// 					if(input[0] == 0)
// 						printf("1\n");
// 					else
// 						printf("0\n");
// 					continue;
// 				}
// 				if(input[1] == 0)
// 					input[1] = 1;
// 				if(input[1] > input[0]) {
// 					printf("0\n");
// 					continue;
// 				}
// 				printf("%lld\n", DP(input[0], min(input[0], input[2])) - DP(input[0], min(input[0], input[1]-1)));
// 			}
// 		}
// 	}
// 	return 0;
// }