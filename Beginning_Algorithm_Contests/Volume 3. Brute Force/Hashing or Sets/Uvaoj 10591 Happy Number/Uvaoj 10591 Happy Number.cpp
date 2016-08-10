#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int mod = 10001;

int n;

vector<int> hash[mod];

bool isExist(int a){
	int k = a % mod;
	for(int i=0;i<hash[k].size();i++)
		if(hash[k][i] == a)
			return true;
	return false;
}

void Insert(int a){
	int k = a % mod;
	hash[k].push_back(a);
}

bool isHappy(int a){
	//printf("%d\n", a);
	if(a == 1)
		return true;
	if(isExist(a))
		return false;
	Insert(a);
	int next = 0;
	char c[100];
	sprintf(c, "%d", a);
	for(int i=0;i<strlen(c);i++)
		next += (c[i]-'0')*(c[i]-'0');
	return isHappy(next);
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=1;cc<=T;cc++){
		for(int i=0;i<mod;i++)
			hash[i].clear();
		scanf("%d", &n);
		if(isHappy(n))
			printf("Case #%d: %d is a Happy number.\n", cc, n);
		else
			printf("Case #%d: %d is an Unhappy number.\n", cc, n);
	}
	return 0;
}