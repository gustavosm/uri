	#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef pair<ll, ii > iii;

vector<ll> pset;
ll M;
ll N;

void init()
{
    pset.assign(N, 0);
    for (int i=0; i<N; i++) pset[i]=i;
}
int findSet (int i)
{
    return ((pset[i]==i)?i:pset[i]=findSet(pset[i]));
}
bool isSameSet (int i, int j)
{
    return findSet(i)==findSet(j);
}
void unionSet(int i, int j)
{
    pset[findSet(i)]=findSet(j);
}

int main()
{
	vector<iii > edges;
	ll u;
	ll v;
	ll w;
	ll mincost;
	
	while(1)
	{
		cin >> N >> M;
		if (!N && !M) return 0;
		init();
		
		for (ll i = 0 ; i < M; i++)
		{
			cin >> u >> v >> w;
			
			edges.push_back(make_pair(w, pair<ll, ll>(u, v)));
		}
		sort(edges.begin(), edges.end());
		
		mincost = 0;
		for (ll i = 0 ; i < M; i++)
		{
			iii par = edges[i];
			
			if (!isSameSet(par.second.first, par.second.second))
				unionSet(par.second.first, par.second.second);
			else mincost+= par.first;
		}
		cout << mincost << '\n';
		edges.clear();
		pset.clear();
	}
}
