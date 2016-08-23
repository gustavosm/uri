#include <bits/stdc++.h>


#define MOD 1000000007

using namespace std;

typedef long long ll;


ll dp[105][105];

ll comb[105][105];
int N;


void calc()
{
	comb[0][0] = 0;
	for (int i = 1; i <= 101; ++i)
	{
		comb[i][0] = comb[0][i] = 1;
		for (int j = 1; j <= i; ++j)
		{
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
		//	cout << "Comb[ " << i << " ] [ " << j << " ] = " << comb[i][j] << '\n';
		}
	}
}
ll solve(int n, int k)
{
	if (k == 1) 
		if (n <= 1) return 1;
		else return 0;
	
	if (n <= 1) return 1;
		
	ll &ans = dp[n][k];
	
	if (ans == -1)
	{
		ans = 0;
		
		for (int i = 1; i <= n; ++i)
		{
			ans += comb[n - 1][i - 1] * i * solve(n - i, k - 1) * solve(i - 1, k - 1);
		}
	}
	return ans;
}

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	
	calc();
	int k;
	cin >> N >> k;
	memset(dp, -1, sizeof dp);
	
	cout << solve(N - 1, k) << '\n';
}
