#include <bits/stdc++.h>

#define inf 10000000

using namespace std;

typedef pair<double,int> ii;

int n;
vector<double> D;
vector<vector<ii > > G;

void dijkstra(int source, int dest)
{
	priority_queue <ii, vector<ii >, greater<ii > > Q;
	
	D[source] = 1.0;
	
	Q.push(ii(1.0,source));
	
	while(!Q.empty()) 
	{
		ii top = Q.top();
		Q.pop();
		
		int v = top.second;
		double d = top.first;
		if(d <= D[v]) 
		{
			for (vector<ii > :: iterator it = G[v].begin(); it != G[v].end(); it++)
			{
				int v2 = it->second;
				double cost = it->first;
				if(D[v2] < D[v] * cost) 
				{
					D[v2] = D[v] * cost;
					Q.push(ii(D[v2], v2));
				}
			}
		}
	}
}

int main ()
{
	int m;
	int u, v, w;
	while(1)
	{
		cin >> n;
		if (!n) return 0;
		
		cin >> m;
		
		D.assign(n,-1);
		G.assign(n,vector<ii>());
		while(m--)
		{
			cin >> u >> v >> w;
			G[u - 1].push_back(ii((double)w/100, v - 1));
			G[v - 1].push_back(ii((double)w/100, u - 1));
			
		}
		
		dijkstra(0,n - 1);
			
		printf("%lf percent\n", D[n - 1]*100);
		
		D.clear();
		G.clear();
	}
}
