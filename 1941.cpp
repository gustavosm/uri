#include <bits/stdc++.h>


using namespace std;


typedef long long ll;
typedef pair<ll, ll> pll;

pll dp[2005][2005];
int especial[2005];
char s[2005];


pll max(pll a, pll b)
{
	if (a.first != b.first) return (a.first < b.first ? b : a);
	return (a.second < b.second? b : a);
}

pll calc(int i, int j)
{
	if (i + 1 == j) 
	{
		if (s[i] == s[j])
			return dp[i][j] = pll(especial[i] + especial[j], 2);
		else 
			return dp[i][j] = pll(especial[i] || especial[j], 1LL);
	}
	if (i == j) return dp[i][j] = pll(especial[i], 1);
	
	pll ans = dp[i][j];
	
	if (ans.first == -1)
	{
		if (s[i] == s[j])
		{
			pll ret = calc(i + 1, j - 1);
			ans.second = 2 + ret.second;
			ans.first = especial[i] + especial[j] + ret.first; 
		}
		
		pll ret = calc(i, j - 1);
		pll ret2 = calc(i + 1, j);
		
		ans = max(ans, max(ret, ret2));
	}
	return dp[i][j] = ans;
}

int main()
{
	int n;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	
	int t = strlen(s);
	for (int i = 0 ; i < t ; ++i)
		for (int j = 0 ; j < t ; ++j)
			dp[i][j].first = dp[i][j].second = -1;
	
	memset(especial, 0, sizeof especial);
	cin >> n;
	
	for (int i = 0 ; i < n ; ++i)
	{
		int x;
		cin >> x;
		--x;
		especial[x] = 1;
	}
	cout << calc(0, t - 1).second << '\n';
}
