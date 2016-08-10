#include <cstdio>
#include <cstring>
#include <algorithm> 
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int maxn = 35;
const int maxf = 22;
const int alp = 30;
long long n;

struct part{
	char c;
	int t;
	part(char c, int t):c(c),t(t){}
	friend bool operator < (const part& a, const part& b){
		return a.c < b.c;
	}
};

char data[maxn];
int num[alp];
long long f[maxf];

void pre(){
	f[0] = 1;
	for(int i=1;i<maxf;i++)
		f[i] = i*f[i-1];
}

long long cal(vector<part> v, int index, int l){
	long long ans = f[l-1];
	for(int i=0;i<v.size();i++)
		if(i == index)
			ans /= f[v[i].t-1];
		else
			ans /= f[v[i].t];
	return ans;
}

string makeString(vector<part> v, long long k, int l){
	if(v.size() == 1){
		string ans = "";
		for(int i=0;i<v[0].t;i++)
			ans += v[0].c;
		return ans;
	}
	long long pre = 0;
	long long now = 0;
	for(int i=0;i<v.size();i++){
		pre = now;
		now += cal(v,i,l);
		if(now >= k){
			v[i].t--;
			char h = v[i].c;
			if(v[i].t == 0)
				v.erase(v.begin()+i);
			return h + makeString(v, k-pre, l-1);
		}
	}
	return "";
}

int main()
{
	//freopen("data.txt","r",stdin);
	pre();
	int T;
	scanf("%d",&T);
	for(int cc=1;cc<=T;cc++){
		printf("Case %d: ", cc);
		scanf("%s%lld",data, &n);
		int l = strlen(data);
		memset(num, 0, sizeof(num));
		for(int i=0;i<l;i++)
			num[data[i]-'a']++;
		int numOdd = 0;
		int hold = -1;
		for(int i=0;i<alp;i++)
			if(num[i]%2 == 1){
				numOdd++;
				hold = i;
			}
		if((l%2 == 0 && numOdd != 0) || (l%2 == 1 && numOdd != 1)){
			printf("XXX\n");
			continue;
		}
		vector<part> v;
		for(int i=0;i<alp;i++)
			if(num[i]/2 > 0)
				v.push_back(part('a'+i, num[i]/2));
		//printf("%d",v.size());
		long long all = f[l/2];
		for(int i=0;i<v.size();i++)
			all /= f[v[i].t];
		if(n > all){
			printf("XXX\n");
			continue;
		}
		//printf("%lld\n",all);
		string ans = makeString(v, n, l/2);
		int len = ans.length();
		if(hold != -1)
			ans += 'a'+hold;
		for(int i=0;i<len;i++)
			ans += ans[len-1-i];
		cout<<ans<<endl;
	}
	return 0;
}