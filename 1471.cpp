#include <bits/stdc++.h>

#define pb push_back

using namespace std;
int main ()
{
	int foram;
	int voltaram;
	int p;
	map<int, int> m;
	while (cin >> foram >> voltaram)
	{
		for (int i = 0 ; i < voltaram ; i++)
		{
			cin >> p;
			if (foram != voltaram)
				m[p]++;
		}
		if (foram == voltaram) cout << "*\n";
		else
		{
			for (int i = 1; i <= foram ; i++)
			{
				if (!m[i])
					cout << i << " ";
			}
			cout << '\n';
			m.clear();
		}
	}
}
