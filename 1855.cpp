#include <bits/stdc++.h>


using namespace std;


string v[106];
int visited[106][106];
int main()
{
	int x, y;
	
	while (cin >> y >> x)
	{
		for (int i = 0 ; i < x; ++i) cin >> v[i];
		int flag = 0;
		int avancai = 0;
		int avancaj = 1;
		int i = 0;
		int j = 0;
		memset(visited, 0, sizeof visited);
		
		while (1)
		{
			if (v[i][j] == '>')
			{
				avancai = 0;
				avancaj = 1;
			}
			if (v[i][j] == '<')
			{
				avancai = 0;
				avancaj = -1;
			}
			if (v[i][j] == 'v')
			{
				avancai = 1;
				avancaj = 0;
			}
			if (v[i][j] == '^')
			{
				avancai = -1;
				avancaj = 0;
			}
			if (v[i][j] == '*')
			{
				cout << "*\n";
				flag = 1;
				break;
			}
			i += avancai;
			j += avancaj;
			if (visited[i][j] || i >= x || j >= y) break;
			visited[i][j] = 1;
		}
		if (!flag) cout << "!\n";
	}
}
