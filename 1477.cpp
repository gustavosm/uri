#include <bits/stdc++.h>
 
#define ff first
#define ss second
#define pb push_back
#define sz size
 
#define MAXN 100010
 
#define ms(x,v) memset((x), (v), sizeof(x))
 
#define cl_(x) ((x) << 1)
#define cr_(x) (((x) << 1) + 1)
#define _NO_USE_LOG
#ifdef _USE_LOG
#define LOG(x) cout << x;
#else
#define LOG(x)
#endif
 
using namespace std;
 
typedef long long L;
typedef pair<L,L> PL;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef vector<PL> VPL;
typedef vector<VPL>VVPL;
 
#define MAN 0
#define ELEPHANT 1
#define RAT 2
 
class SegTree 
{
private:
    int st[MAXN*8][3];
    int lazy[MAXN*8];
    int n_;
 
 
    inline void add_(int *res, int *inc) {
        for(int i = 0; i < 3; ++i) res[i] += inc[i];
    }
 
    void prop_(int u, int l, int r) {
        if(lazy[u] == 1) {
            swap(st[u][0], st[u][1]); // 0 1 2 -> 1 0 2
            swap(st[u][0], st[u][2]); // 1 0 2 -> 2 0 1
        }
        else if(lazy[u] == 2) {
            swap(st[u][0], st[u][2]); // 0 1 2 -> 2 1 0
            swap(st[u][0], st[u][1]); // 2 1 0 -> 1 2 0
        }
 
        if(lazy[u] && l != r) {
            lazy[cl_(u)] = (lazy[cl_(u)] + lazy[u]) % 3;
            lazy[cr_(u)] = (lazy[cr_(u)] + lazy[u]) % 3;
        }
 
        lazy[u] = 0;
    }
 
    void query_(int u, int l, int r, int i, int j, int *res) {
        prop_(u, l, r);
        if(l > j || r < i) {}
        else if(l >= i && r <= j){
            add_(res, st[u]);
        }
        else{
            query_(cl_(u), l, (l + r)/2, i, j, res);
            query_(cr_(u), (l + r)/2 + 1, r, i, j, res);
        }
    }
 
    void upd_(int u, int l, int r, int i, int j) {
        prop_(u, l, r);
        if(l > j || r < i) {}
        else if(l >= i && r <= j) {
            lazy[u] = 1;
            prop_(u, l, r);
        }
        else {
            upd_(cl_(u), l, (l + r) / 2, i , j);
            upd_(cr_(u), (l + r) / 2 + 1, r, i , j);
            ms(st[u], 0);
            add_(st[u], st[cl_(u)]);
            add_(st[u], st[cr_(u)]);
        }
    }
 
    void build_(int u, int l, int r) {
        lazy[u] = 0;
        ms(st[u], 0);
        if(l == r) {
            st[u][0] = 1;
        }
        else {
            build_(cl_(u), l, (l + r) / 2);
            build_(cr_(u), (l + r) / 2 + 1, r);
            add_(st[u], st[cl_(u)]);
            add_(st[u], st[cr_(u)]);
        }
    }
public:
    void init(int n) {
        n_ = n;
        build_(1, 0, n_);
    }
 
    void update(int l, int r) {
        upd_(1, 0, n_, l, r);
    }
 
    void query(int l, int r, int *res) {
        query_(1, 0, n_, l, r, res);
    }
 
};
 
SegTree st;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    while(cin >> n >> m) {
        st.init(n);
        int queryRes[3];
 
        for(int i = 0; i < m; ++i) {
            char q;
            int a, b;
            cin >> q >> a >> b;
            --a; --b;
 
            if(q == 'C') {
                ms(queryRes, 0);
                st.query(a, b, queryRes);
                cout << queryRes[0] << ' '
                     << queryRes[1] << ' '
                     << queryRes[2] << '\n';
            }
            else {
                st.update(a, b);
            }
        }
        cout << '\n';
    }
}
