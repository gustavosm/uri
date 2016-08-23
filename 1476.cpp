#include <bits/stdc++.h>

#define MAXN 20005
#define LOGTWON 15
#define cl(x) ((x) << 1)
#define cr(x) (((x) << 1) + 1)
#define INF 99999999
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

class RMQ{
private:
	int _A[2 * MAXN], SpT[2 * MAXN][2 * LOGTWON];
public :
	void build ( int n , int A[] ) {
		for ( int i = 0 ; i < n ; ++i) { 
			_A[i] = A[i] ; 
			SpT[i][0] = i ; 
		}
		for (int j = 1; (1 << j) <= n; ++j)
		{
			for (int i = 0 ; i + (1 << j) - 1 < n; ++i)
			{
				if (_A[SpT[i][j - 1]] < _A[SpT[i + (1 << (j - 1))][j - 1]])
					SpT[i][j] = SpT[i][j - 1];
				else SpT[i][j] = SpT[i + (1 << (j - 1))][j - 1];
			}
		}
	}
	int query(int i , int j){
		int k = (int)floor(log((double)j - i + 1) / log(2.0));
		if (_A[SpT[i][k]] <= _A[SpT[j - (1 << k) + 1][k]])
			return SpT[i][k];
		else return SpT[j - (1 << k) + 1][k];
	}
};
class LCA{
private:
	RMQ rmq;
	int L[2 * MAXN], E[2 * MAXN], H[MAXN], idx;
	
	void dfs(int cur, int depth, vvi &children)
	{
		H[cur] = idx;
		E[idx] = cur;
		L[idx++] = depth;
		for (int i = 0 ; i < (int)children[cur].size(); ++i)
		{
			dfs(children[cur][i], depth + 1, children);
			E[idx] = cur;
			L[idx++] = depth;
		}
	}
public:
	void build(vvi &children)
	{
		idx = 0;
		memset(H, -1, sizeof H);
		dfs(0, 0, children);
		rmq.build(idx, L);
	}
	int query(int u, int v)
	{
		if (H[v] < H[u]) swap(u, v);
		return E[rmq.query(H[u], H[v])];
	}
};

class HLD{
private:
	LCA lca;
	int chainNo, chainPtr, n;
	int chainHead[MAXN], chainPos[MAXN], chainInd[MAXN];
	int arrBase[MAXN], tree_sz[MAXN], st[4 * MAXN], parent[MAXN];
	
	void build_tree(int x, int l, int r)
	{
		if (l == r) st[x] = arrBase[l];
		else
		{
			build_tree(cl(x), l, (l + r) / 2);
			build_tree(cr(x), (l + r) / 2 + 1, r);
			
			st[x] = min(st[cl(x)], st[cr(x)]);
		}
	}
	
	int query_tree(int x, int l, int r, int i, int j)
	{
		if (j < l || i > r) return INF;
		
		if (l >= i && r <= j) return st[x];
		
		int ans1 = query_tree(cl(x), l, (l + r) / 2, i , j);
		int ans2 = query_tree(cr(x), (l + r) / 2 + 1, r, i , j);
		return min(ans1, ans2);
	}
	
	int query_up(int u, int v)
	{
		if (u == v) return INF;
		
		int uchain, vchain = chainInd[v], ans = INF;
		while (1)
		{
			uchain = chainInd[u];
			if (uchain == vchain)
			{
				if (u == v) break;
				ans = min(ans, query_tree(1, 0, n - 1, chainPos[v] + 1, chainPos[u]));
				break;
			}
			ans = min(ans, query_tree(1, 0, n - 1, chainPos[chainHead[uchain]], chainPos[u]));
			u = parent[chainHead[uchain]];
		}
		return ans;
	}
	
	int dfscnt(int u, vvi &children)
	{
		int v;
		tree_sz[u] = 1;
		
		for (int i = 0 ; i < (int)children[u].size(); ++i)
		{
			v = children[u][i];
			parent[v] = u;
			tree_sz[u] += dfscnt(v, children);
		}
	
		return tree_sz[u];
	}
	
	void hld(int u, int cst, vvi &children, vvi &costs){
		arrBase[chainPtr] = cst;
		if (chainHead[chainNo] == -1) chainHead[chainNo] = u;
		
		chainInd[u] = chainNo; chainPos[u] = chainPtr++;
		
		int ind = n, nc, v;
		
		for (int i = 0; i < (int)children[u].size(); ++i)
		{
			v = children[u][i];
			if (tree_sz[v] > tree_sz[ind]){
				ind = v;
				nc = costs[u][i];
			}
		}
		if (ind == n) return;
		
		hld(ind, nc, children, costs);
		for (int i = 0 ; i < (int)children[u].size(); ++i)
		{
			v = children[u][i];
			if (v != ind)
			{
				++chainNo;
				hld(v, costs[u][i], children, costs);
			}
		}
	}
	
public:
	HLD(){
		lca = LCA();
	}
	
	void build(vvi &children, vvi &costs){
		memset(tree_sz, -1, sizeof tree_sz);
		
		n = children.size();
		dfscnt(0, children);
		
		chainNo = 0;
		memset(chainHead, -1, sizeof chainHead);
		
		chainPtr = 0;
		
		hld(0, INF, children, costs);
		
		lca.build(children);
		build_tree(1, 0, n - 1);
	}
	int query(int u, int v){
	
		int l = lca.query(u, v);
		
		return min(query_up(u, l), query_up(v, l));
	}
};

HLD hld;
vector<pair<int, pair<int, int > > > edges;
vvi g;
vvi custo;
vvi mst;
vi pset;


void init(int n)
{
	pset.assign(n, 0);
	for (int i = 0 ; i < n ; ++i) pset[i] = i;
}

int find(int i)
{
	return (pset[i] == i ? i : pset[i] = find(pset[i]));
}
bool same(int i, int j)
{
	return find(i) == find(j);
}

void une(int i, int j)
{
	pset[find(i)] = find(j);
}

void dfs(int u, int pai)
{	
	for (int i = 0 ; i < g[u].size(); ++i)
	{
		if (g[u][i] != pai)
		{
			mst[u].push_back(g[u][i]);
			dfs(g[u][i], u);
		}
		else custo[u].erase(custo[u].begin() + i);
	}
}

bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b)
{
	return a.first > b.first;
}
int main()
{
	int n, m, s;
	int u, v, w;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while (cin >> n >> m >> s)
	{
		mst.assign(n, vi());
		g.assign(n, vi());
		custo.assign(n, vi());
		edges.clear();
		for (int i = 0 ; i < m ; ++i)
		{
			cin >> u >> v >> w;
			--u; --v;
			edges.push_back(make_pair(w, make_pair(u, v)));
		}
		sort(edges.begin(), edges.end(), cmp);
		init(n);
		
		for (int i = 0 ; i < edges.size(); ++i)
		{
			pair<int, pair<int, int> > u = edges[i];
			
			if (!same(u.second.first, u.second.second))
			{
				une(u.second.first, u.second.second);
				
				g[u.second.first].push_back(u.second.second);
				g[u.second.second].push_back(u.second.first);
				
				custo[u.second.first].push_back(u.first);
				custo[u.second.second].push_back(u.first);
			}
		}
		dfs(0, -1);
		hld = HLD();
		hld.build(mst, custo);
		
		for (int i = 0 ; i < s; ++i)
		{
			cin >> u >> v;
			--u; --v;
			
			cout << hld.query(u, v) << '\n';
		}
	}
}
