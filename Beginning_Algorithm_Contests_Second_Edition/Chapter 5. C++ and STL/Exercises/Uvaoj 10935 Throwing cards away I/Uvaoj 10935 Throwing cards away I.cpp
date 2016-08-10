#include <cstdio>
#include <list>
using namespace std;

void solve(int n){
	list<int> l;
	for(int i=1;i<=n;i++)
		l.push_back(i);
	printf("Discarded cards:");
	int num = 0;
	while(l.size() > 1){
		if(num < n-2)
			printf(" %d,", *l.begin());
		else
			printf(" %d", *l.begin());
		num++;
		l.pop_front();
		l.push_back(*l.begin());
		l.pop_front();
	}
	printf("\nRemaining card: %d\n", *l.begin());
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int n;
	while(scanf("%d", &n) && n){
		solve(n);
	}
	return 0;
}