#include <bits/stdc++.h>
  
#define INF 9999999LL
using namespace std;
  
typedef long long ll;
  
inline ll op(ll num, int id)
{
    switch(id)
    {
        case 1:
            return (num << 1);
        case 2:
            return num * 3;
        case 3:
            return (num >> 1);
        case 4:
            return (num / 3);
        case 5:
            return num + 7;
        case 6:
            return num - 7;
    }
    return 0;
}
void bfs(int s, int t)
{
    map<int, ll> dist;
      
    priority_queue<pair<ll, int> , vector<pair<ll, int> >, greater<pair<ll, int> > > q;
    q.push(make_pair(0, s));
      
    while (!q.empty())
    {
        pair<ll, ll> u = q.top(); q.pop();
        if (u.second == t)
        {
            cout << u.first << '\n';
            return;
        }
        ll v = u.second;
        ll mpv = dist[v];
        for (int i = 1; i <= 6; ++i)
        {
            ll vertice = op(v, i);
            ll &ret = dist[vertice];
            if ((ret == 0) || (ret > mpv + 1))
            {
                ret = mpv + 1;
                q.push(make_pair(ret, vertice));
            }
        }
    }
}
  
int main()
{
    ll n, m;
    ios_base :: sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
    
    bfs(n, m);
    
}
