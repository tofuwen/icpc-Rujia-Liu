#include <cstdio>
#include <algorithm>
using namespace std;

bool at(long long want, int index){
	return want & (((long long)1) << index);
}

long long find_range_low(long long l, long long u, int index){
	long long mod = ((long long)1) << (index+1);
	long long r = l % mod;
	return l - r + mod - 1;
}

long long find_range_high(long long l, long long u, int index){
	long long mod = ((long long)1) << index;
	long long r = u % mod;
	return u - r;
}

long long find_ans(long long n, long long l, long long u, int index){
	if(index == -1)
		return l;
	if(at(n, index) || at(l, index))
		return find_ans(n, l, u, index-1);
	long long should = ((long long)1) << index;
	long long mod = ((long long)1) << (index+1);
	long long next = should - (l % mod) + l;
	return find_ans(n, next, u, index-1); 
}

long long solve(long long n, long long l, long long u, int index){
	if(index == -1)
		return l;
	if(at(n, index))
		return solve(n, l, u, index-1);
	long long num = u-l+1;
	long long length = ((long long)1) << index;
	if(num <= length){
		if(at(l, index) == at(u, index))
			return solve(n, l, u, index-1);
		else{
			if(at(l, index) && !at(u, index)){
				long long next = find_range_low(l, u, index);
				return solve(n, l, next, index-1);
			}
			else{
				long long next = find_range_high(l, u, index);
				return solve(n, next, u, index-1);
			}
		}
	}
	else{
		if(num < 2*length){
			if(at(l, index) && !at(u, index)){
				long long next = find_range_low(l, u, index);
				return solve(n, l, next, index-1);
			}
			if(!at(l, index) && at(u, index)){
				long long next = find_range_high(l, u, index);
				return solve(n, next, u, index-1);
			}
			if(!at(l, index) && !at(u, index)){
				return find_ans(n, l, u, index);
			}
			long long next1 = find_range_low(l, u, index);
			long long next2 = find_range_high(l, u, index);
			long long ans1 = solve(n, l, next1, index-1);
			long long ans2 = solve(n, next2, u, index-1);
			long long b1 = n | ans1;
			long long b2 = n | ans2;
			if(b2 > b1)
				return ans2;
			return ans1;
		}
		else{
			return find_ans(n, l, u, index);
		}
	}
}

int main()
{
	//freopen("data.txt", "r", stdin);
	long long n, l, u;
	while(scanf("%lld%lld%lld", &n, &l, &u) != EOF){
		printf("%lld\n", solve(n, l, u, 31));
	}
	return 0;
}