#include <bits/stdc++.h>

using namespace std;

int main()
{
	int m[105][105];
	
	int n;
	int pl = 0;
	
	while(cin >> n)
	{
		if (pl) cout << '\n';
		pl = 1;
		for (int i = 0 ; i < n ; i++)
		{
			for (int j = 0 ; j < n ; j++)
			{
				if (i == j) m[i][j] = 2;
				else if (i + j == n - 1) m[i][j] = 3;
				else m[i][j] = 0;
			}
		}
		
		int diff = n / 3;
		
		for (int i = diff; i < n - diff; i++)
		{
			for (int j = diff; j < n - diff; j++)
			{
				m[i][j] = 1;
			}
		}
		
		m[n / 2][n / 2] = 4;
		
		for (int i = 0 ; i < n ; i++)
		{
			for (int j = 0 ; j < n ; j++)
			{
				cout << m[i][j];
			}
			cout << '\n';
		}
		
	}
}
