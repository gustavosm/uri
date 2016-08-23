#include <bits/stdc++.h>
 
#define EPS 0.000000001
#define INF 2000000000.000000
using namespace std;
 
typedef long long L;
 
vector<pair<double, pair<int, int > > > g;
vector<int> pset;
void init(int N)
{
    pset.assign(N, 0);
     
    for (int i = 0 ; i < N ; ++i) pset[i] = i;
}
 
int findSet(int i)
{
    return (pset[i] == i? i : pset[i] = findSet(pset[i]));
}
bool issame(int i, int j)
{
    return findSet(i) == findSet(j);
}
void unionset(int i, int j)
{
    pset[findSet(i)] = findSet(j);
}
 
struct point
{
    double x, y;
     
    point() {x = y = 0.0;}
    point(double _x, double _y) : x(_x), y(_y) {}
     
    bool operator < (const point &other) const
    {
        if (fabs(x - other.x) > EPS) return x < other.x;
        return y < other.y;
    }
    bool operator == (const point &other) const
    {
		return (fabs(x - other.x) < EPS && fabs(y - other.y) < EPS);
    }
    bool operator <= (const point &other) const
    {
        return ((*this < other) || (*this == other));
    }
    double operator %(const point& q) { return x * q.y - y * q.x; }
};
 
struct vec
{
    double x, y;
    vec() {x = y = 0.0;}
    vec(double _x, double _y) : x(_x), y(_y) {} 
};
 
// Cross product
inline int cross(const vec & a, const vec &b){
  return a.x*b.y - a.y*b.x;
}
vec toVec(point a, point b)
{
    return vec(b.x - a.x, b.y - a.y);
}
vec scale(vec v, double s)
{
    return vec(v.x * s, v.y * s);
}
point translate(point p, vec v)
{
    return point(p.x + v.x, p.y + v.y);
}


// Returns orientation between vector a and vector b
// 1: CW/ -1: CCW
inline int orientation(const vec & a, const vec & b){
  L c = cross(a,b);
  if(c == 0) return 0;
  return c < 0 ? 1 : -1;
}


// Returns if point q is on segment pr
inline bool onSegment(const point & p, const point & q, const point & r)
{
    if (orientation(toVec(p, q), toVec(p, r)) == 0 &&
        q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
inline bool doIntersect(const point & p1, const point & q1,
                        const point & p2, const point & q2)
{
    // Find the four orientations needed
    int o1 = orientation(toVec(p1,q1),toVec(p1,p2));
    int o2 = orientation(toVec(p1,q1),toVec(p1,q2));
    int o3 = orientation(toVec(p2,q2),toVec(p2,p1));
    int o4 = orientation(toVec(p2,q2),toVec(p2,q1));

    // General case (it's being checked wether the points are on the segment)
    if (o1 != o2 && o3 != o4)
        return true;
        
        // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}
 
double dot(vec a, vec b)
{
	return a.x * b.x + a.y * b.y;
}
double dist(point a, point b)
{
    return hypot(a.x - b.x, a.y - b.y);
}
inline int cmp(double x, double y=0, double tol=EPS)
{
    return (x<=y+tol) ? (x+tol<y) ? -1 : 0 : 1;
}
double dtos(point r, point p, point q)
{
	point A = point(r.x - q.x, r.y - q.y), B = point(r.x - p.x, r.y - p.y), C = point(q.x - p.x, q.y - p.y);
	double a = A.x * A.x + A.y * A.y, b = B.x * B.x + B.y * B.y, c = C.x * C.x + C.y * C.y;
	
	if (cmp(b, a+c) >= 0) return sqrt(a);
	if (cmp(a, b+c) >= 0) return sqrt(b);
	return fabs(A%B) / sqrt(c);
}

int main()
{
    int n;
    vector<pair<point, point> > v;
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    double x1, y1;
    double x2, y2;
    while (cin >> n)
    {
        for (int i = 0 ; i < n ; ++i)
        {
            cin >> x1 >> y1 >> x2 >> y2;
     
            v.push_back(make_pair(point(x1,  y1), point(x2, y2)));
        }
 
        for (int i = 0 ; i < n ; ++i)
        {
            for (int j = i + 1; j < n ; ++j)
            {
                if (doIntersect(v[i].first, v[i].second, v[j].first, v[j].second))
                    g.push_back(make_pair(0.0, make_pair(i, j)));
                    
                else
                {
                    double mn = min(dtos(v[i].first, v[j].first, v[j].second), min(dtos(v[i].second, v[j].first, v[j].second), min(dtos(v[j].first, v[i].first, v[i].second), dtos(v[j].second, v[i].first, v[i].second))));
                     
                    g.push_back(make_pair(mn, make_pair(i, j)));
                }
            }
        }
        sort(g.begin(), g.end());
        init(n);
        double ans = 0.0;
        for (int i = 0 ; i < g.size(); ++i)
        {
            if (!issame(g[i].second.first, g[i].second.second))
            {
                ans += g[i].first;
                unionset(g[i].second.first, g[i].second.second);
            }
        }
        int ans2 = ans;
        ans -= ans2;
        if (ans > EPS) cout << ans2 + 1 << '\n';
        else cout << ans2 << '\n';
        
        g.clear();
        pset.clear();
        v.clear();
    }
}
