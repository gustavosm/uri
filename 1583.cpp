#include <bits/stdc++.h>


using namespace std;

int dr[] = {1, 0, -1 , 0};
int dc[] = {0, 1, 0,-1};

int R, C;
char grid[55][55];
int floodfill(int r, int c, char c1, char c2)
{
	if ( r < 0 || r >= R || c < 0 || c >= C) return 0;
	
	if (grid[r][c] != c1) return 0;
	int ans = 1;
	grid[r][c] = c2;
	for (int d = 0 ; d < 4; d++)
	{
		ans+= floodfill(r + dr[d], c + dc[d], c1, c2);
	}
	return ans;
}

int main()
{
	char c;
	vector<int> row;
	vector<int> col;
	
	while(1)
	{
		cin >> R >> C;
		
		if (!R && !C) return 0;
		
		getchar();
		
		for (int i = 0 ; i < R; i++)
		{
			for (int j = 0 ; j < C; j++)
			{
				char c = getchar();
				grid[i][j] = c;
				if (c == 'T')
				{
					grid[i][j] = 'A';
					row.push_back(i);
					col.push_back(j);
				}
			}
			getchar();
		}
		
		for (int i = 0 ; i < col.size(); i++)
			floodfill(row[i], col[i], 'A', 'T');
		
		for (int i = 0 ; i < R; i++)
		{
			for (int j = 0 ; j < C; j++)
			{
				cout << grid[i][j];
			}
			cout << '\n';
		}
		col.clear();
		row.clear();
		cout << '\n';
	}
}
