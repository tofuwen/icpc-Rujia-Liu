#include <cstdio>
using namespace std;

const int maxn = 510;

int n, m;
int book[maxn];

bool isOk(long long guess){
	int num = 1;
	long long now = 0;
	for(int i=n-1;i>=0;i--){
		if(guess < book[i])
			return false; 
		now += book[i];
		if(i>0 && now+book[i-1] > guess){
			num++;
			now = 0;
		}
	}
	if(num <= m)
		return true;
	return false;
}

long long solve(long long minGuess, long long maxGuess){
	//printf("kao\n");
	//printf("%lld %lld\n", minGuess, maxGuess);
	if(minGuess == maxGuess)
		return minGuess;
	if(minGuess == maxGuess-1)
		return maxGuess;
	long long mid = (minGuess+maxGuess) / 2;
	if(isOk(mid))
		return solve(minGuess, mid);
	return solve(mid, maxGuess);
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++){
		scanf("%d%d",&n,&m);
		long long all = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&book[i]);
			all += book[i];
		}
		//printf("kao\n");
		// for(int i=0;i<n;i++)
		// 	printf("%d\n",book[i]);
		long long minGuess = 0, maxGuess = all;
		long long trueGuess = solve(minGuess, maxGuess);
		//printf("tg:%lld\n",trueGuess);
		int num = 0;
		int cut[maxn];
		long long now = 0;
		for(int i=n-1;i>=0;i--){
			now += book[i];
			if(i>0 && now+book[i-1] > trueGuess){
				cut[num++] = i;
				now = 0;
			}
		}
		// for(int i=0;i<num;i++)
		// 	printf("%d\n",cut[i]);
		int remain = 0;
		if(m > num+1)
			remain = m-num-1;
		// printf("m:%d num:%d\n",m, num);
		// printf("remain: %d\n",remain);
		int pointer = num-1;
		for(int i=0;i<n;i++){
			bool slash = false;
			if(pointer >=0 && cut[pointer] == i){
				printf(" /");
				slash = true;
				pointer--;
			}
			if(i>0 && remain>0 && !slash){
				printf(" /");
				remain--;
			}
			if(i == 0)
				printf("%d", book[i]);
			else
				printf(" %d", book[i]);
		}
		printf("\n");
	}
	return 0;
}