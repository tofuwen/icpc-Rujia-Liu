#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

const int maxn = 100 + 10;
const int deck = 60;

int shuffle_array[maxn][deck];

void make(int * pre, int * next, int choose) {
	for (int j = 1; j <= 52; ++j) {
		int i = shuffle_array[choose][j];
		next[j] = pre[i];
	}
}

string num(int id) {
	--id;
	id %= 13;
	if (id == 12)
		return "Ace";
	if (id == 11)
		return "King";
	if (id == 10)
		return "Queen";
	if (id == 9)
		return "Jack";
	return to_string(id+2);
}

string suit(int id) {
	int s = (id-1) / 13;
	if (s == 0)
		return "Clubs";
	if (s == 1)
		return "Diamonds";
	if (s == 2)
		return "Hearts";
	return "Spades";
}

void name(int id) {
	cout << num(id) << " of " << suit(id) << endl;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	cin >> T;
	bool is_first = true;
	while (T--) {
		if (!is_first)
			cout << endl;
		is_first = false;
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 52; ++j) {
				cin >> shuffle_array[i][j];
			}
		}
		vector<int> v;
		string s;
		getline(cin, s);
		while(getline(cin, s)) {
			if (s == "")
				break;
			stringstream ss(s);
			int cur;
			ss >> cur;
			v.push_back(cur);
		}
		int init[maxn];
		int next[maxn];
		for (int i = 1; i <= 52; ++i)
			init[i] = i;
		for (int i = 0; i < v.size(); ++i) {
			if (i % 2 == 0)
				make(init, next, v[i]);
			else
				make(next, init, v[i]);
		}
		int * ans;
		if (v.size() % 2 == 0)
			ans = init;
		else
			ans = next;
		for (int i = 1; i <=52; ++i)
			name(ans[i]);
	}
	return 0;
}