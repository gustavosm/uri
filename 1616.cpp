#include <bits/stdc++.h>

#define MOD  1000000007
using namespace std;

typedef long long ll;

ll dp[1005][1005];

int btot;
int gtot;

ll ans(int b, int g)
{
	if (b == 0)
	{
		if (g == 0) return 1;
		if (g > 0) return 0;
	}
	if (dp[b][g] == -1)
	{
		dp[b][g] = (ans(b - 1, g) * (gtot - g) + ans(b - 1, g - 1) * g) % MOD;
	}
	return dp[b][g];
}

int main()
{	
	ios_base :: sync_with_stdio(0);
	
	while(1)
	{
		scanf("%d %d", &btot, &gtot);
		for (int i = 0 ; i <= btot; ++i) for (int j = 0; j <= gtot; ++j) dp[i][j] = -1;
		if (!btot && !gtot) return 0;
		
		printf("%lld\n", ans(btot, gtot));
	}
}
