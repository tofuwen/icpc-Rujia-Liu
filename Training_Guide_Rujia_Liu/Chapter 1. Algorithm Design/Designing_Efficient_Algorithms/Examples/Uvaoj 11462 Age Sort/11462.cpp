#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	// freopen("data.txt", "r", stdin);
	int n;
	while(scanf("%d", &n) == 1 && n) {
		int ages[110];
		memset(ages, 0, sizeof(ages));
		for (int i=0;i<n;i++) {
			int a;
			scanf("%d", &a);
			ages[a]++;
		}
		bool is_print = false;
		for(int i=1;i<=100;i++) {
			for(int j=0;j<ages[i];j++) {
				if (is_print)
					printf(" ");
				is_print = true;
				printf("%d", i);
			}
		}
		printf("\n");
	}
	return 0;
}