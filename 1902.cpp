#include <bits/stdc++.h>

#define UNVISITED -1

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

map<string, int> m;

vvi AdjList;

vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter, numSCC;

void tarjanSCC(int u) 
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; 
	S.push_back(u);

	visited[u] = 1;
	for (int j = 0; j < (int)AdjList[u].size(); j++) 
	{
		int v = AdjList[u][j];
		if (dfs_num[v] == UNVISITED)
			tarjanSCC(v);
		if (visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]); 
	}
	if (dfs_low[u] == dfs_num[u]) 
	{
		int tam = 0;
		while (1) 
		{
			++tam;
			int v = S.back(); S.pop_back(); visited[v] = 0;
			if (u == v) break; 
		}
		if (tam >= 2) ++numSCC;
	}
}

int main()
{
	string u, v;
	AdjList.assign(100005, vi());
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	int p1, p2;
	int vertices = 0;
	while (cin >> u >> v)
	{
		if (!m.count(u))
		{
			p1 = vertices;
			m[u] = vertices++;
		}
		else p1 = m[u];
		if (!m.count(v))
		{
			p2 = vertices;
			m[v] = vertices++;
		}
		else p2 = m[v];
		
		AdjList[p1].push_back(p2);		
	}
	dfs_num.assign(vertices, UNVISITED); dfs_low.assign(vertices, 0); visited.assign(vertices, 0);
	dfsNumberCounter = numSCC = 0;
	for (int i = 0; i < vertices; i++)
		if (dfs_num[i] == UNVISITED)
			tarjanSCC(i);
	cout << numSCC << '\n';
}
