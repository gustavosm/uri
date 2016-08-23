#include <bits/stdc++.h>


using namespace std;

int vis[1005][1005];
int dp[1005][1005];
char g[1005][1005];
vector<pair<int, int> > vazio;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int n, m;
int iteracao;

int val(int i, int j)
{
	return i >= 0 && i < n && j >= 0 && j < m;
}
int dfs(int i, int j)
{
	if (g[i][j] == 'b') return 0;
	
	if (g[i][j] == '*') return 0;
	
	if (vis[i][j] == 1) return dp[i][j];
	
	vis[i][j] = 1;
	int ans = 1;
	for (int k = 0 ; k < 4; ++k)
	{
		if (val(i + dr[k], j + dc[k]))
			ans += dfs(i + dr[k], j + dc[k]);
	}
	dp[i][j] = ans;
	return ans;
}

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	for (int i = 0 ; i < n ; ++i)
	{
		for (int j = 0 ; j < m; ++j)
		{
			cin >> g[i][j];
			if (g[i][j] == '*')
				vazio.push_back(make_pair(i, j));
		}
	}
	
	memset(vis, 0, sizeof vis);
	int pos1, pos2, maxn;
	maxn = -1;
	for (iteracao = 1 ; iteracao <= vazio.size(); ++iteracao)
	{
		int maior = 0;
		int x = vazio[iteracao - 1].first;
		int y = vazio[iteracao - 1].second;
		
		for (int i = 0 ; i < 4; ++i)
			if (val(x + dr[i], y + dc[i]))
				maior += dfs(x + dr[i], y + dc[i]);
		
		if (maior > maxn)
		{
			maxn = maior;
			pos1 = x + 1;
			pos2 = y + 1;
		}
	}
	cout << pos1 << ',' << pos2 << '\n';
	
}
