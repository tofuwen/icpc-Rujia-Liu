#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct fragment
{
	int l;
	char s[600];
	friend bool operator < (const fragment& a, const fragment& b)
	{
		return a.l<b.l;
	}
};

const int INF = 1<<30;

char s[600];
fragment f[200];
int n;
int maxl,minl;
int iindex[300];
int l;

void plus(char a[], char b[], char ans[])
{
	int la = strlen(a);
	int lb = strlen(b);
	for(int i=0;i<la;i++)
		ans[i] = a[i];
	for(int i=0;i<lb;i++)
		ans[i+la] = b[i];
	ans[la+lb] = '\0';
}

int ff(int i, bool vi[], char p[])
{
	int sl = l-f[i].l;
	int start = iindex[sl];
	for(int k=start;k<n;k++)
	{
		if(f[k].l!=sl)
			break;
		if(vi[k])
			continue;
		char hold[600];
		plus(f[i].s,f[k].s,hold);
		if(strcmp(hold,p)==0)
			return k;
		plus(f[k].s,f[i].s,hold);
		if(strcmp(hold,p)==0)
			return k;
	}
	return -1;
}

bool test(char p[], int known)
{
	bool vi[300];
	memset(vi,0,sizeof(vi));
	vi[0] = vi[known] = true;
	int counter = 2;
	while(counter<n)
	{
		for(int i=1;i<n;i++)
			if(!vi[i])
			{
				vi[i] = true;
				int h = ff(i,vi,p);
				if(h==-1)
					return false;
				vi[h] = true;
				counter += 2;
			}
	}
	return true;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	getchar();
	getchar();
	for(int cc=0;cc<T;cc++)
	{
		n = 0;
		minl = INF;
		maxl = 0;
		while(gets(s))
		{
			if(s[0]!='0'&&s[0]!='1')
				break;
			strcpy(f[n].s, s);
			//printf("%s\n",f[n].s);
			f[n].l = strlen(s);
			maxl = max(maxl,f[n].l);
			minl = min(minl,f[n].l);
			n++;
		}
		sort(f,f+n);
		//for(int i=0;i<n;i++)
		//	printf("testf%d:%s\n",i,f[i].s);
		memset(iindex,0,sizeof(iindex));
		for(int i=0;i<n;i++)
		{
			if(!iindex[f[i].l])
				iindex[f[i].l] = i;
		}
		l = minl+maxl;
		for(int i=iindex[l-f[0].l];i<n;i++)
		{
			char p[600];
			plus(f[0].s,f[i].s,p);
			//printf("testf0:%s\n",f[0].s);
			//printf("testfi:%s\n",f[i].s);
			bool ok = test(p,i);
			//printf("test:%s\n",p);
			if(ok)
			{
				if(cc)
					putchar('\n');
				printf("%s\n",p);
				break;
			}
			plus(f[i].s,f[0].s,p);
			ok = test(p,i);
			//printf("test:%s\n",p);
			if(ok)
			{
				if(cc)
					putchar('\n');
				printf("%s\n",p);
				break;
			}
		}
	}
	return 0;
}