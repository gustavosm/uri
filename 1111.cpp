#include <bits/stdc++.h>

#define INF 9999999

using namespace std;
int g[103][103];
int n;

void floydwarshall()
{
	for (int k = 0 ; k < n; k++)
	{
		for (int i = 0 ; i < n ; i++)
		{
			for (int j = 0 ; j < n ; j++)
			{
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}
int main()
{
	int u;
	int v;
	int z;
	int w;
	int query;
	
	while(1)
	{
		cin >> n ;
		if (!n) return 0;
		
		for (int i = 0 ; i < n * n; i++)
		{
			for (int j = 0 ; j < n * n ; j++)
				g[i][j] = INF;
			g[i][i] = 0;
		}
		
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> u >> v >> z >> w;
				
				
				if (u == 1)
				{
					g[i * n + j][(i + 1) * n + j] = 1;	
				}
				if (v == 1)
				{
					g[i * n + j][(i - 1) * n + j] = 1;
				}
				if (z == 1)
				{
					g[i * n + j][i * n + - 1 + j] = 1;
				}
				if (w == 1)
				{
					g[i * n + j][i * n + 1 + j] = 1;
				}
			}
		}
		
		int nant = n;
		n*= n;
		
		floydwarshall();
		
		cin >> query;
		
		while(query--)
		{
			cin >> u >> v >> z >> w;
			
			u = u + v * nant;
			z = z + w * nant;
			
			if (g[u][z] != INF) cout << g[u][z] << '\n';
			else cout << "Impossible\n";
		}
		cout << '\n';
	}
}
