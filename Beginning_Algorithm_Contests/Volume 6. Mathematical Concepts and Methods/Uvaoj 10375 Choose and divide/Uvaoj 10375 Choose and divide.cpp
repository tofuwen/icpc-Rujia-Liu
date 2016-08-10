#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int a[5];
int b[5];

double f(int c, int d){
	if(c == d)
		return 1;
	int M = max(c,d);
	int m = min(c,d);
	double h = 1;
	for(int i=m+1;i<=M;i++)
		h *= i;
	if(c > d)
		return h;
	return 1/h;
}

double g(){
	double ans = 1;
	while(1){
		for(int i=0;i<3;i++){
			if(a[i] > 1){
				ans *= a[i];
				a[i]--;
			}
			if(b[i] > 1){
				ans /= b[i];
				b[i]--;
			}
		}
		bool ok = true;
		for(int i=0;i<3;i++)
			if(a[i]>1 || b[i]>1)
				ok = false;
		if(ok)
			break;
	}
	return ans;
}

double solve(int k){
	double ans = 0;
	for(int i=2;i<=k;i++)
		ans += log(i);
	return ans;
}

double h(){
	double ans = 0;
	for(int i=0;i<3;i++){
		ans += solve(a[i]);
		ans -= solve(b[i]);
	}
	return exp(ans);
}

double final(){
	vector<pair<int, int> > big;
	vector<pair<int, int> > small;
	for(int i=0;i<3;i++){
		if(a[i] > b[i])
			big.push_back(make_pair(a[i], b[i]));
		if(a[i] < b[i])
			small.push_back(make_pair(b[i], a[i]));
	}
	double ans = 1;
	while(1){
		for(int i=0;i<big.size();i++)
			if(big[i].second < big[i].first){
				ans *= (big[i].second+1);
				big[i].second++;
			}
		for(int i=0;i<small.size();i++)
			if(small[i].second < small[i].first){
				ans /= (small[i].second+1);
				small[i].second++;
			}
		bool ok = true;
		for(int i=0;i<big.size();i++)
			if(big[i].second < big[i].first)
				ok = false;
		for(int i=0;i<small.size();i++)
			if(small[i].second < small[i].first)
				ok = false;
		if(ok)
			break;
	}
	return ans;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int p,q,r,s;
	while(scanf("%d%d%d%d",&p,&q,&r,&s) != EOF){
		a[0] = p;
		a[1] = r-s;
		a[2] = s;
		b[0] = p-q;
		b[1] = q;
		b[2] = r;
		sort(a,a+3);
		sort(b,b+3);
		// double ans = 1;
		// for(int i=0;i<3;i++)
		// 	ans *= f(a[i],b[i]);
		// printf("%.5f\n",ans);
		//printf("%.5f\n",g());
		//printf("%.5f\n",h());
		printf("%.5f\n",final());
	}
	return 0;
}