#include <bits/stdc++.h>

using namespace std;
int main ()
{
	char table[120][120];
	char search[120];
	int n;
	int m;
	int auxl;
	int cases;
	int testes;
	int k;
	int l;
	int t1;
	int t2;
	int ans;
	int j;
	
	cin >> cases;
	while (cases--)
	{
		cin >> n >> m;
		getchar();
		for (int i = 0 ; i < n; ++i)
		{
			scanf("%[^\n]\n", table[i]);
		}
		for (int i = 0; i < m; ++i)
		{
			for (j = 0 ; j < n; ++j)
			{
				table[n+i][j] = table[j][i];
			}
			table[n+i][j] = '\0';
		}
		cin >> testes;
		while (testes--)
		{
			scanf("\n%[^\n]", search);
			ans = 0;
			for (int i = 0; i < n+m; ++i)
			{
				l = 0;
				t1 = strlen(search);
				t2 = strlen(table[i]);
				while (l < t2)
				{
					k = 0;
					if (search[k] == table[i][l])
					{
						auxl = l;
						while (k < t1 && l < t2 && search[k] == table[i][l])
						{
							++k;
							++l;
						}
						if (k == t1)
							ans++;
						l = auxl;
					}
					++l;
				}				
			}
			if (t1 == 1) ans/=2;
			cout << ans << '\n';
		}
			
	}
	
	return 0;
}
