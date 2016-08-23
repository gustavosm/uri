#include <bits/stdc++.h>

#define pb push_back

using namespace std;
typedef vector<int> vi;
typedef vector<vi > vii;

vii v;
vi visited;

void dfs(int n, int space)
{
	visited[n] = 1;
	for (int i = 0 ; i < v[n].size(); i++)
	{
		for (int j = 0 ; j < space; j++)
			cout << ' ';
		cout << n << "-" << v[n][i];
		if (!visited[v[n][i]] )
		{
			cout << " pathR(G," << v[n][i] << ")\n";
			dfs(v[n][i], space+2);
		}
		else cout << '\n';
	}
}
int main ()
{
	static int cases = 1;
	int V;
	int E;
	int u;
	int w;
	int teste;
	vi marcado;
	cin >> teste;
	while(teste--)
	{
		cin >> V >> E;
		for (int i = 0 ; i < V; i++)
		{
			v.pb(vi());
			visited.pb(0);
			marcado.pb(0);
		}
		for (int i = 0 ; i < E; i++)
		{
			cin >> u >> w;
			marcado[u] = 1;
			v[u].pb(w);
		}
		for (int i = 0 ; i < V; i++)
		{
			sort(v[i].begin(), v[i].end());
		}
		cout << "Caso " << cases << ":\n";
		cases++;
		for (int i = 0 ; i < V; i++)
		{
			if (!visited[i] && marcado[i])
			{
				dfs(i,2);	
				cout << '\n';	
			}
		}
		v.clear();
		visited.clear();
		marcado.clear();
	}
	
}
