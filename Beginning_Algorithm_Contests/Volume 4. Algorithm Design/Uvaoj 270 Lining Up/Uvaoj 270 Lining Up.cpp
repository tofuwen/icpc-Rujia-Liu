/*
//This algorithm is completely wrong!
//What's worse, it's runtime error!

#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

struct line
{
	int x;
	int y;
	friend bool operator < (const line& a, const line& b)
	{
		if(a.y==b.y)
			return a.x<b.x;
		return a.y<b.y;
	}
};

const int maxn = 710;

line l[maxn];
multiset<line> ms;

int absolute(int a)
{
	if(a<0)
		return -a;
	return a;
}

int gcd(int a, int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
	//freopen("data.txt","r",stdin);
	int a,b;
	int n = 0;
	int m = 0;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		bool negative = (double)a*b+1e-7<0;
		int oa = a, ob = b;
		a = absolute(a);
		b = absolute(b);
		int GCD = gcd(a,b);
		//caution: 0!!
		if(a&&b)
		{
			if(!negative)
				l[n].x = a/GCD;
			else
				l[n].x = -a/GCD;
			l[n].y = b/GCD;
		}
		else
		{
			if(a==0)
			{
				l[n].x = 0;
				if(ob>=0)
					l[n].y = ob>0?1:0;
				else
					l[n].y = -1;
			}
			else
			{
				l[n].x = oa>0?1:-1;
				l[n].y = 0;
			}
		}
		ms.insert(l[n]);
		n++;
	}
	for(multiset<line>::iterator iter = ms.begin();iter!=ms.end();iter++)
	{
		//printf("%d %d\n",(*iter).x,(*iter).y);
		int k = ms.count(*iter);
		m = max(m,k);
	}
	printf("%d\n",m);
	return 0;
}
*/


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct point
{
	int x;
	int y;
};

struct line
{
	int sx;
	int sy;
	int vx;
	int vy;
};

const int maxn = 710;
point p[maxn];
int n;
int m;

/*

int gcd(int a, int b)
{
	return b==0?a:gcd(b,a%b);
}

*/

line makeLine(point a, point b)
{
	line l;
	l.sx = a.x;
	l.sy = a.y;
	int dx = a.x-b.x;
	int dy = a.y-b.y;
	// if(!dx||!dy)
	// {
	// 	if(!dx)
	// 	{
	// 		l.vx = 0;
	// 		l.vy = 1;
	// 	}
	// 	else
	// 	{
	// 		l.vx = 1;
	// 		l.vy = 0;
	// 	}
	// 	return l;
	// }
	// int GCD = gcd(abs(dx),abs(dy));
	// l.vx = dx/GCD;
	// l.vy = dy/GCD;
	l.vx = dx;
	l.vy = dy;
	return l;
}

bool inLine(line l, point p)
{
	int x = p.x-l.sx;
	int y = p.y-l.sy;
	if(((long long)x)*l.vy==((long long)y)*l.vx)
		return true;
	return false;
}

void check(int index)
{
	bool v[maxn];
	memset(v,0,sizeof(v));
	for(int i=index+1;i<n;i++)
	{
		if(v[i])
			continue;
		int ans = 2;
		line l = makeLine(p[index],p[i]);
		for(int j=i+1;j<n;j++)
		{
			if(inLine(l,p[j]))
			{
				ans++;
				v[j] = true;
			}
		}
		m = max(m,ans);
	}
}

int main()
{
	//freopen("data.txt","r",stdin);
	//freopen("dataout.txt","w",stdout);
	int T;
	scanf("%d",&T);
	getchar();
	getchar();
	char s[100];
	for(int cc=0;cc<T;cc++)
	{
		int a,b;
		n = m = 0;
		while(gets(s))
		{
			//if(s[0]<'0'||s[0]>'9')
			if(s[0]=='\0')
				break;
			sscanf(s, "%d%d",&a,&b);
			p[n].x = a;
			p[n].y = b;
			n++;
		}
		//for(int i=0;i<n;i++)
		//	printf("%d %d\n",p[i].x,p[i].y);
		for(int i=0;i<n;i++)
		{
			if(n-i<=m)
				break;
			check(i);
		}
		if(n==1)
			m = 1;
		if(n==2)
			m = 2;
		if(cc)
			putchar('\n');
		printf("%d\n",m);
	}
	return 0;
}