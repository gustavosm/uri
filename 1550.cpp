#include <bits/stdc++.h>

#define MAXN 10005
#define INF 10000000
using namespace std;

vector<vector<int > > v;

int inv(int i)
{
	int aux = 0;
	
	while (i)
	{
		aux *= 10;
		aux += i % 10;
		i /= 10;
	}
	return aux;
}
void init()
{
	v.assign(MAXN, vector< int >());
	
	for (int i = 0 ; i < MAXN; ++i)
	{
		v[i].push_back(i + 1);
		v[i].push_back(inv(i));
	}
}
vector<int> d;

void dijkstra(int source)
{
	d.assign(MAXN, INF);
	d[source] = 0;
	
	priority_queue<pair<int, int> , vector<pair<int, int> > , greater<pair<int, int> > > pq;
	
	pq.push(make_pair(0, source));
	
	while (!pq.empty())
	{
		pair<int, int> u = pq.top(); pq.pop();
		int w = u.second;
		if (w < MAXN)
		{
			for (int i = 0 ; i < v[w].size(); ++i)
			{
				int vx = v[w][i];
				if (vx < MAXN - 1 && d[vx] > u.first + 1)
				{
					d[vx] = u.first + 1;
					pq.push(make_pair(d[vx], vx));
				}
			}
		}
	}
}

int main()
{
	int cases;
	
	int s, t;
	
	init();
	ios_base :: sync_with_stdio(0); cin.tie(0);
	cin >> cases;
	
	while (cases--)
	{
		cin >> s >> t;
		dijkstra(s);
		
		cout << d[t] << '\n';
		d.clear();
	}
	v.clear();
}
