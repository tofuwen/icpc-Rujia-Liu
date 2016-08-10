/*
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;

const int maxn = 1000010;

ULL data[maxn];
int n;

struct coin{
	int index;
	ULL cap;
	coin(int index, ULL cap):index(index),cap(cap){}
	coin(){}
};

coin Plus[maxn];
coin Minus[maxn];

int difference(int index1, int index2){
	int big = max(index1, index2);
	int small = min(index1, index2);
	return min(big-small, small+n-big);
}

int main()
{
	freopen("data.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		ULL sum =0;
		for(int i=0;i<n;i++){
			scanf("%llu",&data[i]);
			sum += data[i];
		}
		//printf("kao\n");
		//cout<<sum<<endl;
		ULL ave = sum / n;
		//cout<<ave<<endl;
		int numPlus = 0;
		int numMinus = 0;
		//printf("kao\n");
		for(int i=0;i<n;i++)
			if(data[i] > ave)
				Plus[numPlus++] = coin(i,data[i]-ave);
			else if(data[i] < ave)
					Minus[numMinus++] = coin(i,ave-data[i]);
		if(numPlus == 0){
			printf("0\n");
			continue;
		}
		int pointerSmallMinus = 0, pointerBigMinus = numMinus - 1;
		ULL ans = 0;
		int pointer = 0;
		while(pointer < numPlus){
           // printf("kao\n");
			ULL& num = Plus[pointer].cap;
			int nowIndex = Plus[pointer].index;
			int d1 = difference(nowIndex, Minus[pointerSmallMinus].index);
			int d2 = difference(nowIndex, Minus[pointerBigMinus].index);
			if(d1 < d2){
				ULL& toDeduct = Minus[pointerSmallMinus].cap;
				if(num < toDeduct){
					ans += num*d1;
					toDeduct -= num;
					pointer++;
				}
				else if(num == toDeduct){
					ans += num*d1;
					pointer++;
					pointerSmallMinus++;
				}
				else{
					ans += toDeduct*d1;
					num -= toDeduct;
					pointerSmallMinus++;
				}
			}
			else{
				ULL& toDeduct = Minus[pointerBigMinus].cap;
				if(num < toDeduct){
					ans += num*d2;
					toDeduct -= num;
					pointer++;
				}
				else if(num == toDeduct){
					ans += num*d2;
					pointer++;
					pointerBigMinus--;
				}
				else{
					ans += toDeduct*d2;
					num -= toDeduct;
					pointerBigMinus--;
				}
			}
		}
		printf("%llu\n",ans);
	}
	return 0;
}
*/

/*
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

typedef unsigned long long ULL;

const int maxn = 1000010;

ULL data[maxn];
int n;

struct coin{
	int index;
	ULL cap;
	coin(int index, ULL cap):index(index),cap(cap){}
	coin(){}
	friend bool operator < (const coin& a, const coin& b){
		return a.index > b.index;
	}
};

coin Plus[maxn];
coin Minus[maxn];

set<coin> m;

int difference(int index1, int index2){
	int big = max(index1, index2);
	int small = min(index1, index2);
	return min(big-small, small+n-big);
}

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		ULL sum =0;
		for(int i=0;i<n;i++){
			scanf("%llu",&data[i]);
			sum += data[i];
		}
		//printf("kao\n");
		//cout<<sum<<endl;
		ULL ave = sum / n;
		//cout<<ave<<endl;
		int numPlus = 0;
		int numMinus = 0;
		//printf("kao\n");
		for(int i=0;i<n;i++)
			if(data[i] > ave)
				Plus[numPlus++] = coin(i,data[i]-ave);
			else if(data[i] < ave)
					Minus[numMinus++] = coin(i,ave-data[i]);
		if(numPlus == 0){
			printf("0\n");
			continue;
		}
		m.clear();
		//if(numPlus < numMinus){
		for(int i=0;i<numPlus;i++)
			m.insert(Plus[i]);
		//}
		ULL ans = 0;
		int pointer = 0;
		while(pointer < numMinus){
			coin& now = Minus[pointer];
			int nowIndex = now.index;
			set<coin>::iterator iterSmall = lower_bound(m.begin(), m.end(), now);
			set<coin>::iterator iterBig = iterSmall;
			if(iterBig == m.end())
				iterBig = m.begin();
			if(iterSmall != m.begin())
				iterSmall--;
			else{
				iterSmall = m.end();
				iterSmall--;
			}
			ULL& num = now.cap;
			int d1 = difference(nowIndex, (*iterSmall).index);
			int d2 = difference(nowIndex, (*iterBig).index);
			if(d1 < d2){
				ULL toDeduct = (*iterSmall).cap;
				if(num < toDeduct){
					ans += num*d1;
					toDeduct -= num;
					pointer++;
					coin newOne = coin((*iterSmall).index,toDeduct);
					m.erase(iterSmall);
					m.insert(newOne);
				}
				else if(num == toDeduct){
					ans += num*d1;
					pointer++;
					m.erase(iterSmall);
				}
				else{
					ans += toDeduct*d1;
					num -= toDeduct;
					m.erase(iterSmall);
				}
			}
			else{
				ULL toDeduct = (*iterBig).cap;
				if(num < toDeduct){
					ans += num*d2;
					toDeduct -= num;
					pointer++;
					coin newOne = coin((*iterBig).index,toDeduct);
					m.erase(iterSmall);
					m.insert(newOne);
				}
				else if(num == toDeduct){
					ans += num*d2;
					pointer++;
					m.erase(iterBig);
				}
				else{
					ans += toDeduct*d2;
					num -= toDeduct;
					m.erase(iterBig);
				}
			}
		}

		// int pointerSmallMinus = 0, pointerBigMinus = numMinus - 1;
		// ULL ans = 0;
		// int pointer = 0;
		// while(pointer < numPlus){
  //          // printf("kao\n");
		// 	ULL& num = Plus[pointer].cap;
		// 	int nowIndex = Plus[pointer].index;
		// 	int d1 = difference(nowIndex, Minus[pointerSmallMinus].index);
		// 	int d2 = difference(nowIndex, Minus[pointerBigMinus].index);
		// 	if(d1 < d2){
		// 		ULL& toDeduct = Minus[pointerSmallMinus].cap;
		// 		if(num < toDeduct){
		// 			ans += num*d1;
		// 			toDeduct -= num;
		// 			pointer++;
		// 		}
		// 		else if(num == toDeduct){
		// 			ans += num*d1;
		// 			pointer++;
		// 			pointerSmallMinus++;
		// 		}
		// 		else{
		// 			ans += toDeduct*d1;
		// 			num -= toDeduct;
		// 			pointerSmallMinus++;
		// 		}
		// 	}
		// 	else{
		// 		ULL& toDeduct = Minus[pointerBigMinus].cap;
		// 		if(num < toDeduct){
		// 			ans += num*d2;
		// 			toDeduct -= num;
		// 			pointer++;
		// 		}
		// 		else if(num == toDeduct){
		// 			ans += num*d2;
		// 			pointer++;
		// 			pointerBigMinus--;
		// 		}
		// 		else{
		// 			ans += toDeduct*d2;
		// 			num -= toDeduct;
		// 			pointerBigMinus--;
		// 		}
		// 	}
		// }
		 printf("%llu\n",ans);
	}
	return 0;
}
*/


#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 1000010;

long long data[maxn];
long long c[maxn];

int main()
{
	//freopen("data.txt","r",stdin);
	int n;
	while(scanf("%d",&n) != EOF){
		long long sum = 0;
		for(int i=0;i<n;i++){
			scanf("%lld",&data[i]);
			sum += data[i];
		}
		long long ave = sum / n;
		c[0] = 0;
		for(int i=1;i<n;i++)
			c[i] = c[i-1]+data[i]-ave;
		sort(c,c+n);
		long long ans = c[n/2];
		sum = 0;
		for(int i=0;i<n;i++)
			sum += abs(ans-c[i]);
		printf("%lld\n",sum);
	}
	return 0;
}