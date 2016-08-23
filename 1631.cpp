#include <bits/stdc++.h>

#define EPS 0.00000001

using namespace std;

struct point
{
	
	double x, y;
	
	point() {x = y = 0.0;}
	point(double _x, double _y) : x(_x), y(_y) {}
	
	bool operator < (point other) const
	{
		if (fabs(x - other.x) > EPS) return x < other.x;
		else return y < other.y;
	}
	
};

struct vec
{
	double x, y;
	
	vec() {x = y = 0.0;}
	vec(double _x, double _y) : x(_x), y(_y) {}
	
};

vec tovec(point a, point b)
{
	return vec(b.x - a.x, b.y - a.y);
}
double dot(vec a, vec b) {return a.x * b.x + a.y * b.y;}
double norm(vec a) {return dot(a, a);}
vec scale(vec a, double s)
{
	return vec(a.x * s, a.y * s);
}
point translate(point a, vec b)
{
	return point(a.x + b.x, a.y + b.y);
}

double dtol(point p, point a, point b)
{
	vec ap = tovec(a, p), ab = tovec(a, b);
	
	double u = dot(ap, ab) / norm(ab);
	
	point c = translate(a, scale(ab, u));
	
	return hypot(p.x - c.x, p.y - c.y);
}
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x;}
bool ccw(point p, point q, point r) {return cross(tovec(p, q), tovec(p, r)) > 0.0;}
int main()
{
	point v[106];
	
	int n;
	double x, y;
	
	while (1)
	{
		cin >> n;
		if (!n) return 0;
		
		for (int i = 0 ; i < n ; i++)
		{
			cin >> x >> y;
			v[i] = point(x, y);
		}
		
		double ans = (double) INT_MAX;
		for (int i = 0; i < n ; i++)
		{
			for (int j = i + 1; j < n ; j++)
			{
				double d1 = 0.0;
				double d2 = 0.0;
				for (int k = 0 ; k < n ; k++)
				{
					if (k == i || k == j) continue;
					if (ccw(v[i], v[k], v[j])) d1 += dtol(v[k], v[i], v[j]);
					else d2 += dtol(v[k], v[i], v[j]);
					
				}
				if (fabs(d1 - d2) < ans) ans = fabs(d1 - d2);
			}
		}
		cout << setprecision(3) << fixed << ans << '\n';
	}
}
