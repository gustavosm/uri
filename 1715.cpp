#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	int m;
	int flag;
	int x;
	int gol;
	
	while(cin >> n >> m)
	{
		gol = 0;
		for (int i = 0 ; i < n ; i++)
		{
			flag = 1;
			for (int j = 0; j < m; j++)
			{
				cin >> x;
				if (!x) flag = 0;
			}
			gol+= flag;
		}
		cout << gol << '\n';
	}
}
