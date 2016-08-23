#include <bits/stdc++.h>

#define INF 999999

using namespace std;
typedef pair<int, int> ii;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

int d[105][105];
vector<string> g;
int n;

int val(int i, int j)
{
	return i >= 0 && i < n && j >= 0 && j < n;
}
int value(char c)
{
	return tolower(c) - 'a';
}

int bfs(int mask)
{
	queue< ii > q;
	int result;
	q.push(make_pair(0, 0));
	ii u;
	for (int i = 0 ; i < n ; ++i) for (int j = 0 ; j < n ; ++j)
		d[i][j] = INF;
		
	d[0][0] = 1;
	
	char c = g[0][0];
	int vl = value(c);
	if (c == tolower(c)) result = (1 << vl);
	else result = 0;
	if ((mask & (1 << vl)) != result) return INF;
	
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		int x = u.first;
		int y = u.second;
		for (int i = 0 ; i < 4; ++i)
		{
			if (val(x + dr[i], y + dc[i]))
			{
				c = g[x + dr[i]][y + dc[i]];
				vl = value(c);
				if (c == tolower(c)) result = (1 << vl);
				else result = 0;
				if ((mask & (1 << vl)) == result)
				{
					if (d[x + dr[i]][y + dc[i]] > d[x][y] + 1)
					{
						d[x + dr[i]][y + dc[i]] = d[x][y] + 1;
						q.push(make_pair(x + dr[i], y + dc[i]));
					}
				}
			}
		}
	}
	return d[n - 1][n - 1];
}

int main()
{
	string s;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	cin >> n;
	
	for (int i = 0 ; i < n; ++i)
	{
		cin >> s;
		g.push_back(s);
	}
	
	int ans = INF;
	for (int i = 0 ; i < (1 << 10); ++i)
	{
		ans = min(ans, bfs(i));
	}

	if (ans != INF)		
		cout << ans << '\n';
	else cout << -1 << '\n';

}
