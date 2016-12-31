#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int maxw = 16 + 4;
const int maxn = 3 + 2;
char room[maxw][maxw];

int w, h, n;
int position[2][maxn];

int encode(int * p) {
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans *= (w * h);
		ans += p[i];
	}
	return ans;
	// return (p[0] & 0xff) << 16 | (p[1] & 0xff) << 8 | (p[2] & 0xff);
}

void decode(int * p, int cur_p) {
	for (int i = n-1; i >= 0; --i) {
		p[i] = cur_p % (w*h);
		cur_p /= (w*h);
	}
	// p[0] = (cur_p >> 16) & 0xff;
	// p[1] = (cur_p >> 8) & 0xff;
	// p[2] = cur_p & 0xff;
}

bool is_valid(int po) {
	int cur_h = po / w;
	int cur_w = po - cur_h * w;
	return room[cur_h][cur_w] != '#';
}

bool is_valid(int * cur_p, int * next_p) {
	for (int i = 0; i < n; ++i) {
		if (!is_valid(next_p[i]))
			return false;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if (next_p[i] == next_p[j])
				return false;
			if (next_p[i] == cur_p[j] && next_p[j] == cur_p[i])
				return false;
		}
	}
	return true;
}

vector<int> all_possible_next_state(int state) {
	vector<int> ans;
	int cur_p[maxn];
	decode(cur_p, state);
	// for (int i = 0; i < n; ++i)
	// 	cout << cur_p[i] << " ";
	// cout << endl;
	int possible[5];
	possible[0] = 0;
	possible[1] = 1;
	possible[2] = -1;
	possible[3] = w;
	possible[4] = -w;
	int next_p[maxn];
	switch (n) {
		case 1: {
			for (int i = 0; i < 5; ++i) {
				next_p[0] = cur_p[0] + possible[i];
				if (is_valid(cur_p, next_p))
					ans.push_back(encode(next_p));
			}
			break;
		}
		case 2: {
			for (int i = 0; i < 5; ++i) {
				for (int j = 0; j < 5; ++j) {
					next_p[0] = cur_p[0] + possible[i];
					next_p[1] = cur_p[1] + possible[j];
					if (is_valid(cur_p, next_p))
						ans.push_back(encode(next_p));
				}
			}
			break;
		}
		default: { // n == 3
			for (int i = 0; i < 5; ++i) {
				for (int j = 0; j < 5; ++j) {
					for (int k = 0; k < 5; ++k) {
						next_p[0] = cur_p[0] + possible[i];
						next_p[1] = cur_p[1] + possible[j];
						next_p[2] = cur_p[2] + possible[k];
						if (is_valid(cur_p, next_p))
							ans.push_back(encode(next_p));
					}
				}
			}
			break;
		}
	}
	return ans;
}

int solve() {
	unordered_map<int, int> um1;
	unordered_map<int, int> um2;
	queue<int> q1;
	queue<int> q2;
	int state1 = encode(position[0]);
	int state2 = encode(position[1]);
	um1[state1] = 0;
	um2[state2] = 0;
	q1.push(state1);
	q2.push(state2);
	int q1_level = 0, q2_level = 0;
	bool is_q1 = true;
	while (1) {
		if (is_q1) {
			while (!q1.empty()) {
				int cur_state = q1.front();
				int cur_state_step = um1[cur_state];
				if (cur_state_step > q1_level) {
					q1_level++;
					break;
				}
				q1.pop();
				// cout << "q1" << endl;
				vector<int> v = all_possible_next_state(cur_state);
				for (int i = 0; i < v.size(); ++i) {
					if (um1.find(v[i]) != um1.end())
						continue;
					if (um2.find(v[i]) != um2.end()) {
						// cout << cur_state_step << endl;
						// cout << um2[v[i]] << endl;
						return cur_state_step + 1 + um2[v[i]];
					} else {
						q1.push(v[i]);
						um1[v[i]] = cur_state_step + 1;
					}
				}
			}
		} else {
			while (!q2.empty()) {
				int cur_state = q2.front();
				int cur_state_step = um2[cur_state];
				if (cur_state_step > q2_level) {
					q2_level++;
					break;
				}
				q2.pop();
				// cout << "q2" << endl;
				vector<int> v = all_possible_next_state(cur_state);
				for (int i = 0; i < v.size(); ++i) {
					if (um2.find(v[i]) != um2.end())
						continue;
					if (um1.find(v[i]) != um1.end()) {
						return cur_state_step + 1 + um1[v[i]];
					} else {
						q2.push(v[i]);
						um2[v[i]] = cur_state_step + 1;
					}
				}
			}
		}
		is_q1 = !is_q1;
	}
}

int main()
{
	// freopen("data.txt", "r", stdin);
	while(scanf("%d %d %d\n", &w, &h, &n) && w) {
		for (int i = 0; i < h; ++i) {
			fgets(room[i], 20, stdin);
			for (int j = 0; j < w; ++j) {
				if (room[i][j] >= 'a' && room[i][j] < 'a' + n)
					position[0][room[i][j] - 'a'] = i * w + j;
				if (room[i][j] >= 'A' && room[i][j] < 'A' + n)
					position[1][room[i][j] - 'A'] = i * w + j;
			}
		}
		int ans = solve();
		printf("%d\n", ans);
	}
}