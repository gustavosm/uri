#include <bits/stdc++.h>

#define EPS 1e-9
using namespace std;

typedef long long ll;


struct point{
	ll x, y;
	
	point(){x = y = 0;}
	point(ll _x, ll _y) : x(_x), y(_y){}
	
	bool operator < (const point &other) const{
		if (x != other.x) return x < other.x;
		return y < other.y;
	}
};
struct vec 
{
	double x, y; 
	vec(double _x, double _y) : x(_x), y(_y) {} 
};

vector<point> chPts;
vector<point> upper;
vector<point> lower;

vec toVec(point& a, point& b)
{
	return vec(b.x - a.x, b.y - a.y);
}
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
bool ccw(point p, point q, point r) 
{
	return cross(toVec(p, q), toVec(p, r)) > 0; 
}
void ch(vector<point> &pts, vector<point> &up, vector<point> &dn)
{
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
ll dist2(point &a, point &b)
{
	return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
ll rotatingCalipers(vector<point> &up, vector<point> &dn)
{
	ll ans = 123140;
	
	int i = 0, j = dn.size()-1; 
	
	while(i < (int)up.size() - 1 || j > 0){
		// Entrou aqui: up[i] e dn[j] eh um antipodal pair
		ans = min(ans, dist2(up[i],dn[j]));
		
		if(i == (int)up.size()-1) j--;
		else if(j == 0) i++;
		else{
			// Verifica qual o menor angulo a ser rotacionado p utilizar na rotacao
			if((up[i+1].y - up[i].y) * (dn[j].x - dn[j-1].x)
				> (dn[j].y - dn[j-1].y) * (up[i+1].x - up[i].x ))
				i++;
			else
				j--;
		}
	}
	return ans;
}

int main()
{
	int n, c;
	int cases;
	ll x, y;
	cin >> cases;
	
	while (cases--)
	{
		cin >> c;
		double ans = 0.0;
		for (int j = 0 ; j < c; ++j)
		{
			cin >> n;
			chPts.clear();
			for (int i = 0 ; i < n ; ++i)
			{
				cin >> x >> y;
				chPts.push_back(point(x, y));
			}
			sort(chPts.begin(), chPts.end());
			
			upper.clear();
			lower.clear();
			ch(chPts, upper, lower);
			
			ans = max(ans, sqrt(rotatingCalipers(upper, lower)));
			
		}
		cout << setprecision(10) << fixed << (ans) << '\n';
	}
}
