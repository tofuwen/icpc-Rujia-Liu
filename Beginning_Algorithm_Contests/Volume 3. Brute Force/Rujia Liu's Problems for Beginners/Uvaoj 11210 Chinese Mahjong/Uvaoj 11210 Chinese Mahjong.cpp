#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int makeType(char c){
	if(c == 'T')
		return 1;
	if(c == 'S')
		return 2;
	if(c == 'W')
		return 3;
	return 0;
}

void makeMahjong(char* c, int& value, int& type){
	type = 4;
	if(c[0] == 'D'){
		value = 1;
		return;
	}
	if(c[0] == 'N'){
		value = 2;
		return;
	}
	if(c[0] == 'X'){
		value = 3;
		return;
	}
	if(c[0] == 'Z'){
		value = 5;
		return;
	}
	if(c[0] == 'F'){
		value = 6;
		return;
	}
	if(c[1] == 'E'){
		value = 4;
		return;
	}
	value = 7;
}

struct mahjong
{
	int value;
	int type;
	mahjong(char* c){
		if(c[0]>='0' && c[0]<='9'){
			this->value = c[0]-'0';
			this->type = makeType(c[1]);
		}
		else
			makeMahjong(c, this->value, this->type);
	}
	mahjong(int value, int type):value(value),type(type){}
};

void print(int value, int type){
	char hold[3] = {'T','S','W'};
	char fa[10][10] = {"DONG","NAN","XI","BEI","ZHONG","FA","BAI"};
	if(type <= 3)
		printf(" %c%c", value+'0', hold[type-1]);
	else
		printf(" %s", fa[value-1]);
}

char c[7];

bool solveFeng(vector<int> v){
	int num[10];
	memset(num, 0, sizeof(num));
	for(int i=0;i<v.size();i++)
		num[v[i]]++;
	for(int i=0;i<10;i++)
		if(num[i] % 3 != 0)
			return false;
	return true;
}

bool solveList(vector<int> v){
	if(v.size() == 0)
		return true;
	int num[15];
	memset(num, 0, sizeof(num));
	for(int i=0;i<v.size();i++)
		num[v[i]]++;
	sort(v.begin(), v.end());
	int start = v[0];
	if(num[start] >= 3){
		vector<int> h;
		for(int i=3;i<v.size();i++)
			h.push_back(v[i]);
		bool ok = solveList(h);
		if(ok)
			return true;
	}
	for(int i=0;i<3;i++){
		int now = start + i;
		num[now]--;
		if(num[now] < 0)
			return false;
	}
	vector<int> h;
	for(int i=0;i<15;i++)
		for(int j=0;j<num[i];j++)
			h.push_back(i);
	return solveList(h);
}

bool solve12(vector<int>* v){
	for(int i=1;i<=4;i++)
		if(v[i].size() % 3 != 0)
			return false;
	for(int i=1;i<=3;i++){
		bool okay = solveList(v[i]);
		if(!okay)
			return false;
	}
	return solveFeng(v[4]);
}

bool solve(vector<mahjong> v){
	int num[50];
	memset(num, 0, sizeof(num));
	for(int i=0;i<v.size();i++){
		int k = v[i].type*10 + v[i].value;
		num[k]++;
	}
	bool okay = false;
	for(int i=0;i<50;i++){
		if(num[i] >= 2){
			vector<int> vv[7];
			for(int j=0;j<50;j++)
				if(j != i)
					for(int k=0;k<num[j];k++)
						vv[j/10].push_back(j%10);
				else
					for(int k=0;k<num[j]-2;k++)
						vv[j/10].push_back(j%10);
			bool ok = solve12(vv);
			if(ok)
				okay = true;
		}
	}
	return okay;
}

int main()
{
	//freopen("data.txt","r",stdin);
	vector<mahjong> v;
	int kase = 0;
	while(scanf("%s", c) && c[0] != '0'){
		int num[50];
		memset(num, 0, sizeof(num));
		printf("Case %d:", ++kase);
		v.clear();
		mahjong hold = mahjong(c);
		v.push_back(hold);
		num[hold.type*10+hold.value]++;
		for(int i=1;i<=12;i++){
			scanf("%s", c);
			mahjong hold = mahjong(c);
			v.push_back(hold);
			num[hold.type*10+hold.value]++;
		}
		bool isOkay = false;
		for(int type=1;type<=4;type++){
			int nnum = type==4?7:9;
			for(int i=1;i<=nnum;i++) if(num[i+type*10] < 4){
				vector<mahjong> h = v;
				h.push_back(mahjong(i,type));
				bool okay = solve(h);
				if(okay){
					isOkay = true;
					print(i, type);
				}
			}
		}
		if(!isOkay)
			printf(" Not ready\n");
		else
			printf("\n");
	}
	return 0;
}