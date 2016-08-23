#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define INF INT_MAX

using namespace std;
typedef pair<int, int> ii;

vector<vector<ii > > g;
vector<vector<ii > > g2;
vector<int> d;
vector<int> d2;

int n, m;

void dijkstra1(int s)
{
	d.assign(n, INF);
	d[s] = 0;
	
	priority_queue< ii, vector<ii > , greater<ii > > pq;
	
	pq.push(mp(0, s));
	
	while (!pq.empty())
	{
		ii u = pq.top(); pq.pop();
		
		int x = u.second;
		
		for (int i = 0 ; i < g[x].size(); ++i)
		{
			if (d[g[x][i].second] > d[x] + g[x][i].first)
			{
				d[g[x][i].second] = d[x] + g[x][i].first;
				pq.push(mp(d[g[x][i].second], g[x][i].second));
			}
		}
	}
}

void dijkstra2(int s)
{
	d2.assign(n, INF);
	d2[s] = 0;
	
	priority_queue< ii, vector<ii > , greater<ii > > pq;
	
	pq.push(mp(0, s));
	
	while (!pq.empty())
	{
		ii u = pq.top(); pq.pop();
		
		int x = u.second;
		
		for (int i = 0 ; i < g2[x].size(); ++i)
		{
			if (d2[g2[x][i].second] > d2[x] + g2[x][i].first)
			{
				d2[g2[x][i].second] = d2[x] + g2[x][i].first;
				pq.push(mp(d2[g2[x][i].second], g2[x][i].second));
			}
		}
	}
}
int main()
{
	int s, t, w, u, v;
	while (1)
	{
		cin >> n >> m;
		
		if (!n && !m) return 0;
		
		cin >> s >> t;
		g.assign(n, vector<ii>());
		g2.assign(n, vector<ii>());
		
		for (int i = 0; i < m; ++i)
		{
			cin >> u >> v >> w;
			
			g[u].pb(mp(w, v));
			g2[v].pb(mp(w, u));
		}
		
		d.clear();
		dijkstra1(s);
		d2.clear();
		dijkstra2(t);
		
		for (int i = 0 ; i < n ; ++i)
		{
			for (int j = 0 ; j < g[i].size(); ++j)
			{
				if (d[i] + g[i][j].first + d2[g[i][j].second] == d[t])
					g[i].erase(g[i].begin() + j);
			}
		}
		d.clear();
		dijkstra1(s);
		if (d[t] != INF)
			cout << d[t] << '\n';
		else cout << "-1\n";
		
		g.clear();
		g2.clear();
	}
}
