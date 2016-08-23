#include<bits/stdc++.h>

#define INF 999999
using namespace std;

typedef long long ll;

int dist[4005][26];

int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	vector<vector<pair<int, string> > > adj;
	ll n;
	string origem, destino;
	map<string, int> m;
	int marcaVertice;
	int i;
	string s1, s2, s3;
	
	while(1){
		
		cin >> n;
		if(!n)
			break;
			
		marcaVertice = 1;
		cin >> origem >> destino;
		
		m[origem] = 1;
		m[destino] = 2;
		marcaVertice = 3;
		
		adj.assign((2 * n + 10), vector<pair<int, string> > ());
			
		for(i=0; i<n; i++){
			cin >> s1 >> s2>> s3;
			int x, y;
			if(!m.count(s1)){
				m[s1] = marcaVertice;
				x = marcaVertice;
				marcaVertice++;
			}
			else x = m[s1];
			if(!m.count(s2)){
				m[s2] = marcaVertice;
				y = marcaVertice;
				marcaVertice++;
			}else y = m[s2];
			
			adj[x].push_back(make_pair(y, s3));
			adj[y].push_back(make_pair(x, s3));
		}
		
		for (int i = 0 ; i < 4005; ++i) for (int j = 0 ; j < 26; ++j)
			dist[i][j] = INF;
			
		for (int i = 0 ; i < 26; ++i)
			dist[1][i] = 0;
			
		priority_queue< pair<int, pair<int, char> >, vector<pair<int, pair<int, char> > >, greater<pair<int, pair<int, char> > > > pq;
		pq.push(make_pair(0, make_pair(1, 'a')));
		
		while(!pq.empty()){
			pair<int, pair<int, char> > front = pq.top();
			pq.pop();
			int d = front.first;
			int v = front.second.first;
			char cx = front.second.second;
			for (int i = 0 ; i < adj[v].size(); ++i)
			{
				char c = adj[v][i].second[0];
				if (v != 1 && c == cx) continue;
				
				if (dist[adj[v][i].first][c - 'a'] >= dist[v][cx - 'a'] + adj[v][i].second.size())
				{	
					dist[adj[v][i].first][c - 'a'] = dist[v][cx - 'a'] + adj[v][i].second.size();
					pq.push(make_pair(dist[adj[v][i].first][c - 'a'], make_pair(adj[v][i].first, c)));
				}
			}
		}
		int mn = INF;
		for (int i = 0 ; i < 26; ++i)
			mn = min(mn, dist[2][i]);
			
		if (mn == INF) cout << "impossivel\n";
		else cout << mn << '\n';

		m.clear();
		adj.clear();
	}
}		
