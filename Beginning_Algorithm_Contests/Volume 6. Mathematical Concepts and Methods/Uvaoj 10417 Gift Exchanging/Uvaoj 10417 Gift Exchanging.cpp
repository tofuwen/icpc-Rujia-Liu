#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int n;
int box[10];
double p[15][10];
double a[10];
double aa[10];

bool next_Com(int num, int k, int *com)//0,1...num-1 choose k
{
	if(com[k-1]!=num-1)
	{
		com[k-1]++;
		return true;
	}
	int i;
	for(i=k-1;i>=0;i--)
		if(com[i]!=num-k+i)
			break;
	if(i==-1)
		return false;
	com[i]++;
	for(int j=i+1;j<k;j++)
		com[j] = com[i]+(j-i);
	return true;
}

void makeFirstCom(int num, int k, int *com)
{
	for(int i=0;i<k;i++)
		com[i] = i;
}

double f(int degree, vector<int> v, int *b)
{
	int num = v.size();
	if(degree==4)
	{
		double ans = 1.0;
		for(int i=0;i<num;i++)
			ans *= p[v[i]][degree];
		return ans;
	}
	if(b[degree]==0)
        return f(degree+1,v,b);
	int com[15];
	double ans = 0.0;
	int numberOfThisBox = b[degree];
	makeFirstCom(num, numberOfThisBox, com);
	vector<int> nv;
	do
	{
		double hold = 1;
		for(int i=0;i<numberOfThisBox;i++)
			hold *= p[v[com[i]]][degree];
		int cur = 0;
		nv.clear();
		for(int i=0;i<num;i++)
		{
			if(cur<numberOfThisBox&&com[cur]==i)
				cur++;
			else
				nv.push_back(v[i]);
		}
		ans += hold*f(degree+1,nv,b);
	}while(next_Com(num, numberOfThisBox, com));
	return ans;
}

double solve(int boxNumber)
{
	if(box[boxNumber]==0)
		return 0.0;
    if(fabs(p[0][boxNumber])<1e-10)
        return 0.0;
	int b[10];
	for(int i=0;i<5;i++)
		b[i] = box[i];
	b[boxNumber]--;
	vector<int> v;
	for(int i=1;i<n;i++)
		v.push_back(i);
	return p[0][boxNumber]*f(0,v,b);
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++)
	{
		scanf("%d",&n);
		for(int i=0;i<5;i++)
			scanf("%d",&box[i]);
		for(int i=0;i<n;i++)
			for(int j=0;j<5;j++)
				scanf("%lf",&p[i][j]);
      //  for(int i=0;i<n;i++){
		//	for(int j=0;j<5;j++)
		//		printf("%lf ",p[i][j]);
     //       printf("\n");
     //   }
     //for(int i=0;i<5;i++)
     //   printf("%d ",box[i]);
		double pro = 0;
		int ans = 0;
		for(int i=0;i<5;i++)
            a[i] = aa[i] = 0.0;
		for(int i=0;i<5;i++)
		{
			if(box[i])
			{
				a[i] = solve(i);
               // printf("%lf\n",h);
				//if(a[i]>pro+1e-10)
				//{
				//	pro = a[i];
				//	ans = i;
				//}
			}
		}
		double sum = 0.0;
		for(int i=0;i<5;i++)
            sum += a[i];
        for(int i=0;i<5;i++)
        {
            if(box[i])
                aa[i] = a[i]/sum/box[i];
        }
        for(int i=0;i<5;i++)
            if(aa[i]>pro+1e-10)
            {
                pro = aa[i];
                ans = i;
            }
		//printf("%d %.3lf\n",ans+1,pro/sum/box[ans]);
		printf("%d %.3lf\n",ans+1,pro);
	}
	return 0;
}
