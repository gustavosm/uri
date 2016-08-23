#include <bits/stdc++.h>


using namespace std;

set<int> s;


int main()
{
	int n;
	int v[205][205];
	int x, y;
	
	while (cin >> n)
	{
		s.clear();
		for (int i = 0 ; i < n ; ++i) for (int j = 0 ; j < n ; ++j)
			cin >> v[i][j];
			
		n *= 2;
		
		while (n--)
		{
			cin >> x >> y;
			--x,--y;
			s.insert(v[x][y]);
		}
		cout << s.size() << '\n';
	}
}
