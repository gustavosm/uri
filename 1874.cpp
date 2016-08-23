#include <bits/stdc++.h>


using namespace std;;


int main()
{
	int m[100][100];
	
	int h, p, f;
	
	int x;
	while (1)
	{
		cin >> h >> p >> f;
		
		if (!h) return 0;
		
		for (int i = 0 ; i < h; ++i)
			for (int j = 0 ; j < p; ++j)
				cin >> m[i][j];
				
		while (f--)
		{
			cin >> x;
			
			int i = 0;
			int j = p - 1;
			
			int flag = 0;
			while (j >= 0 && m[i][j] != 0)
				--j, flag = 1;
			if (flag)
			{
				while (i < h && m[i][j] == 0)
					++i;
				--i;
				m[i][j] = x;
			}
		}
		for (int i = 0 ; i < h; ++i)
		{
			for (int j = 0 ; j < p; ++j)
			{
				if (j) cout << ' ' ;
				cout << m[i][j];
			}
			cout << '\n';
		}
	}
}
