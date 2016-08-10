#include <cstdio>
#include <set>
using namespace std;

int n;

struct exchange
{
	int x;
	int y;
	friend bool operator < (const exchange& a, const exchange& b){
		if(a.x!=b.x)
			return a.x<b.x;
		return a.y<b.y;
	}
};

exchange f(exchange a){
	exchange h;
	h.x = a.y;
	h.y = a.x;
	return h;
}

multiset<exchange> s;

int main()
{
	//freopen("data.txt","r",stdin);
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=0;i<n;i++)
		{
			exchange a;
			scanf("%d%d",&a.x,&a.y);
			multiset<exchange>::iterator iter = s.find(a);
			if(iter==s.end())
				s.insert(f(a));
			else
				s.erase(iter);
			//just erase 1 element
			//if s.erase(a): erase all elements that equal to a
		}
		if(!s.size())
			printf("YES\n");
		else
			printf("NO\n");
		s.clear();
	}
	return 0;
}