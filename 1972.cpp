#include <bits/stdc++.h>


#define INF 9999999

using namespace std;


string g[505];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int n, m;
int val(int i, int j)
{
	return i >= 0 && i < n && j >= 0 && j < m;
}
void dijkstra(int x, int y)
{
	vector<int> dist(n * m, INF);
	
	
}
