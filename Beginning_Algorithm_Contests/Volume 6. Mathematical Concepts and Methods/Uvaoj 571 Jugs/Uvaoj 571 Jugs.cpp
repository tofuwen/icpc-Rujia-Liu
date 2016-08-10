#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

const int maxn = 1010;

bool v[maxn][maxn];
int n;
int ca,cb;
map<int, string> m;

void pre()
{
	m[0] = "fill A";
	m[1] = "fill B";
	m[2] = "empty A";
	m[3] = "empty B";
	m[4] = "pour A B";
	m[5] = "pour B A";
	m[6] = "success";
}

struct jug
{
	int a;
	int b;
	int id;
	int preId;
	int o;
	jug(int a, int b, int id, int preId, int o):a(a),b(b),id(id),preId(preId),o(o){}
// 	fill A: 0
//  fill B: 1
//  empty A: 2
//  empty B: 3
//  pour A B: 4
//  pour B A: 5
//  success
};

queue<jug> q;
vector<jug> vec;

void output(jug j)
{
	string s = "6";
	while(j.preId!=-1)
	{
		//cout<<j.o<<endl;
		s += j.o+'0';
		j = vec[j.preId];
	}
	int l = s.length();
	//cout<<s<<endl;
	for(int i=l-1;i>=0;i--)
	{
		string h = m[(s[i]-'0')];
		cout<<h<<endl;
	}
		
}

bool isExist(jug j)
{
	if(v[j.a][j.b])
		return true;
	return false;
}

int main()
{
	//freopen("data.txt","r",stdin);
	pre();
	while(scanf("%d%d%d",&ca,&cb,&n)!=EOF)
	{
		while(!q.empty())
			q.pop();
		vec.clear();
		memset(v,0,sizeof(v));
		jug start = jug(0,0,0,-1,-1);
		vec.push_back(start);
		q.push(start);
		v[0][0] = true;
		while(!q.empty())
		{
			jug now = q.front();
			q.pop();
			if(now.b==n)
			{
				output(now);
				break;
			}
			jug h1 = jug(ca,now.b,vec.size(),now.id,0);
			if(!isExist(h1))
			{
				vec.push_back(h1);
				q.push(h1);
				v[h1.a][h1.b] = true;
			}
			jug h2 = jug(now.a,cb,vec.size(),now.id,1);
			if(!isExist(h2))
			{
				vec.push_back(h2);
				q.push(h2);
				v[h2.a][h2.b] = true;
			}
			jug h3 = jug(0,now.b,vec.size(),now.id,2);
			if(!isExist(h3))
			{
				vec.push_back(h3);
				q.push(h3);
				v[h3.a][h3.b] = true;
			}
			jug h4 = jug(now.a,0,vec.size(),now.id,3);
			if(!isExist(h4))
			{
				vec.push_back(h4);
				q.push(h4);
				v[h4.a][h4.b] = true;
			}
			if(now.a+now.b>cb)
			{
				jug h5 = jug(now.a+now.b-cb,cb,vec.size(),now.id,4);
				if(!isExist(h5))
				{
					vec.push_back(h5);
					q.push(h5);
					v[h5.a][h5.b] = true;
				}
			}
			else
			{
				jug h5 = jug(0,now.a+now.b,vec.size(),now.id,4);
				if(!isExist(h5))
				{
					vec.push_back(h5);
					q.push(h5);
					v[h5.a][h5.b] = true;
				}
			}
			if(now.a+now.b>ca)
			{
				jug h6 = jug(ca,now.a+now.b-ca,vec.size(),now.id,5);
				if(!isExist(h6))
				{
					vec.push_back(h6);
					q.push(h6);
					v[h6.a][h6.b] = true;
				}
			}
			else
			{
				jug h6 = jug(now.a+now.b,0,vec.size(),now.id,5);
				if(!isExist(h6))
				{
					vec.push_back(h6);
					q.push(h6);
					v[h6.a][h6.b] = true;
				}
			}		
		}
	}
	return 0;
}