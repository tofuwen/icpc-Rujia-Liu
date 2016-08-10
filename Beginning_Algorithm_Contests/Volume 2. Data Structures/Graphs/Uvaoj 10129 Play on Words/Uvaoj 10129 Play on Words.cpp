/*
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

const int alp = 27;

int n;
int numEqual;

bool isEqual[alp];
int numS[alp];
int numF[alp];

vector<string> v;
vector<int> head[alp];
int nowIndex[alp];
//vector<int> tail[alp];

int start;

bool solve(){
	for(int i=0;i<alp;i++)
		if(isEqual[i])
			if(numS[i] == 0 && numF[i] == 0)
				return false;
	int numStart = 0, numFinish = 0;
	for(int i=0;i<alp;i++)
		if(numS[i] > numF[i]){
			numStart += numS[i]-numF[i];
			start = head[i][0];
		}
		else
			numFinish += numF[i]-numS[i];
	if(numStart > 1 || numFinish > 1)
		return false;
	return true;
}

bool solve2(){
	memset(nowIndex, 0, sizeof(nowIndex));
	int num = 1;
	int l = v[start].length();
	int nextChar = v[start][l-1] - 'a';
	int firstChar = v[start][0] - 'a';
	nowIndex[firstChar]++;
	while(num < n-numEqual){
		//printf("num:%d n:%d", num, n);
		if(head[nextChar].size() == nowIndex[nextChar])
			return false;
		num++;
		int now = head[nextChar][nowIndex[nextChar]];
		nowIndex[nextChar]++;
		int l = v[now].length();
		nextChar = v[now][l-1]-'a';
	}
	return true;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++){
		scanf("%d",&n);
		memset(isEqual, 0, sizeof(isEqual));
		memset(numS,0,sizeof(numS));
		memset(numF,0,sizeof(numF));
		v.clear();
		for(int i=0;i<alp;i++)
			head[i].clear();
		start = numEqual = 0;// start 初始为0是不对的！！因为有可能第0个是"mm"。。首位字母相同！
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			v.push_back(s);
			int l = s.length();
			if(s[0] == s[l-1]){
				isEqual[s[0]-'a'] = true;
				numEqual++;
			}
			else{
				int h = s[0] - 'a';
				int t = s[l-1] - 'a';
				numS[h]++;
				head[h].push_back(i);
				start = i;
				numF[t]++;
				//tail[t].push_back(i);
			}
		}
		bool ok = solve();
		if(ok){
			bool ok2 = solve2();
			if(ok2)
				printf("Ordering is possible.\n");
			else
				printf("The door cannot be opened.\n");
		}
		else
			printf("The door cannot be opened.\n");
	}
	return 0;


*/

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

const int alp = 27;

int n;

bool isEqual[alp];
bool is[alp];
int numS[alp];
int numF[alp];
bool vis[alp];

vector<int> v[alp];
int start;

bool solve(){
	for(int i=0;i<alp;i++)
		if(isEqual[i])
			if(numS[i] == 0 && numF[i] == 0)
				return false; // 不对！！只有一个aa也是可行的！！！
	int numStart = 0, numFinish = 0;
	for(int i=0;i<alp;i++)
		if(numS[i] > numF[i]){
			numStart += numS[i]-numF[i];
		}
		else
			numFinish += numF[i]-numS[i];
	if(numStart > 1 || numFinish > 1)
		return false;
	return true;
}

void dfs(int s){
	vis[s] = true;
	for(int i=0;i<v[s].size();i++){
		int next = v[s][i];
		if(!vis[next])
			dfs(next);
	}
}

bool solve2(){ // 判断是否连通（忽略边的方向后）
	memset(vis, 0 ,sizeof(vis));
	dfs(start);
	for(int i=0;i<alp;i++)
		if(is[i] && !vis[i])
			return false;
	return true;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++){
		scanf("%d",&n);
		memset(isEqual, 0, sizeof(isEqual));
		memset(numS,0,sizeof(numS));
		memset(numF,0,sizeof(numF));
		memset(is,0,sizeof(is));
		for(int i=0;i<alp;i++)
			v[i].clear();
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			int l = s.length();
			if(s[0] == s[l-1]){
				isEqual[s[0]-'a'] = true;
				//is[s[0]-'a'] = true;
			}
			else{
				int h = s[0] - 'a';
				int t = s[l-1] - 'a';
				start = t;
				is[h] = is[t] = true;
				numS[h]++;
				v[h].push_back(t);
				numF[t]++;
				v[t].push_back(h);
			}
		}
		if(n == 1){
			printf("Ordering is possible.\n");
			continue;
		}
		bool ok = solve();
		if(ok){
			bool ok2 = solve2();
			if(ok2)
				printf("Ordering is possible.\n");
			else
				printf("The door cannot be opened.\n");
		}
		else
			printf("The door cannot be opened.\n");
	}
	return 0;
}