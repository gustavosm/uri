#include <bits/stdc++.h>

#define INF 999999
using namespace std;
typedef pair<int, int> ii;

int v[255][255];
int caminho[255];
int n, m, c, k1;

void floydwarshall()
{
	for (int k = c ; k < n ; ++k)
		for (int i = 0 ; i < n ; ++i)
			for (int j = 0 ; j < n ; ++j)
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
}

int main()
{
	
	int u, w, p;
	int v1, v2;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	while (1)
	{
		cin >> n >> m >> c >> k1;
		if (!n) return 0;
		
		memset(v, INF, sizeof v);
		memset(caminho, 0, sizeof caminho);
		
		for (int i = 0 ; i < m ; ++i)
		{
			cin >> u >> w >> p;
			v[u][w] = v[w][u] = p;
		}
		int sum = 0;
		for (int i = c - 2 ; i >= 0; --i)
		{
			sum += v[i][i + 1];
			
			caminho[i] = sum;
		}
		floydwarshall();
		int ans = v[k1][c - 1];
		for (int i = 0 ; i < c - 1; ++i)
		{
			ans = min(v[k1][i] + caminho[i], ans);
		}
		cout << ans << '\n';
	}
}

