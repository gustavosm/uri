#include <bits/stdc++.h>


using namespace std;


struct point{
	int x, y;
	point() {x = y = 0;}
	point(int _x, int _y) : x(_x), y(_y){}
	bool operator < (const point &other) const
	{
		if (x != other.x) return x < other.x
		; return y < other.y;
	}
};

struct vec 
{
	int x, y; 
	vec(int _x, int _y) : x(_x), y(_y) {} 
};

vec toVec(point a, point b) { return vec(b.x - a.x, b.y - a.y); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r) { return cross(toVec(p, q), toVec(p, r)) > 0; }

void convexHull(vector<point> &pts, vector<point> &up, vector<point> &dn){
	up.assign(pts.size(),point());
	dn.assign(pts.size(),point());
	int i = 0, j = 0;
	
	for(vector<point>::iterator it = pts.begin(); it != pts.end(); ++it){
		while(i > 1 && ccw(up[i-2], up[i-1], *it)) i--;
		while(j > 1 && !ccw(dn[j-2], dn[j-1], *it)) j--;
		
		up[i++] = *it;
		dn[j++] = *it;
	}
	up.resize(i);
	dn.resize(j);
}

vector<point> upc, dnc, ptsc;

double dist(point &a, point &b)
{
	return hypot(a.x - b.x, a.y - b.y);
}
int main()
{
	int n;
	cout.precision(2);
	int x, y;
	
	while (cin >> n)
	{
		if (!n) return 0;
		
		double ans = 0.0;
		ptsc.clear();
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> x >> y;
			ptsc.push_back(point(x, y));
		}		
		sort(ptsc.begin(), ptsc.end());
		
		convexHull(ptsc, upc, dnc);
		
		for (int i = 0 ; i < upc.size() - 1; ++i)
			ans += dist(upc[i], upc[i + 1]);
			
		for (int i = 0 ; i < dnc.size() - 1; ++i)
			ans += dist(dnc[i], dnc[i + 1]);
			
		cout << fixed << "Tera que comprar uma fita de tamanho " << ans << ".\n";
	}
}
