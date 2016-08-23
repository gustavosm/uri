#include <bits/stdc++.h>


using namespace std;


int dp[55][55][11];
int g[55][55];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};
int n;
int val(int i, int j)
{
	return i >= 0 && i < n && j >= 0 && j < n;
}

int calc(int i, int j, int m)
{
	if (!val(i, j)) return 0;
	if (g[i][j] == 0) return -19999999;
	
	if (!m) return 0;
	
	int &ans = dp[i][j][m];
	
	if (ans == -1)
	{
		for (int i1 = 0 ; i1 < 4; ++i1)
		{
			int aux = g[i][j];
			g[i][j] = 0;
			ans = max(ans, aux + calc(i + dr[i1], j + dc[i1], m - 1));
			g[i][j] = aux;
		}
	}
	return ans;
}
int main()
{
	int m;
	
	while (cin >> n >> m)
	{
		for (int i = 0 ; i < n ; ++i) for (int j = 0 ; j < n ; ++j)
			cin >> g[i][j];
		memset(dp, -1, sizeof dp);
		
		int resp = -1;
		
		for (int i = 0 ; i < n ; ++i) for (int j = 0 ; j < n ; ++j)
		{
			resp = max(resp, calc(i, j, m));
			cout << "em " << g[i][j] << " deu resp = " << resp << '\n';
		}
		cout << resp << '\n';
	}
}
