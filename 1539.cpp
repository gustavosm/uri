#include <bits/stdc++.h>

#define INF 123112512.00
#define EPS 1e-9
using namespace std;

struct point{
	int x, y, r;
	
	point() {x = y = r = 0;}
	point(int _x, int _y, int _r) : x(_x), y(_y), r(_r){}
	
};
int n;
double dt[105];
vector<vector<pair<double, int> > > pontos;
double dist(point &a, point &b)
{
	return (hypot(a.x - b.x, a.y - b.y));
}

void dijkstra(int s)
{
	for (int i = 0 ; i < n ; ++i) dt[i] = INF;
	
	dt[s] = 0;
	priority_queue<pair<double, int>, vector<pair<double, int> > , greater<pair<double, int> > > q;
	q.push(make_pair(0., s));
	
	while (!q.empty())
	{
		pair<double, int> u = q.top(); q.pop();
		
		int v = u.second;
		
		if (u.first - dt[v] > EPS) continue;
		
		for (int i = 0 ; i < pontos[v].size(); ++i)
		{
			int v2 = pontos[v][i].second;
			if (dt[v2] - (dt[v] + pontos[v][i].first) > EPS)
			{
				dt[v2] = dt[v] + pontos[v][i].first;
				q.push(make_pair(dt[v2], v2));
			}
		}
	}
}
int main()
{
	ios_base :: sync_with_stdio(0);
	
	point input[105];
	int u, v , w;
	int idx1, idx2;
	int queries;
	int linha = 1;
	while (1)
	{
		scanf("%d", &n);
		if (!n) return 0;
		
		pontos.clear();
		pontos.assign(n, vector<pair<double, int> > ());
		for (int i = 0 ; i < n ; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			input[i] = (point(u, v, w));
		}
		for (int i = 0 ; i < n ; ++i)
		{
			for (int j = 0 ; j < n; ++j)
			{
				double d = dist(input[i], input[j]);
				if (input[i].r - d > EPS)
					pontos[i].push_back(make_pair(d, j));
			}
		}
		scanf("%d", &queries);
		while (queries--)
		{
			scanf("%d %d", &idx1, &idx2);
			--idx1, --idx2;
			
			dijkstra(idx1);
			
			if (fabs(dt[idx2] - INF) < EPS)
				printf("-1\n");
			else printf("%d\n", (int)(dt[idx2]));
		}
	}
}
