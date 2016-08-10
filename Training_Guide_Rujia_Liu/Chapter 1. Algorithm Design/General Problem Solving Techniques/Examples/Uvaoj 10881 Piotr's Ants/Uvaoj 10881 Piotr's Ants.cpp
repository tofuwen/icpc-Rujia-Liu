/*
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 10010;

int l, t, n;

struct ant
{
	int id;
	int num;
	int start;
	char direction;
	vector<int> collisionTime2;
	ant(int id, int start, char direction){
		this->id = id;
		this->start = start;
		this->direction = direction;
		collisionTime2.clear();
	}
	ant(){}
};

ant rants[maxn];
ant lants[maxn];
int rnum, lnum;

int main()
{
	freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++){
		scanf("%d%d%d",&l,&t,&n);
		for(int i=0;i<n;i++){
			lnum = rnum = 0;
			int start;
			char d[5];
			scanf("%d%s",&start, d);
			if(d[0] == 'R')
				rants[rnum++] = ant(i, start, d[0]);
			else
				lants[lnum++] = ant(i, start, d[0]);
		}
	}
	return 0;
}
*/


#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10010;

int l, t, n;

struct ants
{
	int position;
	char direction;
	ants(int position, char direction):position(position), direction(direction){}
	ants(){}
	friend bool operator < (const ants& a, const ants& b){
		return a.position < b.position;
	}
};

ants a[maxn];
ants after[maxn];
int order[maxn];
int oorder[maxn];

bool compare(int i, int j)
{
	// //防止初始数据有相同坐标的。不过好像没用···
	// double ih = a[i].direction == 'R'?0.1:-0.1;
	// double jh = a[j].direction == 'R'?0.1:-0.1;
	// double iprime = a[i].position + ih;
	// double jprime = a[j].position + jh;
     return a[i].position < a[j].position;
 //    return iprime < jprime;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int cc=1;cc<=T;cc++){
		printf("Case #%d:\n", cc);
		scanf("%d%d%d",&l,&t,&n);
		if(n > 0){
			for(int i=0;i<n;i++){
				int p;
				char c[5];
				scanf("%d%s",&p,c);
				a[i] = ants(p,c[0]);
			}
			for(int i=0;i<n;i++)
				oorder[i] = i;
			sort(oorder, oorder+n, compare);
			for(int i=0;i<n;i++)
				order[oorder[i]] = i;
			// for(int i=0;i<n;i++)
			// 	printf(" a[]: %d order: %d\n",a[i].position, order[i]);
			for(int i=0;i<n;i++){
				int p;
				if(a[i].direction == 'R')
					p = a[i].position + t;
				else
					p = a[i].position - t;
				after[i] = ants(p, a[i].direction);
			}
			sort(after, after+n);
			for(int i=0;i<n;i++){
				int o = order[i];
				bool isTurning = false;
				if(after[o].position < 0 || after[o].position > l){
					printf("Fell off\n");
					continue;
				}
				if(o > 0 && after[o].position == after[o-1].position)
					isTurning = true;
				if(o < n-1 && after[o].position == after[o+1].position)
					isTurning = true;
				if(isTurning)
					printf("%d Turning\n", after[o].position);
				else{
					char anss[5];
					anss[0] = after[o].direction;
					anss[1] = '\0';
					printf("%d %s\n",after[o].position, anss);
				}
			}
		}
		printf("\n");
	}
	return 0;
}