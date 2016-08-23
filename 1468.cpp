#include <bits/stdc++.h>

#define T_ADD 0
#define T_QUERY 1
#define T_RM 2

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef set<int, bool(*)(int a, int b)> active_set;

struct point
{
	ll x, y;
	
	point(){x = y = 0;}
	point(ll a, ll b) {x = a; y = b;}
	
	bool operator < (const point rhs) const
	{
		if(x < rhs.x) return true;
		return false;
	}
};

typedef pair<int, point> ip;

struct evt
{
	point p;
	int type, segid;
	evt()
	{
		p = point();
	}
	evt(point _p, int _t, int _s)
	{
		p = _p; type = _t; segid = _s;
	}
	
	bool operator < (const evt rhs) const
	{
		if (p < rhs.p) return true;
		if (rhs.p < p) return false;
		if (type < rhs.type) return true;
		return false;
	}
};

vector<pair<point,point> > lines;

inline bool line_cmp(const int lhs, const int rhs){
	if(lines[lhs].first.x > lines[rhs].first.x && lines[lhs].first.x < lines[rhs].second.x){
		return (lines[rhs].second.x - lines[rhs].first.x) * (lines[lhs].first.y - lines[rhs].first.y) - (lines[rhs].second.y - lines[rhs].first.y) * (lines[lhs].first.x - lines[rhs].first.x) < 0;
	}
	else if(lines[lhs].first.x < lines[rhs].first.x && lines[lhs].second.x > lines[rhs].first.x){
		return (lines[lhs].second.x - lines[lhs].first.x)*(lines[rhs].first.y - lines[lhs].first.y) - (lines[lhs].second.y - lines[lhs].first.y) * (lines[rhs].first.x - lines[lhs].first.x) > 0;
	}
	return false;
}

int n, c;
vector<evt> evts;
active_set active(line_cmp);
vector<ip> plines;
vector<ip> pbalao;

ip getp(int p)
{
	if (p == plines[p].first) return plines[p];
	
	ip pp = getp(plines[p].first);
	
	if (pp.second.x == -1)
		plines[p].second.y = pp.second.y;
	else plines[p] = pp;
	
	plines[p].first = p;
	
	return plines[p];
}

int main()
{
	while (cin >> n >> c)
	{
		lines.assign(n, pair<point, point>());
		evts.assign(n * 2 +  c, evt());
		plines.assign(n, ip(-1, point(-1, -1)));
		pbalao.assign(c, ip(-1, point(-1, -1)));
		int i = 0;
		for (; i < n; ++i)
		{
			plines[i].first = i;
			cin >> lines[i].first.x >> lines[i].first.y;
			cin >> lines[i].second.x >> lines[i].second.y;
			
			if (lines[i].second < lines[i].first)
				swap(lines[i].first, lines[i].second);
				
			if (lines[i].first.y > lines[i].second.y)
				plines[i].second.x = lines[i].first.x;
			else if (lines[i].first.y < lines[i].second.y) 
				plines[i].second.x = lines[i].second.x;
			else 
			{
				plines[i].second.x = -1;
				plines[i].second.y = lines[i].first.y;
			}
			
			evts[i * 2].p = lines[i].first;
			evts[i * 2].type = T_ADD;
			evts[i * 2].segid = i;
			
			evts[i * 2 + 1].p = lines[i].second;
			evts[i * 2 + 1].type = T_RM;
			evts[i * 2 + 1].segid = i;
		}
		i *= 2;
		
		for (int k = 0 ; k < c; ++k, ++i)
		{
			cin >> evts[i].p.x;
			evts[i].type = T_QUERY;
			evts[i].segid = k;
			pbalao[k].second.x = evts[i].p.x;
		}
		sort(evts.begin(), evts.end());
		
		active.clear();
		active_set :: const_iterator itp;
		
		for (int k = 0 ; k < (int)evts.size(); ++k)
		{
			if (evts[k].type == T_ADD)
			{
				active.insert(evts[k].segid);
				if (lines[evts[k].segid].first.y > lines[evts[k].segid].second.y)
				{
					itp = active.find(evts[k].segid);
					++itp;
					if (itp != active.end())
						plines[evts[k].segid].first = *itp;
				}
			}
			else if (evts[k].type == T_RM)
			{
				if (lines[evts[k].segid].second.y > lines[evts[k].segid].first.y)
				{
					itp = active.find(evts[k].segid);
					++itp;
					if (itp != active.end())
						plines[evts[k].segid].first = *itp;
				}
				active.erase(evts[k].segid);
			}			
			else if (evts[k].type == T_QUERY)
				if (active.size() > 0)
					pbalao[evts[k].segid].first = *(active.begin());
		}
		for (int k = 0 ; k < c; ++k)
		{
			if (pbalao[k].first == -1) cout << pbalao[k].second.x;
			else
			{
				ip acima = getp(pbalao[k].first);
				cout << (acima.second.x != -1? acima.second.x : pbalao[k].second.x);
				if (acima.second.y != -1) cout << ' ' << acima.second.y;
				cout << '\n';
			}
		}
		lines.clear();
		evts.clear();
		plines.clear();
		pbalao.clear();
	}
}
