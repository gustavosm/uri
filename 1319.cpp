#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int dp[105][105];

pll v[105];
int n;
ll m;

int pode(int i, int idx, int ult)
{
	return v[ult].second <= v[i].first && v[i].first <= v[idx].first;
}
int calc(int idx, int ult)
{
	if (idx == n) return 0;
	
	int &ans = dp[idx][ult];
	
	if (ans == -1)
	{
		for (int i = 0 ; i < n ; ++i)
		{
			if (i == idx || i == ult) continue;
			if (pode(i, idx, ult))
				ans = max(ans, 1 + calc(i, idx));
		}
	}
	return ans;
}


int main()
{
	while(1)
	{
		cin >> m >> n;
		
		if (!m && !n) return 0;
		
		for (int i = 0 ; i < n ; ++i)
		{
			ll x, y;
			cin >> x >> y;
			v[i] = pll(x, y);
		}
		sort(v, v + n);
		memset(dp, -1, sizeof dp);
		int ans = -1;
		for (int i = 0 ; i < n ; ++i)
		{
			for (int j = i + 1; j < n ; ++j)
				ans = max(ans, calc(i, j));	
		}
		
		cout << ans << '\n';
	}
}
