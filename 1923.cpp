#include <bits/stdc++.h>


#define INF 999999

using namespace std;

map<string, int> m;
vector<string> ans;
vector<vector<int> > v;
vector<int> d;

int n;

int m1, g;

void dijkstra()
{
	priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > q;
	
	d.assign(n, INF);
	
	d[0] = 0;
	q.push(make_pair(0, 0));
	
	while (!q.empty())
	{
		pair<int, int> u = q.top(); q.pop();
		
		int uf = u.first;
		int us = u.second;
		if (uf > d[us]) continue;
		
		for (int i = 0; i < v[us].size(); ++i)
		{
			if (d[v[us][i]] > d[us] + 1)
			{
				d[v[us][i]] = d[us] + 1;
				q.push(make_pair(d[v[us][i]], v[us][i]));
			}
		}
	}
}

int main()
{
	string u, v1;
	int marca;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	while (cin >> m1 >> g)
	{
		v.clear();
		m.clear();
		d.clear();
		m["Rerisson"] = 0;
		n = 1;
		
		v.assign(2010, vector<int> ());
		
		while (m1--)
		{
			cin >> u >> v1;
			int p1, p2;
			if (!m.count(u))
				m[u] = p1 = n++;
			else p1 = m[u];
			
			if (!m.count(v1))
				m[v1] = p2 = n++;
			else p2 = m[v1];
			
			v[p1].push_back(p2);
			v[p2].push_back(p1);
		}
		
		dijkstra();
		d[0] = INF;
		for (map<string, int> :: iterator it = m.begin(); it != m.end(); ++it)
		{
			if (d[it->second] <= g)
				ans.push_back(it->first);
		}
		cout << ans.size() << '\n';
		
		for (int i = 0 ; i < ans.size(); ++i) cout << ans[i] << '\n';
		ans.clear();
	}
}
