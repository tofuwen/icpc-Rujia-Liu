#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 10;

int com[maxn];

bool next_Com(int num, int k)//0,1...num-1 choose k
{
	if(k == 0)
		return false;
	if(com[k-1]!=num-1)
	{
		com[k-1]++;
		return true;
	}
	int i;
	for(i=k-1;i>=0;i--)
		if(com[i]!=num-k+i)
			break;
	if(i==-1)
		return false;
	com[i]++;
	for(int j=i+1;j<k;j++)
		com[j] = com[i]+(j-i);
	return true;
}

void makeFirstCom(int k)
{
	for(int i=0;i<k;i++)
		com[i] = i;
}

int change(char c){
	if(c == 'T')
		return 10;
	if(c == 'J')
		return 11;
	if(c == 'Q')
		return 12;
	if(c == 'K')
		return 13;
	if(c == 'A')
		return 1;
	return c-'0';
}

int makeSuit(char c){
	if(c == 'C')
		return 0;
	if(c == 'D')
		return 1;
	if(c == 'H')
		return 2;
	return 3;
}

struct Texas
{
	int suit;
	int v;
	Texas(char* s){
		this->suit = makeSuit(s[1]);
		this->v = change(s[0]);
	}
};

bool vCompare(Texas a, Texas b){
	if(a.v == b.v)
		return a.suit < b.suit;
	return a.v < b.v;
}

bool suitCompare(Texas a, Texas b){
	if(a.suit == b.suit)
		return a.v < b.v;
	return a.suit < b.suit;
}

char hand[maxn][5];
char deck[maxn][5];

char ans[10][100] = {"straight-flush", "four-of-a-kind", "full-house", "flush", "straight", "three-of-a-kind", "two-pairs", "one-pair", "highest-card"};

bool isFourKind(vector<Texas> v){
	int num[15];
	memset(num, 0, sizeof(num));
	for(int i=0;i<5;i++)
		num[v[i].v]++;
	for(int i=0;i<15;i++)
		if(num[i] == 4)
			return true;
	return false;
}

bool isFullHouse(vector<Texas> v){
	bool num[15];
	int Num = 0;
	memset(num, 0, sizeof(num));
	for(int i=0;i<5;i++)
		if(!num[v[i].v]){
			num[v[i].v] = true;
			Num++;
		}
	return Num == 2;
}

bool isFlush(vector<Texas> v){
	int suit = v[0].suit;
	for(int i=1;i<5;i++)
		if(v[i].suit != suit)
			return false;
	return true;
}

bool isStraight(vector<Texas> v){
	sort(v.begin(), v.end(), vCompare);
	int start = v[0].v;
	bool ans = true;
	for(int i=1;i<5;i++)
		if(v[i].v != i+start)
			ans = false;
	if(ans)
		return true;
	ans = true;
	if(v[0].v == 1){
		for(int i=1;i<5;i++)
			if(v[i].v != 9+i)
				ans = false;
		return ans;
	}
	else
		return false;
}

bool isThreeKind(vector<Texas> v){
	int num[15];
	memset(num, 0, sizeof(num));
	for(int i=0;i<5;i++)
		num[v[i].v]++;
	for(int i=0;i<15;i++)
		if(num[i] == 3)
			return true;
	return false;
}

bool isTwoPair(vector<Texas> v){
	bool num[15];
	int Num = 0;
	memset(num, 0, sizeof(num));
	for(int i=0;i<5;i++)
		if(!num[v[i].v]){
			num[v[i].v] = true;
			Num++;
		}
	return Num == 3;
}

bool isOnePair(vector<Texas> v){
	bool num[15];
	int Num = 0;
	memset(num, 0, sizeof(num));
	for(int i=0;i<5;i++)
		if(!num[v[i].v]){
			num[v[i].v] = true;
			Num++;
		}
	return Num == 4;
}

bool isStraightFlush(vector<Texas> v){
	return isFlush(v) && isStraight(v);
}

int check(vector<Texas> v){
	if(isStraightFlush(v))
		return 0;
	if(isFourKind(v))
		return 1;
	if(isFullHouse(v))
		return 2;
	if(isFlush(v))
		return 3;
	if(isStraight(v))
		return 4;
	if(isThreeKind(v))
		return 5;
	if(isTwoPair(v))
		return 6;
	if(isOnePair(v))
		return 7;
	return 8;
}

int solve(){
	vector<Texas> v;
	int ans = 100;
	for(int i=0;i<=5;i++){
		makeFirstCom(i);
		do{
			v.clear();
			for(int j=0;j<i;j++)
				v.push_back(Texas(hand[com[j]]));
			int remain = 5-i;
			for(int j=0;j<remain;j++)
				v.push_back(Texas(deck[j]));
			ans = min(ans, check(v));
		}while(next_Com(5, i));
	}
	return ans;
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%s", hand[0]) != EOF){
		for(int i=1;i<5;i++)
			scanf("%s", hand[i]);
		for(int i=0;i<5;i++)
			scanf("%s", deck[i]);
		printf("Hand: ");
		for(int i=0;i<5;i++)
			printf("%s ", hand[i]);
		printf("Deck: ");
		for(int i=0;i<5;i++)
			printf("%s ", deck[i]);
		printf("Best hand: %s\n", ans[solve()]);
	}
	return 0;
}