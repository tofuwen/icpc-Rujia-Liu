#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
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

// struct Line
// {
// 	Point p;
// 	Vector v;
// 	Line(Point p, Vector v):p(p),v(v){}
// 	Line(){}
// };

const int maxn = 310;
Point p[maxn];
Point intersection[maxn*maxn];
bool isDuplicate[maxn*maxn];
//Line l[maxn];

int main()
{
	//freopen("data.txt","r",stdin);
	int n;
	int kase = 0;
	while(scanf("%d",&n)&&n)
	{
		int numIn = 0;
		for(int i=0;i<n;i++){
			double a, b;
			scanf("%lf%lf",&a,&b);
			p[i] = Point(a,b);
			intersection[numIn++] = p[i];
		}
		// for(int i=0;i<n-1;i++){
		// 	l[i] = Line(p[i],p[i+1]-p[i]);
		// }
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n-1;j++)
				if(segmentProperIntersection(p[i], p[i+1], p[j], p[j+1])){
					intersection[numIn++] = GetLineIntersection(p[i], p[i+1]-p[i], p[j], p[j+1]-p[j]);
				}
		sort(intersection,intersection+numIn);
		memset(isDuplicate,0,sizeof(isDuplicate));
		int numDuplicate = 0;
		for(int i=1;i<numIn;i++){
			if(intersection[i]==intersection[i-1])
			{
				isDuplicate[i] = true;
				numDuplicate++;
			}
		}
		int V = numIn - numDuplicate;
		int E = n-1;
		for(int i=0;i<numIn;i++){
			if(!isDuplicate[i]){
				for(int j=0;j<n-1;j++)
					if(OnSegment(intersection[i],p[j],p[j+1]))
						E++;
			}
		}
		int F = 2+E-V;
		printf("Case %d: There are %d pieces.\n",++kase,F);
	}
	return 0;
}