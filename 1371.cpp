#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	
	int cont;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while(1)
	{
		cin >> n;
		if (!n) return 0;
		
		cont = 1;
		for (int i = 1; i * i <= n ; ++i)
		{
			if (i == 1) cout << i * i;
			else cout << ' ' << i * i;
		}
		cout << '\n';
	}
}
