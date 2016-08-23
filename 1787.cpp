#include <bits/stdc++.h>

using namespace std;

int potenciade2(int x)
{
	if (x == 1) return 1;
	else return !(x & (x - 1));
}
int main ()
{
	int n;
	int u;
	int r;
	int in;
	int su;
	int sr;
	int sin;

	while(1)
	{
		cin >> n;
		if (!n) return 0;
		su = sr = sin = 0;
		while(n--)
		{
			cin >> u >> r >> in;
			if (potenciade2(u))
			{
				su++;
				if (u == max(max(r,in),u)) su++;
			}
			if (potenciade2(r))
			{
				sr++;
				if (r == max(max(r,in),u)) sr++;
			}
			
			if (potenciade2(in))
			{
				sin++;
				if (in == max(max(r,in),u)) sin++;
			}
		}
		if (su > sr && su > sin) cout << "Uilton\n";
		else
		{
			if (sr > su && sr > sin) cout << "Rita\n";
			else
			{
				if (sin > su && sin > sr) cout << "Ingred\n";
				else cout << "URI\n";
			}
		}
	}
}
