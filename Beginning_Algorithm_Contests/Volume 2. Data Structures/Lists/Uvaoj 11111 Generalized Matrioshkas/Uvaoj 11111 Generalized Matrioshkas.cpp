#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

struct doll
{
	int cap;
	int remain;
	doll(int cap, int remain):cap(cap),remain(remain){}
};

vector<int> data;

bool solve(){
	stack<doll> s;
	bool ok = true;
	for(int i=0;i<data.size();i++){
		if(data[i] < 0){
			if(s.empty())
				if(ok){
					s.push(doll(-data[i], -data[i]));
					ok = false;
				}
				else
					return false;
			else{
				doll pre = s.top();
				s.pop();
				pre.remain += data[i];
				if(pre.remain <= 0)
					return false;
				s.push(pre);
				s.push(doll(-data[i], -data[i]));
			}
		}
		else{
			if(s.empty())
				return false;
			doll now = s.top();
			s.pop();
			if(now.cap != data[i])
				return false;
		}
	}
	if(!s.empty())
		return false;
	return true;
}

int main()
{
	//freopen("data.txt","r",stdin);
	string s;
	while(getline(cin, s)){
		data.clear();
		stringstream ss(s);
		int h;
		while(ss>>h)
			data.push_back(h);
		if(solve())
			printf(":-) Matrioshka!\n");
		else
			printf(":-( Try again.\n");
	}
	return 0;
}