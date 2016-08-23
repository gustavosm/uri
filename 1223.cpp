#include <bits/stdc++.h>


#define EPS 0.000000001
#define INF 2000000000.000000
using namespace std;

struct point
{
    int x, y;
     
    point() {x = y = 0.0;}
    point(int _x, int _y) : x(_x), y(_y) {}
     
    bool operator < (const point &other) const
    {
    	if (x != other.x) return x < other.x;
    	return y < other.y;
    }
    bool operator == (const point &other) const
    {
		return x == other.x && y == other.y;
    }
    bool operator <= (const point &other) const
    {
        return ((*this < other) || (*this == other));
    }
    int operator %(const point& q) { return x * q.y - y * q.x; }
};
struct segment
{
	point first;
	point second;
	
	segment() {first = point(); second = point();}
	segment(point a, point b) {first = a; second = b;}
};

inline int cmp(int x, int y=0)
{
    return (x <= y) ? (x < y) ? -1 : 0 : 1;
}
double dtos(point r, point p, point q)
{
	point A = point(r.x - q.x, r.y - q.y), B = point(r.x - p.x, r.y - p.y), C = point(q.x - p.x, q.y - p.y);
	int a = A.x * A.x + A.y * A.y, b = B.x * B.x + B.y * B.y, c = C.x * C.x + C.y * C.y;
	
	if (cmp(b, a+c) >= 0) return sqrt(a);
	if (cmp(a, b+c) >= 0) return sqrt(b);
	return abs(A%B) / sqrt(c);
}

int main()
{
	vector<segment> v;
	
	int xf, yf, yi;
	int n;
	int l, h;
	point parede1c, parede2c, parede1f, parede2f;
	while (cin >> n)
	{
		cin >> l >> h;
		
		parede1c = point(0, h);
		parede1f = point(0, 0);
		
		parede2c = point(l, h);
		parede2f = point(l, 0);
		
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> yi >> xf >> yf;
			if (i & 1)
				v.push_back(segment(point(l, yi),point(xf, yf)));
			else v.push_back(segment(point(0, yi),point(xf, yf)));
		
		}
		
		int n1 = v.size();
		double ans;
		if (n & 1)
			ans = dtos(v[n1 - 1].second, parede2c, parede2f);
		else ans = dtos(v[n - 1].second, parede1c, parede1f);
		cout << "Ate agora tenho " << ans << '\n';
		int cont = 0;	
		for (int i = 0 ; i < n - 1 ; ++i, ++cont)
		{
			ans = min(ans, dtos(v[i].second, v[i + 1].first, v[i + 1].second)); 
			if (cont & 1)
				ans = min(dtos(v[i].second, parede2c, parede2f), ans);
			else
				ans = min(dtos(v[i].second, parede1c, parede1f), ans);
			cout << "Ate agora tenho " << ans << '\n';
		}
		
		cout << setprecision(2) << fixed << ans << '\n';
		v.clear();
	}
}
