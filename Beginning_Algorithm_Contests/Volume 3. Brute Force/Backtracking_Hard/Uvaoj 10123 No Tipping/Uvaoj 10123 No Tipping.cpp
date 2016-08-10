/*
//TLE

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 25;

struct package
{
	int p;
	int w;
	package(int p, int w):p(p),w(w){}
	package(){}
};

int l, w, n;

package p[maxn];

int ans[maxn];

void print(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++)
			if(ans[j] == i){
				printf("%d %d\n", p[j].p / 2, p[j].w);
				break;
			}
	}
}

bool isOk(int* vis){
	int right = 0;
	for(int i=0;i<n;i++)
		if(vis[i] == 0)
			right += p[i].w * (p[i].p - 3);
	if(right > 3*w)
		return false;
	int left = 0;
	for(int i=0;i<n;i++)
		if(vis[i] == 0)
			left += p[i].w * (-3 - p[i].p);
	if(left > 3*w)
		return false;
	return true;
}

bool isNotOk(){
	int vis[maxn];
	for(int i=0;i<n;i++)
		vis[i] = 1;
	for(int i=0;i<n;i++){
		vis[i] = 0;
		if(isOk(vis))
			return false;
		vis[i] = 1;
	}
	return true;
}

bool isOk(int* vis, int degree){
	if(!isOk(vis))
		return false;
	if(degree == n+1){
		// for(int i=0;i<n;i++)
		// 	ans[i] = vis[i];
		memcpy(ans, vis, sizeof(ans));
		return true;
	}
	int v[maxn];
	// for(int i=0;i<n;i++)
	// 	v[i] = vis[i];
	memcpy(v, vis, sizeof(v)); 
	for(int i=0;i<n;i++){
		if(v[i] == 0){
			v[i] = degree;
			if(isOk(v, degree+1))
				return true;
			v[i] = 0;
		}
	}
	return false;
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int kase = 0;
	while(scanf("%d%d%d", &l, &w, &n) && l){
		printf("Case %d:\n", ++kase);
		for(int i=0;i<n;i++){
			scanf("%d%d", &p[i].p, &p[i].w);
			p[i].p *= 2; //避免出现分数
		}
		int vis[maxn];
		memset(vis, 0, sizeof(vis));
		if(isNotOk()){
			printf("Impossible\n");
			continue;
		}
		if(!isOk(vis, 1))
			printf("Impossible\n");
		else
			print();
	}
	return 0;
}
*/

/*

//第二个思路，估计也太靠谱···

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 25;

struct package
{
	int p;
	int w;
	package(int p, int w):p(p),w(w){}
	package(){}
};

int l, w, n;

int numFromZero, numFromMax;

package p[maxn];
// package zuo[maxn];
// package you[maxn];

int ans[maxn];

void printFromZero(){
	for(int i=n;i>0;i--){
		for(int j=0;j<n;j++)
			if(ans[j] == i){
				printf("%d %d\n", p[j].p / 2, p[j].w);
				break;
			}
	}
}

bool isOkFromZero(int* vis){
	int right = 0;
	for(int i=0;i<n;i++)
		if(vis[i] != 0)
			right += p[i].w * (p[i].p - 3);
	if(right > 3*w)
		return false;
	int left = 0;
	for(int i=0;i<n;i++)
		if(vis[i] != 0)
			left += p[i].w * (-3 - p[i].p);
	if(left > 3*w)
		return false;
	return true;
}

bool isOkFromZero(int* vis, int degree){
	if(!isOkFromZero(vis))
		return false;
	if(degree == n+1){
		// for(int i=0;i<n;i++)
		// 	ans[i] = vis[i];
		memcpy(ans, vis, sizeof(ans));
		return true;
	}
	int v[maxn];
	// for(int i=0;i<n;i++)
	// 	v[i] = vis[i];
	memcpy(v, vis, sizeof(v)); 
	for(int i=0;i<n;i++){
		if(v[i] == 0){
			v[i] = degree;
			if(isOkFromZero(v, degree+1))
				return true;
			v[i] = 0;
		}
	}
	return false;
}


void print(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++)
			if(ans[j] == i){
				printf("%d %d\n", p[j].p / 2, p[j].w);
				break;
			}
	}
}

bool isOk(int* vis){
	int right = 0;
	for(int i=0;i<n;i++)
		if(vis[i] == 0)
			right += p[i].w * (p[i].p - 3);
	if(right > 3*w)
		return false;
	int left = 0;
	for(int i=0;i<n;i++)
		if(vis[i] == 0)
			left += p[i].w * (-3 - p[i].p);
	if(left > 3*w)
		return false;
	return true;
}

bool isOk(int* vis, int degree){
	if(!isOk(vis))
		return false;
	if(degree == n+1){
		// for(int i=0;i<n;i++)
		// 	ans[i] = vis[i];
		memcpy(ans, vis, sizeof(ans));
		return true;
	}
	int v[maxn];
	// for(int i=0;i<n;i++)
	// 	v[i] = vis[i];
	memcpy(v, vis, sizeof(v)); 
	for(int i=0;i<n;i++){
		if(v[i] == 0){
			v[i] = degree;
			if(isOk(v, degree+1))
				return true;
			v[i] = 0;
		}
	}
	return false;
}

int main()
{
	freopen("data.txt", "r", stdin);
	int kase = 0;
	while(scanf("%d%d%d", &l, &w, &n) && l){
		int right = 0, left = 0;
		numFromMax = numFromZero = 0;
		printf("Case %d:\n", ++kase);
		for(int i=0;i<n;i++){
			scanf("%d%d", &p[i].p, &p[i].w);
			p[i].p *= 2; //避免出现分数
			if(p[i].p > 3)
				right += p[i].w * (p[i].p - 3);
			if(p[i].p < -3)
				left += p[i].w * (-3 - p[i].p);
		}
		if(right <= 3*w && left <= 3*w){
			for(int i=0;i<n;i++)
				ans[i] = i+1;
			printFromZero();
			continue;
		}
		int vis[maxn];
		memset(vis, 0, sizeof(vis));
		if(!isOkFromZero(vis, 1))
			printf("Impossible\n");
		else
			printFromZero();
	}
	return 0;
}
*/

/*

// 第三个pre的思路，没有实现呢，估计也不靠谱··
//而且太尼玛难实现了！

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 25;
const int preNum = 6;

struct package
{
	int p;
	int w;
	package(int p, int w):p(p),w(w){}
	package(){}
};

int l, w, n;

package p[maxn];

int ans[maxn];

void print(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++)
			if(ans[j] == i){
				printf("%d %d\n", p[j].p / 2, p[j].w);
				break;
			}
	}
}

void pre(){

}

bool isOk(int* vis){
	int right = 0;
	for(int i=0;i<n;i++)
		if(vis[i] == 0)
			right += p[i].w * (p[i].p - 3);
	if(right > 3*w)
		return false;
	int left = 0;
	for(int i=0;i<n;i++)
		if(vis[i] == 0)
			left += p[i].w * (-3 - p[i].p);
	if(left > 3*w)
		return false;
	return true;
}

bool isNotOk(){
	int vis[maxn];
	for(int i=0;i<n;i++)
		vis[i] = 1;
	for(int i=0;i<n;i++){
		vis[i] = 0;
		if(isOk(vis))
			return false;
		vis[i] = 1;
	}
	return true;
}

bool isOk(int* vis, int degree){
	if(!isOk(vis))
		return false;
	if(degree == n+1){
		// for(int i=0;i<n;i++)
		// 	ans[i] = vis[i];
		memcpy(ans, vis, sizeof(ans));
		return true;
	}
	int v[maxn];
	// for(int i=0;i<n;i++)
	// 	v[i] = vis[i];
	memcpy(v, vis, sizeof(v)); 
	for(int i=0;i<n;i++){
		if(v[i] == 0){
			v[i] = degree;
			if(isOk(v, degree+1))
				return true;
			v[i] = 0;
		}
	}
	return false;
}

int main()
{
	freopen("data.txt", "r", stdin);
	int kase = 0;
	while(scanf("%d%d%d", &l, &w, &n) && l){
		printf("Case %d:\n", ++kase);
		for(int i=0;i<n;i++){
			scanf("%d%d", &p[i].p, &p[i].w);
			p[i].p *= 2; //避免出现分数
		}
		if(n >= preNum+1){
			pre();
			int vis[maxn];
			memset(vis, 0, sizeof(vis));
			if(isNotOk()){
				printf("Impossible\n");
				continue;
			}
			if(!isOk(vis, 1))
				printf("Impossible\n");
			else
				print();
		}
		else{
			int vis[maxn];
			memset(vis, 0, sizeof(vis));
			if(isNotOk()){
				printf("Impossible\n");
				continue;
			}
			if(!isOk(vis, 1))
				printf("Impossible\n");
			else
				print();
		}
	}
	return 0;
}

*/


#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 25;
const int maxState = (1<<20) + 5;

struct package
{
	int p;
	int w;
	package(int p, int w):p(p),w(w){}
	package(){}
};

int l, w, n;

package p[maxn];

int ans[maxn];

bool visit[maxState];

int make(int* vis){
	int ans = 0;
	for(int i=0;i<n;i++){
		ans = ans<<1;
		ans += vis[i]>0?1:0;
	}
	return ans;
}

void print(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++)
			if(ans[j] == i){
				printf("%d %d\n", p[j].p / 2, p[j].w);
				break;
			}
	}
}

bool isOk(int* vis){
	int right = 0;
	for(int i=0;i<n;i++)
		if(vis[i] == 0)
			right += p[i].w * (p[i].p - 3);
	if(right > 3*w)
		return false;
	int left = 0;
	for(int i=0;i<n;i++)
		if(vis[i] == 0)
			left += p[i].w * (-3 - p[i].p);
	if(left > 3*w)
		return false;
	return true;
}

bool isNotOk(){
	int vis[maxn];
	for(int i=0;i<n;i++)
		vis[i] = 1;
	for(int i=0;i<n;i++){
		vis[i] = 0;
		if(isOk(vis))
			return false;
		vis[i] = 1;
	}
	return true;
}

bool isOk(int* vis, int degree){
	int now = make(vis);
	if(visit[now])
		return false;
	visit[now] = 1;
	if(!isOk(vis))
		return false;
	if(degree == n+1){
		// for(int i=0;i<n;i++)
		// 	ans[i] = vis[i];
		memcpy(ans, vis, sizeof(ans));
		return true;
	}
	int v[maxn];
	// for(int i=0;i<n;i++)
	// 	v[i] = vis[i];
	memcpy(v, vis, sizeof(v)); 
	for(int i=0;i<n;i++){
		if(v[i] == 0){
			v[i] = degree;
			if(isOk(v, degree+1))
				return true;
			v[i] = 0;
		}
	}
	return false;
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int kase = 0;
	while(scanf("%d%d%d", &l, &w, &n) && l){
		memset(visit, 0, sizeof(visit));
		printf("Case %d:\n", ++kase);
		for(int i=0;i<n;i++){
			scanf("%d%d", &p[i].p, &p[i].w);
			p[i].p *= 2; //避免出现分数
		}
		int vis[maxn];
		memset(vis, 0, sizeof(vis));
		if(isNotOk()){
			printf("Impossible\n");
			continue;
		}
		if(!isOk(vis, 1))
			printf("Impossible\n");
		else
			print();
	}
	return 0;
}