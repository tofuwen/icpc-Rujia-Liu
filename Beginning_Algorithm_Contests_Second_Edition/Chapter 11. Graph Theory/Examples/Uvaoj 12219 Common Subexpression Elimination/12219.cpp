#include <cstdio>
#include <map>
#include <iostream>
#include <cstring>
#include <tuple>
#include <string>
using namespace std;

map<tuple<string, int, int>, int> mapping;
bool ids[60000];

struct node {
	int id = 100;
	char name[6];
	node * left;
	node * right;
	int length;
	node(int id, char * s, node * left, node * right, int length):id(id), left(left), right(right), length(length) {
		strcpy(name, s);
	}
};

node * build_tree(char * s) {
	char name[6];
	int index = 0;
	while(islower(s[index])) {
		name[index] = s[index];
		index++;
	}
	name[index] = 0;
	if (s[index] == 0) {
		return new node(0, name, NULL, NULL, index);
	}
	if (s[index] == '(') {
		node * left = build_tree(s + index + 1);
		node * right = build_tree(s + index + 1 + left->length + 1);
		return new node(0, name, left, right, left->length + right->length + index + 3);
	} else {
		return new node(0, name, NULL, NULL, index);
	}
}

void traverse(node * cur) {
	if (cur) {
		cout << cur->id << endl;
		traverse(cur->left);
		traverse(cur->right);
	}
}

int cur_id = 1;

int assign_id(node * cur) {
	if (!cur)
		return 0;
	cur->id = cur_id++;
	int lid = assign_id(cur->left);
	int rid = assign_id(cur->right);
	auto cur_tuple = make_tuple(string(cur->name), lid, rid);
	if (mapping.find(cur_tuple) != mapping.end()) {
		cur_id--;
		cur->id = mapping[cur_tuple];
		return cur->id;
	}
	mapping[cur_tuple] = cur->id;
	return cur->id;
}

void print(node * cur) {
	if (ids[cur->id]) {
		cout << cur -> id;
		return;
	}
	ids[cur->id] = true;
	cout << cur -> name;
	if (cur -> left) {
		cout << "(";
		print(cur->left);
		cout << ",";
		print(cur->right);
		cout << ")";
	}
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	cin >> T;
	for (int cc = 0; cc < T; ++cc) {
		cur_id = 1;
		mapping.clear();
		memset(ids, 0, sizeof(ids));
		char s[300000];
		cin >> s;
		node * root = build_tree(s);
		assign_id(root);
		print(root);
		cout << endl;
	}
	return 0;
}