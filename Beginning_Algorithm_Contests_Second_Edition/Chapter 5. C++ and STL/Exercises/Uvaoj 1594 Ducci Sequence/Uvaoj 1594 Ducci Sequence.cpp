#include <cstdio>
#include <set>
#include <cstdlib>
using namespace std;

const int maxn = 17;

struct ducci{
	int n;
	int data[maxn];
	friend bool operator < (const ducci & a, const ducci & b){
		for(int i=0;i<a.n;i++){
			if(a.data[i] != b.data[i])
				return a.data[i] < b.data[i];
		}
		return false;
	}
};

bool isZero(const ducci & cur){
	for(int i=0;i<cur.n;i++)
		if(cur.data[i] != 0)
			return false;
	return true;
}

ducci next(ducci cur){
	ducci ans;
	ans.n = cur.n;
	for(int i=0;i<cur.n-1;i++)
		ans.data[i] = abs(cur.data[i+1] - cur.data[i]);
	ans.data[cur.n-1] = abs(cur.data[0] - cur.data[cur.n-1]);
	return ans;
}

void solve(ducci start){
	if(isZero(start)){
		printf("ZERO\n");
		return;
	}
	set<ducci> s;
	while(!isZero(start)){
		s.insert(start);
		start = next(start);
		auto look = s.find(start);
		if(look != s.end()){
			printf("LOOP\n");
			return;
		}
	}
	printf("ZERO\n");
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++){
		int n;
		ducci start;
		scanf("%d", &start.n);
		for(int i=0;i<start.n;i++)
			scanf("%d", &start.data[i]);
		solve(start);
	}
	return 0;
}