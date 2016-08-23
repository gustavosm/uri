#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
int fazenda[1000005];
int vis[1000005];

int n;
int atacados;


int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while (cin >> n)
	{
		atacados = 0;
		ll sum = 0;
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> fazenda[i];
			sum += fazenda[i];
			vis[i] = 0;
		}
		
		int i = 0;
		ll ans = 0;
		while (i >= 0 && i < n)
		{
			if (!vis[i]) ++atacados;
			vis[i] = 1;
			if (fazenda[i] & 1)
				++ans, --fazenda[i], ++i;
			else
			{
				if (fazenda[i]) ++ans, --fazenda[i];
				--i;
			}
		}
		
		cout << atacados << ' ' << sum - ans << '\n';
	}
}
