#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

set<ll> colocacao;

int main()
{
	ll c[4];
	ll n, m;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while (cin >> n >> m)
	{
		for (int i = 0 ; i  < n ; ++i)
			cin >> c[i];
		
		colocacao.clear();
		int flag = 0;
		
		if (n > 1)
		{
			for (int i = 1 ; i <= m ; ++i)
			{
				for (int j = 1; j <= m ; ++j)
				{
					if (n == 3)
					{
						for (int k = 1; k <= m; ++k)
						{
							int pont = c[0] * i + c[1] * j + c[2] * k;
							if (colocacao.find(pont) != colocacao.end())
							{
								flag = 1;
								break;
							}
							colocacao.insert(pont);
						}
						if (flag) break;
					}
					else
					{
						int pont = c[0] * i + c[1] * j;
						if (colocacao.find(pont) != colocacao.end())
						{
							flag = 1;
							break;
						}
						colocacao.insert(pont);
					}
				}
				if (flag) break;
			}
			if (flag) cout << "Try again later, Denis...\n";
			else cout << "Lucky Denis!\n";
		}
		else cout << "Lucky Denis!\n";

	}
}
