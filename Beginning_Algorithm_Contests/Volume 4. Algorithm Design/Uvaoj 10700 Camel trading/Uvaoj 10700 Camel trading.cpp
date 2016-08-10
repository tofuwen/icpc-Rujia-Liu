#include <cstdio>
#include <cstring>
using namespace std;

const int maxl = 10000;
const int maxn = 15;
long long num[maxn];
char o[maxn];

long long f(long long* num, int numNum, char* o, int numO){
	int k;
	for(k=0;k<numO;k++){
		if(o[k] == '*')
			break;
	}
	if(k == numO){
		long long ans = 0;
		for(int i=0;i<numNum;i++)
			ans += num[i];
		return ans;
	}
	long long num0[maxn];
	char o0[maxn];
	for(int i=0;i<k;i++){
		num0[i] = num[i];
		o0[i] = o[i];
	}
	num0[k] = num[k]*num[k+1];
	for(int i=k+1;i<numNum-1;i++)
		num0[i] = num[i+1];
	for(int i=k;i<numO-1;i++)
		o0[i] = o[i+1];
	return f(num0,numNum-1,o0,numO-1);
}

long long g(long long* num, int numNum, char* o, int numO){
	int k;
	for(k=0;k<numO;k++){
		if(o[k] == '+')
			break;
	}
	if(k == numO){
		long long ans = 1;
		for(int i=0;i<numNum;i++)
			ans *= num[i];
		return ans;
	}
	long long num0[maxn];
	char o0[maxn];
	for(int i=0;i<k;i++){
		num0[i] = num[i];
		o0[i] = o[i];
	}
	num0[k] = num[k]+num[k+1];
	for(int i=k+1;i<numNum-1;i++)
		num0[i] = num[i+1];
	for(int i=k;i<numO-1;i++)
		o0[i] = o[i+1];
	return g(num0,numNum-1,o0,numO-1);
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T = 0;
	scanf("%d",&T);
	char data[maxl];
	for(int cc=0;cc<T;cc++){
		scanf("%s",data);
		int l = strlen(data);
		int indexO = 0, indexNum = 0;
		memset(num,0,sizeof(num));
		for(int i=0;i<l;i++){
			if(data[i]<='9' && data[i]>='0')
				num[indexNum] = num[indexNum]*10 + (data[i]-'0');
			else{
				o[indexO++] = data[i];
				indexNum++;
			}
		}
		indexNum++;
		long long ansmin = f(num, indexNum, o, indexO);
		long long ansmax = g(num, indexNum, o, indexO);
		printf("The maximum and minimum are %lld and %lld.\n",ansmax, ansmin);
		// for(int i=0;i<indexNum;i++)
		// 	printf("%d ",num[i]);
		// printf("\n");
		// for(int i=0;i<indexO;i++)
		// 	printf("%c ", o[i]);
		// printf("\n\n");
	}
	return 0;
}
