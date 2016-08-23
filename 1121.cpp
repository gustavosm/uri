#include <bits/stdc++.h>

using namespace std;
int main ()
{
	char nm[105][105];
	string instrucao;
	int n;
	int m;
	int k;
	int inst;
	int figurinha;
	int i;
	int j;
	
	while(1)
	{
		cin >> n >> m >> inst;
		if (!n && !m && !inst) return 0;
		getchar();
		for ( i = 0; i < n; i++)
			scanf("%s\n", nm[i]);
		
		getline(cin,instrucao);
		k = 0;
		for ( i = 0 ; i < n; i++)
		{
			for (j = 0 ; j < m; j++)
				if (isalpha(nm[i][j])) break;	
			if (isalpha(nm[i][j])) break;
		}
		figurinha = 0;
		for (k = 0 ; k < inst; k++)
		{
			if (instrucao[k] == 'E')
			{
				if (nm[i][j] == 'N') nm[i][j] = 'O';
				else if (nm[i][j] == 'O') nm[i][j] = 'S';
				else if (nm[i][j] == 'S') nm[i][j] = 'L';
				else if (nm[i][j] == 'L') nm[i][j] = 'N';
			}
			else if (instrucao[k] == 'D')
			{
				if (nm[i][j] == 'N') nm[i][j] = 'L';
				else if (nm[i][j] == 'O') nm[i][j] = 'N';
				else if (nm[i][j] == 'S') nm[i][j] = 'O';
				else if (nm[i][j] == 'L') nm[i][j] = 'S';
			}
			else if (instrucao[k] == 'F')
			{
				if (nm[i][j] == 'N')
				{
					if (i > 0 && nm[i-1][j] != '#')
					{
						if (nm[i-1][j] == '*') figurinha++;
						nm[i-1][j] = 'N';
						i--;
					}
				}
				else if (nm[i][j] == 'O')
				{
					if (j > 0 && nm[i][j-1] != '#')
					{
						if (nm[i][j-1] == '*') figurinha++;
						nm[i][j-1] = 'O';
						j--;
					}
				}
				else if (nm[i][j] == 'S')
				{
					if (i < n - 1 && nm[i+1][j] != '#')
					{
						if (nm[i+1][j] == '*') figurinha++;
						nm[i+1][j] = 'S';
						i++;
					}
				}
				else if (nm[i][j] == 'L')
				{	
					if (j < m - 1 && nm[i][j+1] != '#')
					{
						if (nm[i][j+1] == '*') figurinha++;
						nm[i][j+1] = 'L';
						j++;
					}
				}
			}
		}
		cout << figurinha << '\n';		
	}
}

