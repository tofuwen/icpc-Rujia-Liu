#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

const int T = 5;
const int maxl = 1100;
const int maxn = 10;
const int maxt = 10;

set<int> exist;

int main()
{
	freopen("input.txt","w",stdout);
	srand(time(NULL));
	printf("%d\n",T);
	int l, t, n;
	for(int cc=0;cc<T;cc++){
		l = (int)((double)rand()/RAND_MAX*maxl);
		t = (int)((double)rand()/RAND_MAX*maxt);
		n = (int)((double)rand()/RAND_MAX*maxn);
		printf("%d %d %d\n", l, t, n);
		exist.clear();
		for(int i=0;i<n;i++){
			char c[2] = {'R', 'L'};
			int dir = rand()%2;
			int num = (int)((double)rand()/RAND_MAX*l);
			while(exist.find(num) != exist.end())
				num = (int)((double)rand()/RAND_MAX*l);
			exist.insert(num);
			printf("%d %c\n",num, c[dir]);
		}
	}
	return 0;
}