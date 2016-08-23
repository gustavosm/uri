#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXN 10000010

short isp[MAXN];
int modo;
int l, c, k;
int g[1005][1005];
int dp[1005][1005][6];

int val(int i, int j)
{
	return i >= 0 && i < l && j >= 0 && j < c;
}

void sieve()
{
	memset(isp, 1, sizeof isp);
	isp[1] = isp[0] = 0;
	for(ll i = 4; i < MAXN; i+=2) isp[i] = 0;

	for(ll i = 3; i < MAXN; i+=2) if(isp[i])
		for(ll x = i * i; x < MAXN; x+=i) isp[x] = 0;

}
int calc(int i, int j, int k1)
{
	if (!val(i, j)) return 0;
	
	int &ans = dp[i][j][k1];
	
	if (!ans)
	{
		//cout << "Estou no " << g[i][j] << '\n';
		ans = 1;
		if (k1 && (isp[g[i][j]]))
			ans = max(1 + calc(i - modo, j, k1 - 1), 1 + calc(i, j + modo, k1 - 1));

		if (val(i - modo, j))
		{
			if (g[i][j] > g[i - modo][j])
				ans = max(ans, 1 + calc(i - modo, j, k1));
		}

		if (val(i, j + modo))
		{
			//cout << "comparando " << g[i][j] << " com " << g[i][j + modo] << '\n';
			if (g[i][j] > g[i][j + modo])
				ans = max(ans, 1 + calc(i, j + modo, k1));
		}
	}
	//cout << "Vou retornar " << ans << '\n';
	return ans;
}

int main()
{
	char x;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	sieve();
	c = 1;
	while (1)
	{
		cin >> l >> c >> k;
		if (!l && !c && !k) return 0;
		cin >> x;
		
		if (x == 'N') modo = 1;
		else modo = -1;
		
		for (int i = 0 ; i < l ; ++i)
		{
			for (int j = 0 ; j < c;  ++j)
			{
				cin >> g[i][j];
				for (int k1 = 0 ; k1 <= 5; ++k1)
					dp[i][j][k1] = 0;
			}
		}
		int resp = -1;
		
		for (int i = 0 ; i < l ; ++i)
		{
			for (int j = 0 ; j < c; ++j)
			{
				//cout << "analisando " << g[i][j] << '\n';
				int ret = calc(i, j, k);
				//cout << "deu " << ret << '\n';
				resp = max(resp, ret);
			}
		}
		cout << resp << '\n';
	}
	return 0;
}
