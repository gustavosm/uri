#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 40101;
int c, p, SCC;
vector< vector<int> > adj, adj_inv;
vector< int > visitado, top, componente;
int used[N];

int sim(int a){ return a; } 
int nao(int a){ return sim(a) + p; }
 
void addedge(int a, int b){
	adj[a].push_back(b);
	adj_inv[b].push_back(a);
}
 
void dfs1(int u){
	if(visitado[u]) return;
	visitado[u] = 1;
 
	for(int i=0; i<adj[u].size(); i++){
		dfs1(adj[u][i]);
	}
	top.push_back(u);
 
}
 
void dfs2(int u){
	if(visitado[u]) return;
	visitado[u] = 1;
	componente[u] = SCC;
	for(int i=0; i<adj_inv[u].size(); i++){
		dfs2(adj_inv[u][i]);
	}
}
 
void print(){
	for(int i=0; i<=nao(p); i++){
		printf("%d-->  ", i);
		for(int j=0; j<adj[i].size(); j++){
			printf(" %d,", adj[i][j]);
		}
		cout << endl;
	}
}
 
int main(){
	while(cin >> c >> p, c, p){
		memset(used, 0, sizeof used);
		int a, b, aa, bb;
		adj.resize(N);
		adj_inv.resize(N);
		for(int i=0; i<c; i++){
			cin >> a >> b >> aa >> bb;
			used[a] = used[b] = used[aa] = used[bb] = used[nao(a)] = used[nao(b)] = used[nao(bb)] = used[nao(aa)] = 1;
			if(a==0 || b==0){
				if(a==0 && b==0);
				else{
					if(!a) addedge(nao(b), sim(b));
					if(!b) addedge(nao(a), sim(a));
				}
			}else {
				addedge(nao(a), sim(b));
				addedge(nao(b), sim(a));
			}
			if(aa==0 || bb==0){
				if(aa==0 && bb==0);
				else{
					if(!aa) addedge(sim(bb), nao(bb));
					if(!bb) addedge(sim(aa), nao(aa));
				}
			}else {
				addedge(sim(aa), nao(bb));
				addedge(sim(bb), nao(aa));
			}
		}
		//print();
		visitado.assign(N, 0);
		for(int i=2; i<=nao(p); i++){
			if(used[i] && !visitado[i]){
				dfs1(i);
			}
		}
		SCC = 0;
		visitado.assign(N, 0);
		componente.resize(N);
		for(int i=top.size()-1; i>=0; i--){
			if(!visitado[top[i]]){
				dfs2(top[i]);
				SCC++;
			}
		}
		bool T=true;
		for(int i=1; i<=p && T; i++){
			if (used[i])
				if(componente[sim(i)] == componente[nao(i)]) T=false;
		}
		if(T) printf("yes\n");else printf("no\n");
		adj.clear(); adj_inv.clear(); componente.clear();
	}
}
