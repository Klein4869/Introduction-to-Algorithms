#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const double eps = 1e-7, PI = acos(-1.0);

int sgn(double x) {
	if(fabs(x) < eps) return 0;
	return x > 0 ? 1 : -1;
}

struct Point {
	double x, y;
	Point() {}
	Point(const double &a, const double &b) {
		x = a, y = b;
	}
	bool operator <(const Point &a)const {
		return x != a.x ? x < a.x : y < a.y;
	}
	bool operator ==(const Point &a)const {
		//return sgn(x - a.x) == 0 && sgn(y - a.y) == 0;
		return x == a.x && y == a.y;
	}
	inline void print()const {
		printf("Point: %.6lf, %.6lf\n", x, y);
	}
	inline void scan() {
		scanf("%lf%lf", &x, &y);
	}
	void rotate(double Angle) {
		double X = x, Y = y, C = cos(Angle), S = sin(Angle);
		x = C * X - S * Y;
		y = S * X + C * Y;
	}
};
typedef Point Vector;

Point operator +(const Point &a, const Point &b) {
	return Point(a.x + b.x, a.y + b.y);
}
Point operator -(const Point &a, const Point &b) {
	return Point(a.x - b.x, a.y - b.y);
}
Point operator *(const Point &a, double k) {
	return Point(a.x * k, a.y * k);
}
Point operator /(const Point &a, double k) {
	return k ? Point(a.x / k, a.y / k) : a;
}

double cross(const Vector &a, const Vector &b) {
	return a.x * b.y - a.y * b.x;
}
double cross(const Point &a, const Point &b, const Point &c) {
	return cross(b - a, c - b);
}

double dot(const Point &a, const Point &b) {
	return a.x * b.x + a.y * b.y;
}

double direct(const Point &a, const Point &b, const Point &c) {
	return cross(b - a, c - a);// + Left - Right
}
/*
int quad(const Point &a) {
	if(a.x == 0 && 0 == a.y) return 0;
	if(a.x > 0 && a.y >= 0) return 1;
	if(a.y > 0 && a.x <= 0) return 2;
	if(a.x < 0 && a.y <= 0) return 3;
	return 4; //if(a.y < 0 && a.x >= 0) 
}*/

inline double sqr(const double &x) {
	return x * x;
}
double abs(const Point &a) {//length ^ 2
	return sqr(a.x) + sqr(a.y);
}
double dis(const Point &a) {//距离
	return sqrt(sqr(a.x) + sqr(a.y));
}
/*
bool cmpAng(const Point &a, const Point &b) {//Angle sort, if same cmp Length
	int A = quad(a), B = quad(b);
	if(A != B) return A < B;
	double t = cross(a, b);
	return t != 0 ? t > 0 : dis(a) < dis(b);
}*/

int Hull(Point *a, Point *s, int n) {//Anti-Clockwise 求凸包
	sort(a, a + n);
	int tot = 1;
	s[0] = a[0];
	for(int i = 1; i < n; ++i) {//Lower
		while(tot > 1 && sgn(cross(s[tot - 2], s[tot - 1], a[i])) < 0) --tot;
		s[tot++] = a[i];
	}
	for(int i = n - 2; i >= 0; --i) {//Upper
		while(tot > 1 && sgn(cross(s[tot - 2], s[tot - 1], a[i])) < 0) --tot;
		s[tot++] = a[i];
	}
	//puts("Hull");for(int i = 0; i < tot; ++i) s[i].print(); puts("");
	return tot == 1 ? tot : tot - 1;
}

int Onseg(const Point &p, const Point &a, const Point &b) {//判断点共线
	Vector X = a - p, Y = b - p;
	return !sgn(cross(X, Y)) && sgn(dot(X, Y)) < 0;
}

int InPoly(const Point &p, Point *s, int n) {//Border -1. 判断是否在凸包内
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		Point a = s[i], b = s[(i + 1) % n];
		//a.print(); b.print(); p.print(); puts("a time");
		if(a == p || b == p || Onseg(p, a, b)) return -1;
		int k = sgn(cross(b - a, p - a)),
			u = sgn(a.y - p.y),
			v = sgn(b.y - p.y);
		if(k > 0 && u <= 0 && v > 0) ++cnt;
		if(k < 0 && u > 0 && v <= 0) --cnt;
	}
	return cnt != 0;
}

bool SegIntersect(const Point &a, const Point &b, const Point &c, const Point &d) {//判断线段相交
	double t1 = cross(b - a, c - a),
		t2 = cross(b - a, d - a),
		t3 = cross(d - c, a - c),
		t4 = cross(d - c, b - c);
	return sgn(t1) * sgn(t2) < 0 && sgn(t3) * sgn(t4) < 0;
}

bool HullJoint(Point *a, int n, Point *b, int m) {
	for(int i = 0; i < n; ++i) if(InPoly(a[i], b, m)) return 1;
	for(int i = 0; i < m; ++i) if(InPoly(b[i], a, n)) return 1;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(SegIntersect(a[i], a[(i + 1) % n], b[j], b[(j + 1) % m])) return 1;//判断所有的线段相交
	return 0;
}

const int N = 20010;

Point a[N], b[N], s1[N], s2[N];

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		for(int i = 0; i < n; ++i) a[i].scan();
		for(int i = 0; i < m; ++i) b[i].scan();
		n = Hull(a, s1, n);
		m = Hull(b, s2, m);
		HullJoint(s1, n, s2, m) ? puts("NO") : puts("YES");
	}
	return 0;
}
