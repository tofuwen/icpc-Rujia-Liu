#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 10;

int n;

char charList[maxn*2+5];

void solve(vector<int> v){
	int num = v.size();
	if(num == n){
		char hold[2*maxn+5];
		for(int i=0;i<2*n-1;i++)
			if(i % 2)
				hold[i] = ',';
			else
				hold[i] = v[i/2]+'a';
		hold[2*n-1] = '\0';
		printf("writeln(%s)\n", hold);
		return;
	}
	for(int i=num;i>=1;i--){
		vector<int> h = v;
		printf("if %c < %c then\n", v[i-1]+'a', num+'a');
		h.insert(h.begin()+i, num);
		solve(h);
		printf("else\n");
	}
	v.insert(v.begin(), num);
	solve(v);
}

void solve(){
	vector<int> v;
	if(n == 1){
		printf("writeln(a)\n");
		return;
	}
	printf("if a < b then\n");
	v.push_back(0);
	v.push_back(1);
	solve(v);
	printf("else\n");
	v.clear();
	v.push_back(1);
	v.push_back(0);
	solve(v);
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++){
		if(cc)
			printf("\n");
		scanf("%d", &n);
		for(int i=0;i<2*n-1;i++){
			if(i % 2)
				charList[i] = ',';
			else
				charList[i] = 'a'+i/2;
		}
		charList[2*n-1] = '\0';
		printf("program sort(input,output);\nvar\n%s : integer;\nbegin\nreadln(%s);\n", charList, charList);
		solve();
		printf("end.\n");
	}
	return 0;
}