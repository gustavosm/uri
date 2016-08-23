#include <bits/stdc++.h>

using namespace std;
int main ()
{
	int ans[55][105];
	int n;
	int m;
	int dano;
	int peso;
	int res;
	
	int cases;
	cin >> cases;
	while(cases--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			ans[i][0] = 0;
		for (int i = 0 ; i <= 100; i++)
			ans[0][i] = 0;
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> dano >> peso;
			for (int j = 1 ; j <= 101; j++)
			{
				if (j < peso) ans[i][j] = ans[i - 1][j];
				else
					ans[i][j] = max(ans[i-1][j], ans[i - 1][j - peso] + dano);
			}
		}
		cin >> m >> res;
		if (ans[n][m] >= res) cout << "Missao completada com sucesso\n";
		else cout << "Falha na missao\n";
	}
}
