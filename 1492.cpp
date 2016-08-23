#include <bits/stdc++.h>
 
 
using namespace std;
 
typedef unsigned long long ll;
 
 
ll dp[60][2][2][60];
 
int qtde_bits;
string rep;
 
ll calc(int pos, int menor, int comeco, int sum)
{
    if (pos == qtde_bits) return sum;
     
    ll &ans = dp[pos][menor][comeco][sum];
     
    if (ans == -1)
    {
        ans = 0;
        int limite = (menor ? 1 : rep[pos] - '0');
        if (comeco)
        {
            for (int i = 1; i <= limite; ++i)
                ans += calc(pos + 1, menor, 0, sum + (1 == i));
            ans += calc(pos + 1, 1, 1, 0);
        }
        else
        {
            for (int i = 0 ; i <= limite; ++i)
                ans += calc(pos + 1, menor || (i < limite), 0, sum + (1 == i));
        }
    }
    return ans;
}
 
void tobin(ll a)
{
    rep.clear();
    while (a)
    {
        rep.push_back((a & 1) + '0');
        a >>= 1;
    }
    reverse(rep.begin(), rep.end());
}
ll ans(ll a, ll b)
{
    tobin(a - 1);
    qtde_bits = rep.size();
     
    memset(dp, -1, sizeof dp);
    ll ans1 = calc(0, 0, 1, 0);
     
    tobin(b);
    qtde_bits = rep.size();
     
    memset(dp, -1, sizeof dp);
    ll ans2 = calc(0, 0, 1, 0);
     
    return ans2 - ans1; 
}
 
int main()
{
    ll a, b;
     
    while (cin >> a >> b)
    {
        cout << ans(a, b) << '\n';
    }
}
