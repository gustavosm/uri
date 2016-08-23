#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;
typedef vector<int> vi;
typedef vector<vi > vvi;
typedef pair<int, int> ii;

int idade[505];
vvi v;
vi dist;
int n, m, q;
int s, d;
char c;

int main()
{	
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	dist.reserve(505);
	
	while(scanf("%d %d %d", &n, &m, &q) != EOF)
	{
		for (int i = 0 ; i < n ;i++)
		{
			scanf("%d", &idade[i]);
		}
		
		v.assign(n, vi());
		
		for (int i = 0 ; i < m; i++)
		{
			scanf("%d %d", &s, &d);
			
			--s; --d;
			v[d].push_back(s);			
		}
		for (int i = 0 ; i < q; i++)
		{
			getchar();
			scanf("%c %d", &c, &s);
			--s;
			
			if (c == 'P')
			{
				queue<int> q;
				dist.clear();
				for (int i = 0 ; i < n ; i++) dist[i] = INF;
				dist[s] = 0;
				q.push(s);
				int mn = INF;
				
				while (!q.empty())
				{
					int u = q.front();
					q.pop();
					for (int i = 0 ; i < v[u].size(); i++)
					{
						int aux = v[u][i];
						if (dist[aux] > dist[u] + 1)
						{
							dist[aux] = dist[u] + 1;
							mn = min(mn, idade[aux]);
							q.push(aux);
						}
					}
					
				}
				if (mn == INF) printf("*\n");
				else printf("%d\n", mn);				
			}
			else
			{
				scanf("%d", &d);
				--d;
				
				for (int i = 0 ; i < n; i++)
				{					
					for (int j = 0; j < v[i].size(); j++)
					{
						if (v[i][j] == s)
							v[i][j] = d;
						else if (v[i][j] == d)
							v[i][j] = s;
					}
				}
				vi aux = v[s];
				v[s] = v[d];
				v[d] = aux;
			}
		}
		v.clear();
	}
	
}
