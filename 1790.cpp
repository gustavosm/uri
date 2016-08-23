#include <bits/stdc++.h>

#define UNVISITED -1

using namespace std;

int dfsNumberCounter;
int dfs_low[60], dfs_parent[60], dfs_num[60];
int bridges;

vector<vector<int> > AdjList;

void dfs(int u) 
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
	
	for (int j = 0; j < (int)AdjList[u].size(); j++) 
	{
		int v = AdjList[u][j];
		if (dfs_num[v] == UNVISITED) 
		{	
			dfs_parent[v] = u;
			dfs(v);
			
			if (dfs_low[v] > dfs_num[u])
				++bridges;
		
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (v != dfs_parent[u]) 
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	} 
}

int main()
{
	int n, m;
	
	while (cin >> n >> m)
	{
		memset(dfs_low, UNVISITED, sizeof dfs_low);
		memset(dfs_parent, UNVISITED, sizeof dfs_parent);
		memset(dfs_num, UNVISITED, sizeof dfs_num);
		
		dfsNumberCounter = bridges = 0;
		
		AdjList.assign(n, vector<int> ());
		
		for (int i = 0 ; i < m; ++i)
		{
			int u, v;
			cin >> u >> v;
			--u;
			--v;
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}
		
		dfs(0);
		
		cout << bridges << '\n';
		
		AdjList.clear();
		
	}
}
