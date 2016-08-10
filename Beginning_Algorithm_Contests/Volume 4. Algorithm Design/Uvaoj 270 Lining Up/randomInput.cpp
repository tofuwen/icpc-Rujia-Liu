#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

struct point
{
	int x;
	int y;
	friend bool operator < (const point& a, const point& b)
	{
		if(a.y==b.y)
			return a.x<b.x;
		return a.y<b.y;
	}
};

const int n = 600;

set<point> s;

int main()
{
	freopen("datain.txt","w",stdout);
	srand(time(NULL));
	printf("1\n\n");
	for(int i=0;i<n;i++)
	{
		point p;
		p.x = rand()%17;
		p.y = rand()%28;
		s.insert(p);
	}
	for(set<point>::iterator iter = s.begin();iter!=s.end();iter++)
		printf("%d %d\n",(*iter).x,(*iter).y);
	return 0;
}