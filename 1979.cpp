#include <bits/stdc++.h>


using namespace std;

vector<vector<int> > adj;
int n;

bool partite()
{
	vector<int> color;
	
	color.assign(n, -1);
	
	queue<int> q;
	q.push(0);
	color[0] = 0;
	bool ispartite = true;
	while (!q.empty() && ispartite)
	{
		int u = q.front(); q.pop();
		
		for (int j = 0 ; j < adj[u].size(); ++j)
		{
			if (color[adj[u][j]] != -1 && color[adj[u][j]] == color[u])
			{
				ispartite = false;
				break;
			}
			else if (color[adj[u][j]] == -1)
			{
				color[adj[u][j]] = color[u] ^ 1;
				q.push(adj[u][j]);
			}
		}
	}
	while (!q.empty()) q.pop();
	color.clear();
	return ispartite;
}

int main()
{
	string in;
	
	stringstream ss;
	
	int s;
	int v;
	
	while (cin >> n)
	{
		if (!n) return 0;
		adj.assign(n, vector<int> ());
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> v;
			getchar();
			getline(cin, in);
			--v;
			ss << in;
			
			while (ss >> s)
				adj[v].push_back(s - 1);
			
			ss.clear();
		}
		
		if (partite()) cout << "SIM\n";
		else cout << "NAO\n";
		adj.clear();
	}
		
}
