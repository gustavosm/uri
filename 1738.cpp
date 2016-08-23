#include <bits/stdc++.h>

#define inf 12345690
using namespace std;
int fw[201][201][26];
int n;

void floydwarshall()
{
	for (int k = 0 ; k < n ; k++)
	{
		for (int i = 0 ; i < n ; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int l = 0 ; l < 26; l++)
					fw[i][j][l] = min(fw[i][j][l], fw[i][k][l] + fw[k][j][l]);
			}
		}
	}
}

int main()
{
	int u;
	int v;
	int flag;
	
	string s;
	
	while (1)
	{
		cin >> n;
		if (!n) return 0;
		
		for (int i = 0 ; i < n ; i++)
		{
			for (int j = 0 ; j < n; j++)
			{
				for (int k = 0 ; k < 26; k++)
					fw[i][j][k] = inf;
			}
		}
		
		while(1)
		{
			cin >> u >> v;
			if (!u && !v) break;
			cin >> s;
			--u;
			--v;
			for (int i = 0 ; i < s.size(); i++)
				fw[u][v][s[i] - 'a'] = 1;
		}
		
		floydwarshall();
		
		while(1)
		{
			cin >> u >> v;
			if (!u && !v) break;
			
			--u;
			--v;
			flag = 0;
			for (int i = 0 ; i < 26 ; i++)
			{
				if (fw[u][v][i] != inf) 
				{
					cout << (char)(i+'a');
					flag = 1;
				}
			}
			if (!flag) cout << '-';
			cout << '\n';
		}
		cout << '\n';
	}
}
