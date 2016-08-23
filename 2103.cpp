#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1300031LL;
vector<vector<pair<int, int> > > g;
int n;
ll ans;
int dfs(int u, int evitar)
{
	int sz = 1;
	int qtd;
	for (int i = 0 ; i < (int)g[u].size(); ++i)
	{
		int &v = g[u][i].second;
		if (v != evitar)
		{
			qtd = dfs(v, u);
			ans += qtd * (n - qtd) * g[u][i].first;
			while (ans >= MOD) ans -= MOD;
			sz += qtd;
		}			
	}
	return sz;
}

int main()
{	
	int u, v, w;
	int cases;
	scanf("%d", &cases);
	
	while (cases--)
	{
		scanf("%d", &n);
		g.assign(n, vector<pair<int, int> >());
		for (int i = 0 ; i < n - 1; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			--u, --v;
			g[u].push_back(make_pair(w, v));
			g[v].push_back(make_pair(w, u));
		}
		ans = 0;
		int chamei = 0;
		for (int i = 0 ; i < n; ++i)
		{
			if ((int)g[i].size() == 1) 
			{
				dfs(i, -1);
				break;
			}
		}
		printf("%lld\n", ans);
	}
}
