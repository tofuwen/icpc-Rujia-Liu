/*
//TLE! O(nlogn) why?
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
set<int> dragon;
set<int> warrior;
long long ans;

bool solve(set<int>& d, set<int>& w){
	if(d.empty())
		return true;
	set<int>::iterator iter1 = d.begin();
	set<int>::iterator iter2 = lower_bound(w.begin(), w.end(), *iter1);
	if(iter2 == w.end())
		return false;
	ans += *iter2;
	d.erase(iter1);
	w.erase(iter2);
	return solve(d,w);
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d%d",&n,&m) && n){
		dragon.clear();
		warrior.clear();
		for(int i=0;i<n;i++){
			int h;
			scanf("%d",&h);
			dragon.insert(h);
		}
		for(int i=0;i<m;i++){
			int h;
			scanf("%d",&h);
			warrior.insert(h);
		}
		if(n > m){
			printf("Loowater is doomed!\n");
			continue;
		}
		ans = 0;
		bool okay = solve(dragon, warrior);
		if(okay)
			printf("%lld\n",ans);
		else
			printf("Loowater is doomed!\n");
	}
	return 0;
}
*/

/*
// still TLE!
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

const int maxn = 20010;

int n, m;
int dragon[maxn];
multiset<int> warrior;
long long ans;

bool solve(int* d, int now, multiset<int>& w){
	if(now == -1)
		return true;
	set<int>::iterator iter2 = lower_bound(w.begin(), w.end(), d[now]);
	if(iter2 == w.end())
		return false;
	ans += *iter2;
	w.erase(iter2);
	return solve(d,now-1,w);
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d%d",&n,&m) && n){
		warrior.clear();
		for(int i=0;i<n;i++)
			scanf("%d",&dragon[i]);
		sort(dragon,dragon+n);
		for(int i=0;i<m;i++){
			int h;
			scanf("%d",&h);
			warrior.insert(h);
		}
		if(n > m){
			printf("Loowater is doomed!\n");
			continue;
		}
		ans = 0;
		bool okay = solve(dragon, n-1, warrior);
		if(okay)
			printf("%lld\n",ans);
		else
			printf("Loowater is doomed!\n");
	}
	return 0;
}
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 20010;

int n, m;
int dragon[maxn];
int warrior[maxn];
long long ans;

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d%d",&n,&m) && n){
		for(int i=0;i<n;i++)
			scanf("%d",&dragon[i]);
		for(int i=0;i<m;i++)	
			scanf("%d",&warrior[i]);
		if(n > m){
			printf("Loowater is doomed!\n");
			continue;
		}
		sort(dragon,dragon+n);
		sort(warrior,warrior+m);
		ans = 0;
		int d = 0, w = 0;
		while(d<n && w<m ){
			if(warrior[w] >= dragon[d]){
				ans += warrior[w];
				w++;
				d++;
			}
			else
				w++;
		}
		if(d == n)
			printf("%lld\n",ans);
		else
			printf("Loowater is doomed!\n");
	}
	return 0;
}

