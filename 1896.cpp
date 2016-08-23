#include <bits/stdc++.h>


using namespace std;
typedef long long ll;


struct carta
{
	int a, d, h;
	
	carta(){a = d = h = 0;}
	carta(int i, int j, int k) : a(i), d(j), h(k){}
	
	bool operator == (const carta &other) const
	{
		return a == other.a && d == other.d && h == other.h;
	}
};

carta v[25];

int main()
{
	int n, a, d, h;
	
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	carta prassodia;
	
	while (cin >> n)
	{
		cin >> a >> d >> h;
		prassodia = carta(a, d, h);
		
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> a >> d >> h;
			v[i] = carta(a, d, h);
		}
		
		ll lim = (1L << n);
		int flag = 0;
		for (ll i = 3; i < lim; ++i)
		{
			if (!(i & (i - 1))) continue;
			a = d = h = 0;
			for (int j = 0 ; j < n ; ++j)
			{
				if (i & (1L << j))
				{
					a += v[j].a;
					d += v[j].d;
					h += v[j].h;
				}
			}
			
			carta aux = carta(a, d, h);
			if (aux == prassodia)
			{
				flag = 1;
				break;
			}
		}
		if (flag) cout << "Y\n";
		else cout << "N\n";
	}
}
