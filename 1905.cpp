#include <bits/stdc++.h>


using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};


vector<int> visited;

int m[6][6];
int val(int i, int j)
{
	return i >= 0 && i < 5 && j >= 0 && j < 5;
}	
void dfs(int i, int j)
{
	if (m[i][j]) return;
	if (!val(i, j)) return;
	if (visited[5 * i + j]) return;
	visited[5 * i + j] = 1;
	for (int l = 0 ; l < 4; ++l)
	{
		dfs(i + dir[l][0], j + dir[l][1]);
	}
}
int main()
{
	int tc;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	cin >> tc;
	
	while (tc--)
	{
		for (int i = 0 ; i < 5; ++i) for (int j = 0 ; j < 5; ++j) cin >> m[i][j];
		
		visited.assign(26, 0);
		
		dfs(0,0);
		
		if (visited[24]) cout << "COPS\n";
		else cout << "ROBBERS\n";
	}
}
