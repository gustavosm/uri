#include <bits/stdc++.h>

#define INF -2000000000000LL
using namespace std;

typedef long long ll;

ll v[125][125];
ll dp[125][125];
ll n, m;
ll k;
string p[105];

ll maxi(ll a, ll b)
{
	return (a > b ? a : b);
}

ll val(int linha, string& pr)
{
	ll r = 0;
	
	for (int i = 0; i < m; ++i)
	{
		if (pr[i] == '+') r += v[linha][i];
		else if (pr[i] == '-') r -= v[linha][i];
	}
	return r;
}
int compativel(string &s, string& s2)
{
	for (int i = 0; i < m; ++i) if (s[i] != '.') if (s[i] == s2[i]) return 0;
	return 1;
}

ll calc(int linha, int padrao)
{
	if (linha == n) return 0;
	ll ret;
	ll &reet = dp[linha][padrao];
	if (reet == INF)
	{
		for (int i = 0 ; i < k; ++i)
		{
			if (compativel(p[i], p[padrao]))
			{
				ret = calc(linha + 1, i);
				reet = maxi(reet, val(linha, p[i]) + ret);
			}
		}
	}
	return reet;
}

int main()
{
	while (1)
	{
		cin >> n >> m;
		if (!n && !m) return 0;
		
		for (int i = 0 ; i < n ; ++i ) 
		{
			for (int j = 0 ; j < m ; ++j) 
			{
				cin >> v[i][j];
			}
		}
		
		
		cin >> k;
		
		for (int i = 0 ; i < n; ++i)
			for (int j = 0 ; j < k; ++j)
				dp[i][j] = INF;
		
		for (int i = 0 ; i < k; ++i) 
			cin >> p[i];
		
		ll ans = INF;
		
		for (int i = 0; i < k; ++i)
		{
			ll ret = calc(1, i);
			
			ans = maxi(ans, val(0, p[i]) + ret);
		}
		cout << ans << '\n';
	}
}
