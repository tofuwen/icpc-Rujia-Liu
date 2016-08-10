#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point{
	double x, y;
	Point(double x=0, double y=0):x(x), y(y){}
};

typedef Point Vector;

//Vector + Vector = Vector / Point + Vector = Point
Vector operator + (Vector A, Vector B){
	return Vector(A.x+B.x, A.y+B.y);
}

//Point - Point = Vector
Vector operator - (Point A, Point B){
	return Vector(A.x-B.x, A.y-B.y);
}

Vector operator * (Vector A, double p){
	return Vector(A.x*p, A.y*p);
}

Vector operator / (Vector A, double p){
	return Vector(A.x/p, A.y/p);
}

const double eps = 1e-10;
int dcmp(double x){
	if(fabs(x) < eps)
		return 0;
	return x<0?-1:1;
}

bool operator < (const Point& a, const Point& b){
	return a.x < b.x || (dcmp(a.x-b.x)==0 && a.y < b.y);
}

bool operator == (const Point& a, const Point &b){
	return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0;
}

//夹角θ一般指A到B逆时针旋转的角度 
double Dot(Vector A, Vector B){
	return A.x*B.x + A.y*B.y;
}

double Length(Vector A){
	return sqrt(Dot(A,A));
}

//两向量夹角，0到pi
double Angle(Vector A, Vector B){
	return acos(Dot(A,B)/Length(A)/Length(B));
}

double Cross(Vector A, Vector B){
	return A.x*B.y - A.y*B.x;
}

//rad 为向量A逆时针旋转的角度（弧度）
Vector Rotate(Vector A, double rad){
	return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}

//计算向量A的单位法线（左转90度） 保证A非零向量
Vector Normal(Vector A){
	double L = Length(A);
	return Vector(-A.y/L, A.x/L);
}

//调用前确保两条直线P+tv和Q+tw有唯一交点。当且仅当Cross(v,w)非0
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w){
	Vector u = P-Q;
	double t = Cross(w,u)/Cross(v,w);
	return P+v*t;
}

//点P到直线AB的距离
double DistanceToLine(Point P, Point A, Point B){
	Vector v1 = B-A, v2 = P-A;
	return fabs(Cross(v1,v2))/Length(v1);//不取fabs，则得到有向距离
}

//点P到线段AB的距离
double DistanceToSegment(Point P, Point A, Point B){
	if(A == B)
		return Length(P-A);
	Vector v1 = B-A, v2 = P-A, v3 = P-B;
	if(dcmp(Dot(v1,v2))<0)
		return Length(v2);
	if(dcmp(Dot(v1,v3))>0)
		return Length(v3);
	return fabs(Cross(v1,v2))/Length(v1);//不取fabs，则得到有向距离
}

double DistanceToSegmentMax(Point P, Point A, Point B){
	if(A == B)
		return Length(P-A);
	Vector v1 = B-A, v2 = P-A, v3 = P-B;
	return max(Length(v2),Length(v3));
}


Point GetLineProjection(Point P, Point A, Point B){
	Vector v = B-A;
	return A+v*(Dot(v,P-A) / Dot(v,v));
}

//判断线段a1a2与线段b1b2是否规范相交（只有一个公共点，且不在端点）
//若允许端点处相交：c1 = c2 = 0: 共线，可能重叠 否则某个端点在另外一条线段上
bool segmentProperIntersection(Point a1, Point a2, Point b1, Point b2){
	double c1 = Cross(a2-a1,b1-a1);
	double c2 = Cross(a2-a1,b2-a1);
	double c3 = Cross(b2-b1,a1-b1);
	double c4 = Cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}

//判断点P是否在线段a1a2上（不包括端点）
bool OnSegment(Point p, Point a1, Point a2){
	return dcmp(Cross(a1-p,a2-p))==0 && dcmp(Dot(a1-p,a2-p))<0;
}

//计算多边形的有向面积（凸多边形以及非凸多边形）
double PolygonArea(Point* p, int n){
	double area = 0;
	for(int i=1;i<n-1;i++)
		area += Cross(p[i]-p[0],p[i+1]-p[0]);
	return area/2;
}

//计算凸包，输入点数组p，个数为n，输出点数组ch。函数返回凸包顶点数
//输入不能有重复点。函数执行完之后输入点的顺序被破坏
//如果不希望在凸包的边上有输入点，把两个 <= 改为 <
int ConvexHull(Point* p, int n, Point* ch){
	sort(p,p+n);
	int m = 0;
	for(int i=0;i<n;i++){
		while(m>1 && dcmp(Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) <= 0)
			m--;
		ch[m++] = p[i];
	}
	int k = m;
	for(int i=n-2;i>=0;i--){
		while(m>k && dcmp(Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) <= 0)
			m--;
		ch[m++] = p[i];
	}
	if(n>1)
		m--;
	return m;
}

struct state{
	int id;
	double t;
	state(int id, double t):id(id),t(t){}
};

const int maxn = 70;

Point pa[maxn];
Point pb[maxn];
double sa[maxn], sb[maxn];
double ta[maxn], tb[maxn];
double va, vb;
double maximum, minimum;
int A, B;

Point positionA(state a){
	double t = a.t - ta[a.id-1];
	double ratio = t/(ta[a.id]-ta[a.id-1]);
	Point start = pa[a.id-1];
	Point finish = pa[a.id];
	return start*(1-ratio)+finish*ratio;
}

Point positionB(state b){
	double t = b.t - tb[b.id-1];
	double ratio = t/(tb[b.id]-tb[b.id-1]);
	Point start = pb[b.id-1];
	Point finish = pb[b.id];
	return start*(1-ratio)+finish*ratio;
}

void solve(state a, state b){
	if(a.id == A || b.id == B)
		return;
	double timeA = ta[a.id] - a.t;
	double timeB = tb[b.id] - b.t;
	if(dcmp(timeA-timeB)<0){
		Point nowA = positionA(a);
		Point nowB = positionB(b);
		Vector vA = (pa[a.id]-pa[a.id-1])/(ta[a.id]-ta[a.id-1]);
		Vector vB = (pb[b.id]-pb[b.id-1])/(tb[b.id]-tb[b.id-1]);
		Vector v = (vB - vA)*timeA;
		double d = DistanceToSegment(nowA, nowB, nowB+v);
		double D = DistanceToSegmentMax(nowA, nowB, nowB+v);
		maximum = max(maximum, D);
		minimum = min(minimum, d);
		state nextA = state(a.id+1, ta[a.id]);
		state nextB = state(b.id, b.t + timeA);
		solve(nextA, nextB);
	}else{
		if(dcmp(timeA-timeB)>0){
			Point nowA = positionA(a);
			Point nowB = positionB(b);
			Vector vA = (pa[a.id]-pa[a.id-1])/(ta[a.id]-ta[a.id-1]);
			Vector vB = (pb[b.id]-pb[b.id-1])/(tb[b.id]-tb[b.id-1]);
			Vector v = (vB - vA)*timeB;
			double d = DistanceToSegment(nowA, nowB, nowB+v);
			double D = DistanceToSegmentMax(nowA, nowB, nowB+v);
			maximum = max(maximum, D);
			minimum = min(minimum, d);
			state nextA = state(a.id, a.t+timeB);
			state nextB = state(b.id+1, tb[b.id]);
			solve(nextA, nextB);
		}
		else{
			Point nowA = positionA(a);
			Point nowB = positionB(b);
			Vector vA = (pa[a.id]-pa[a.id-1])/(ta[a.id]-ta[a.id-1]);
			Vector vB = (pb[b.id]-pb[b.id-1])/(tb[b.id]-tb[b.id-1]);
			Vector v = (vB - vA)*timeB;
			double d = DistanceToSegment(nowA, nowB, nowB+v);
			double D = DistanceToSegmentMax(nowA, nowB, nowB+v);
			maximum = max(maximum, D);
			minimum = min(minimum, d);
			state nextA = state(a.id+1, ta[a.id]);
			state nextB = state(b.id+1, tb[b.id]);
			solve(nextA, nextB);
		}
	}
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=1;cc<=T;cc++){
		scanf("%d%d",&A,&B);
		for(int i=0;i<A;i++){
			double a, b;
			scanf("%lf%lf",&a,&b);
			pa[i] = Point(a,b);
		}
		for(int i=0;i<B;i++){
			double a, b;
			scanf("%lf%lf",&a,&b);
			pb[i] = Point(a,b);
		}
		sa[0] = sb[0] = 0.0;
		for(int i=1;i<A;i++)
			sa[i] = sa[i-1] + Length(pa[i]-pa[i-1]);
		for(int i=1;i<B;i++)
			sb[i] = sb[i-1] + Length(pb[i]-pb[i-1]);
		va = 1.0;
		vb = va*sb[B-1]/sa[A-1];
		for(int i=0;i<A;i++)
			ta[i] = sa[i]/va;
		for(int i=0;i<B;i++)
			tb[i] = sb[i]/vb; 
		maximum = 0.0;
		minimum = 1e100;
		state stateA = state(1,0.0); 
		state stateB = state(1,0.0);
		solve(stateA, stateB);
		printf("Case %d: %.0f\n",cc,maximum-minimum);
	}
	return 0;
}