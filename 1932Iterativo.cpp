#include <bits/stdc++.h>


using namespace std;
typedef int ll;

ll dp[200005][2];
ll v[200005];
int n, c;

ll calc()
{
	dp[n][0] = dp[n][1] = 0;
	
	for (int i = n - 1; i >= 0 ; --i)
	{
		for (int j = 0 ; j <= 1; ++j)
		{
			ll x = (j? v[i] : -(v[i] + c));
			
			dp[i][j] = max(x + dp[i + 1][!j], dp[i + 1][j]);
		}
	}
	return dp[0][0];
}

int main()
{	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while (cin >> n >> c)
	{
		for (int i = 0 ; i < n ; ++i) cin >> v[i];
		
		memset(dp, -1, sizeof dp);
		
		int ans = calc();
		
		cout << ans << '\n';
	}
}
