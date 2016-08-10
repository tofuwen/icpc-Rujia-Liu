#include <cstdio>
#include <cmath>
#include <algorithm> //swap
#include <vector>
using namespace std;

const double PI = acos(-1);

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
	return dcmp(a.x - b.x) < 0 || (dcmp(a.x-b.x)==0 && dcmp(a.y - b.y) < 0);
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

//向量极角（-pi -- pi）
double angle(Vector v) {
  return atan2(v.y, v.x);
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

//计算凸包，输入点数组p，个数为n，输出点数组ch。函数返回凸包顶点数
//输入不能有重复点。函数执行完之后输入点的顺序被破坏
//如果希望在凸包的边上有输入点，把两个 <= 改为 <
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

// 返回点集直径 (旋转卡壳法 Rotating Calipers Algorithm) ch数组已是凸包(且不能有三点共线的) n: 点的个数
// 可以证明对踵点的个数不超过3N/2个 也就是说对踵点的个数是O(N)的
double diameter(Point* ch, int n) {
  if(n == 1) return 0;
  if(n == 2) return Length(ch[0] - ch[1]);
  ch[n] = ch[0]; // 免得取模
  double ans = 0;
  for(int u = 0, v = 1; u < n; u++) {
    // 一条直线贴住边p[u]-p[u+1]
    for(;;) {
      // 当Area(p[u], p[u+1], p[v+1]) <= Area(p[u], p[u+1], p[v])时停止旋转
      // 即Cross(p[u+1]-p[u], p[v+1]-p[u]) - Cross(p[u+1]-p[u], p[v]-p[u]) <= 0 (此时这个角度不能超过180度，所以不需要去绝对值)
      // 根据Cross(A,B) - Cross(A,C) = Cross(A,B-C)
      // 化简得Cross(p[u+1]-p[u], p[v+1]-p[v]) <= 0
      double diff = Cross(ch[u+1]-ch[u], ch[v+1]-ch[v]);
      if(dcmp(diff) <= 0) {
        ans = max(ans, Length(ch[u]-ch[v])); // u和v是对踵点
        if(dcmp(diff) == 0)
        	ans = max(ans, Length(ch[u]-ch[v+1])); // diff == 0时u和v+1也是对踵点
        break;
      }
      v = (v + 1) % n;
    }
  }
  return ans;
}

//poly: 多边形 n: 点的个数
//返回值：-2：在端点	-1：在边界	0：外部		1：内部
//点在凸多边形的判定：判断点是否在所有边的左边（各顶点已按逆时针排序）
int isPointInPolygon(Point p, Point* poly, int n){
	int wn = 0;
	for(int i=0;i<n;i++){
		if(p == poly[i])
			return -2; //在端点
		if(OnSegment(p, poly[i], poly[(i+1)%n])) // 在边界
			return -1;
		int k = dcmp(Cross(poly[(i+1)%n]-poly[i], p-poly[i]));
		int d1 = dcmp(poly[i].y - p.y);
		int d2 = dcmp(poly[(i+1)%n].y - p.y);
		if(k>0 && d1<=0 && d2>0)
			wn++;
		if(k<0 && d2<=0 && d1>0)
			wn--;
	}
	if(wn != 0)
		return 1; // 内部
	return 0; // 外部
}

struct Line{
	Point p;
	Vector v;
	Line(Point p, Vector v):p(p),v(v){}
	Point point(double t) {
    	return p + v*t;
  	}
  	Line move(double d) { //平移
    	return Line(p + Normal(v)*d, v);
  }
};

struct Circle{
	Point c;
	double r;
	Circle(Point c, double r):c(c),r(r){}
	Point point(double a){
		return Point(c.x + cos(a)*r, c.y + sin(a)*r);
	}
};

//返回交点个数 sol存放交点本身。函数没有清空sol，可存放多个顶点
//设交点为 P = A + t(B-A)，化简后得到et^2+ft+g = 0
int getLineCircleIntersection(Line L, Circle C, double& t1, double& t2, vector<Point>& sol){
	double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
	double e = a*a + c*c, f = 2*(a*b+c*d), g = b*b + d*d - C.r*C.r;
	double delta = f*f - 4*e*g;
	if(dcmp(delta) < 0)
		return 0;
	if(dcmp(delta) == 0){
		t1 = t2 = -f / (2*e);
		sol.push_back(L.point(t1));
		return 1;
	}
	t1 = (-f - sqrt(delta)) / (2*e);
	sol.push_back(L.point(t1));
	t2 = (-f + sqrt(delta)) / (2*e);
	sol.push_back(L.point(t2));
	return 2;
}

//返回交点个数。重合返回-1
int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol){
	double d = Length(C1.c-C2.c);
	if(dcmp(d) == 0){
		if(dcmp(C1.r-C2.r) == 0)
			return -1;
		return 0;
	}
	if(dcmp(C1.r+C2.r-d) < 0)
		return 0;
	if(dcmp(fabs(C1.r-C2.r) - d) > 0)
		return 0;
	double a = angle(C2.c-C1.c); //向量C1C2的极角
	double da = acos((C1.r*C1.r + d*d - C2.r*C2.r) / (2*C1.r*d)); //C1C2到C1P1的角
	Point p1 = C1.point(a-da), p2 = C1.point(a+da);
	sol.push_back(p1);
	if(p1 == p2)
		return 1;
	sol.push_back(p2);
	return 2;
}

// 过点p到圆C的切线。v[i]是第i条切线的向量（从0开始）。返回切线条数
int getTangents(Point p, Circle C, Vector* v){
	Vector u = C.c - p;
	double dist = Length(u);
	if(dist < C.r)
		return 0;
	else if(dcmp(dist-C.r)==0){
		v[0] = Rotate(u,PI/2);
		return 1;
	} else {
		double ang = asin(C.r / dist);
		v[0] = Rotate(u, -ang);
		v[1] = Rotate(u, +ang);
		return 2;
	}
}

//返回切线的条数，-1表示无穷条切线
//a[i]和b[i]分别是第i条切线在圆A和圆B上的切点。内切，外切时，这两个点相同
int getTangents(Circle A, Circle B, Point* a, Point* b){
	int cnt = 0;
	if(A.r < B.r){
		swap(A, B);
		swap(a, b);
	}
	double d2 = (A.c.x-B.c.x)*(A.c.x-B.c.x) + (A.c.y-B.c.y)*(A.c.y-B.c.y);
	double rdiff = A.r - B.r;
	double rsum = A.r + B.r;
	if(dcmp(d2 - rdiff*rdiff) < 0) // 内含
		return 0;
	double base = atan2(B.c.y-A.c.y, B.c.x-A.c.x);
	if(dcmp(d2)==0 && dcmp(A.r-B.r)==0)// 无限多条切线
		return -1;
	if(dcmp(d2-rdiff*rdiff) == 0){// 内切，一条切线
		a[cnt] = A.point(base);
		b[cnt] = B.point(base);
		cnt++;
		return 1;
	}
	double ang = acos((A.r-B.r)/sqrt(d2));// 两条外公切线
	a[cnt] = A.point(base + ang);
	b[cnt] = B.point(base + ang);
	cnt++;
	a[cnt] = A.point(base - ang);
	b[cnt] = B.point(base - ang);
	cnt++;
	if(dcmp(d2-rsum*rsum) == 0){
		a[cnt] = A.point(base);
		b[cnt] = B.point(PI + base);
		cnt++;
	}
	else if(dcmp(d2 - rsum*rsum) > 0){ // 两条内公切线
		double ang = acos((A.r+B.r) / sqrt(d2));
		a[cnt] = A.point(base+ang);
		b[cnt] = B.point(PI+base+ang);
		cnt++;
		a[cnt] = A.point(base-ang);
		b[cnt] = B.point(PI+base-ang);
		cnt++;
	}
	return cnt;
}



const int maxn = 100010;
int n;

Point p[4*maxn];
Point ch[4*maxn];

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++){
		scanf("%d",&n);
		int num = 0;
		for(int i=0;i<n;i++){
			double x,y,w;
			scanf("%lf%lf%lf",&x,&y,&w);
			p[num++] = Point(x,y);
			p[num++] = Point(x+w,y);
			p[num++] = Point(x,y+w);
			p[num++] = Point(x+w,y+w);
		}
		// 其实不应该有重复点的，但是我也没有unique，也过了···
		int numConvex = ConvexHull(p, num, ch);
		// double maxl = 0;
		// for(int i=0;i<numConvex;i++){
		// 	for(int j=i+1;j<numConvex;j++){
		// 		double l = Length(ch[i]-ch[j]);
		// 		maxl = max(l,maxl);
		// 	}
		// }
		// long long ans = (long long)(maxl*maxl+0.5);
		double ans = diameter(ch, numConvex);
		printf("%lld\n",(long long)(ans*ans+0.5));
	}
	return 0;
}