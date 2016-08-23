#include <bits/stdc++.h>

#define INF 9999999
using namespace std;
typedef pair<int, int> ii;

vector<vector<ii > > g;
vector<int> dist;
int n;

int m;

void dijkstra(int source)
{
	dist.clear();
	dist.assign(m * m + 2, INF);
	dist[source] = 0;
	
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	
	pq.push(ii(0, source));
	
	while(!pq.empty())
	{
		ii v = pq.top();
		pq.pop();
		
		
		for (int i = 0 ; i < g[v.second].size(); i++)
		{
			if (dist[g[v.second][i].second] > dist[v.second] + 1)
			{
				dist[g[v.second][i].second] = dist[v.second] + 1;
				pq.push(ii(dist[g[v.second][i].second], g[v.second][i].second));
			}
		}
	}
}
int main()
{
	vector<string> aux;
	string x;
	
	char c;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	while(1)
	{
		cin >> n >> m;
		if (!n && !m) return 0;
		g.assign(m * m + 2, vector<ii> ());
		
		for (int i = 0 ; i < n ; i++)
		{
			cin >> x;
			aux.push_back(x);
		}
		
		for (int i = 0 ; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (aux[i][j] == '.')
				{
					if (i > 0)
					{
						if (aux[i - 1][j] == '.')
						{
							g[m * i + j].push_back(make_pair(1, m * (i - 1) + j));
						}
					}
					if (i < n - 1)
					{
						if (aux[i + 1][j] == '.')
						{
							g[m * i + j].push_back(make_pair(1, m * (i + 1) + j));
						}
					}
					if (j > 0)
					{
						if (aux[i][j - 1] == '.')
						{
							g[m * i + j].push_back(make_pair(1, m * i + j - 1));
						}
					}
					if (j < m - 1)
					{
						if (aux[i][j + 1] == '.')
						{
							g[m * i + j].push_back(make_pair(1, m * i + j + 1));
						}
					}
				}
			}
		}
		int p;
		
		for (p = 0; p < g.size(); ++p) if (g[p].size()) break;
		dijkstra(p);
		int mx = INT_MIN;
		for (int i = 0 ; i < dist.size(); ++i)
		{
			if (dist[i] != INF && dist[i] > mx) mx = dist[i], p = i;
		}
		dijkstra(p);
		mx = INT_MIN;
		for (int i = 0 ; i < dist.size(); ++i)
		{
			if (dist[i] != INF && dist[i] > mx) mx = dist[i];
		}
		
		
		
		cout << mx << '\n';
		
		g.clear();		
		aux.clear();
	}
	
}
