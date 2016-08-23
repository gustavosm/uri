#include <bits/stdc++.h>

using namespace std;
typedef pair<int, pair<int,int> > iii;
vector<int> ps;

void init(int n)
{
	ps.assign(n,0);
	for (int i = 0 ; i < n; i++)
		ps[i] = i; //vertice i na componente i
}

int findSet(int i)
{
	return (ps[i] == i? i : ps[i] = findSet(ps[i]));
}

bool isSameSet(int i, int j)
{
	return findSet(i) == findSet(j);
}
void unionSet(int i, int j)
{
	ps[findSet(i)] = findSet(j);
}

int main()
{
	vector< iii >adj;
	int n;
	int m;
	int v;
	int u;
	int peso;
	int min_cost;
	
	while(cin >> n >> m)
	{
		for (int i = 0 ; i < m ; i++)
		{
			cin >> u >> v >> peso;
			--u;
			--v;
			adj.push_back(iii(peso, pair<int,int> (u,v)));
		}
		min_cost = 0;
		sort(adj.begin(), adj.end());
		
		init(n);
		for (int i = 0 ; i < m ; i++)
		{
			iii f = adj[i];
			if (!isSameSet(f.second.first, f.second.second))
			{
				unionSet(f.second.first, f.second.second);
				min_cost+= f.first;
			}
		}
		cout << min_cost << '\n';
		ps.clear();
		adj.clear();
	}
}
