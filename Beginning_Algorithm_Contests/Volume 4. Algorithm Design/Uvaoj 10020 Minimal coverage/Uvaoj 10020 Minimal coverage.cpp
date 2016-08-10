#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct segment
{
	int l;
	int r;
	segment(int l=0, int r=0):l(l),r(r){}
	friend bool operator < (const segment& a, const segment& b)
	{
		if(a.l==b.l)
			return a.r<b.r;
		return a.l<b.l;
	}
};

segment s[maxn];
segment ts[maxn];
segment ans[maxn];
int hold[maxn];
int n,tn,nAns;
bool v[maxn];
int M;
bool ok;

bool isContain(segment a, segment b)
{
	if(a.l>=b.l&&a.r<=b.r)
		return true;
	return false;
}

bool solve(int x)
{
	int p = lower_bound(hold,hold+tn,x)-hold;
	//printf("P:%d\n",p);
	if(hold[p]!=x)
		p--;
	if(p==-1)
		return false;
	if(ts[p].r<=x)
		return false;
	ans[nAns++] = ts[p];
	int r = ts[p].r;
	if(r==M)
		return true;
	return solve(r);
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++)
	{
		int l,r;
		scanf("%d",&M);
		n = tn = nAns = 0;
		memset(v,0,sizeof(v));
		while(scanf("%d%d",&l,&r)==2&&(l||r))
		{
			if(r<=0)
				continue;
			else
			{
				l = max(0,l);
				r = min(M,r);
				//printf("l: %d r: %d",l,r);
				if(l>=r)
					continue;
				s[n++] = segment(l,r);
			}
		}
		//printf("n:%d\n",n);
		if(n)
		{
			sort(s,s+n);
			//for(int i=0;i<n;i++)
			//	printf("%d %d\n",s[i].l,s[i].r);
			segment pre = segment(0,0);
			for(int i=0;i<n;i++)
			{
				if((i==n-1&&!isContain(s[i],pre))||(s[i].l!=s[i+1].l&&!isContain(s[i],pre)))
				{
					v[i] = true;
					pre = s[i];
				}		
			}
			for(int i=0;i<n;i++)
				if(v[i])
					ts[tn++] = s[i];
			//for(int i=0;i<tn;i++)
			//	printf("%d %d\n",ts[i].l,ts[i].r);
			for(int i=0;i<tn;i++)
				hold[i] = ts[i].l;
			ok = solve(0);
		}
		else
			ok = false;
		//printf("lkao\n");
		if(cc)
			printf("\n");
		if(ok)
		{
			printf("%d\n",nAns);
			for(int i=0;i<nAns;i++)
				printf("%d %d\n",ans[i].l,ans[i].r);
		}
		else
			printf("%d\n", 0);
			
	}
	return 0;
}