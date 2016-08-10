#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 100001;
const int maxn = 55;

int n;

int data[maxn][maxn];

struct state
{
	vector<long long> v;
};

vector<state> hash[mod];

long long make(int *a){
	long long ans = 0;
	for(int i=0;i<n;i++){
		ans = ans << 1;
		ans += a[i];
	}
	return ans;
}

state makeState(int a[][maxn]){
	state s;
	s.v.clear();
	for(int i=0;i<n;i++)
		s.v.push_back(make(a[i]));
	return s;
}

bool isExist(state s){
	int k = (int)(s.v[0] % mod);
	for(int i=0;i<hash[k].size();i++)
		if(hash[k][i].v == s.v)
			return true;
	return false;
}

void Add(state s){
	int k = (int)(s.v[0] % mod);
	hash[k].push_back(s);
}

void rotate(int ori[][maxn], int after[][maxn]){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			after[j][n-i-1] = ori[i][j];
}

void print(int data[][maxn]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d ", data[i][j]);
		printf("\n");
	}
	printf("\n");
}

bool check(int data[][maxn]){
	vector<state> h;
	state now = makeState(data);
	//print(data);
	if(isExist(now))
		return true;
	h.push_back(now);
	int hold[4][maxn][maxn];
	for(int i=0;i<3;i++){
		if(i == 0)
			rotate(data, hold[i]);
		else
			rotate(hold[i-1], hold[i]);
		//print(hold[i]);
		state now = makeState(hold[i]);
		if(isExist(now))
			return true;
		h.push_back(now);
	}
	for(int i=0;i<h.size();i++)
		Add(h[i]);
	return false;
}

int main()
{
	//freopen("data.txt", "r", stdin);
	while(scanf("%d", &n) && n){
		//printf("%d\n", n);
		bool okay = true;
		for(int i=0;i<mod;i++)
			hash[i].clear();
		memset(data, 0, sizeof(data));
		Add(makeState(data));
		for(int i=0;i<2*n;i++){
			int x, y;
			char o;
			scanf("%d %d %c", &x, &y, &o);
			if(!okay)
				continue;
			if(o == '+')
				data[x-1][y-1] = 1;
			else
				data[x-1][y-1] = 0;
			if(check(data)){
				printf("Player %d wins on move %d\n",i%2==0?2:1, i+1);
				okay = false;
			}
		}
		if(okay)
			printf("Draw\n");
	}
	return 0;
}