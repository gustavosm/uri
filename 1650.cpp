#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    ll m;
    ll aux;
    ll ans;
    int branco;
     
    while(1)
    {
        cin >> n >> m >> branco;
        if (!n && !m && !branco) return 0;
         
        if (n == 8 && m == 8 && branco == 0) 
        {
            cout << "0\n";
            continue;
        }
        ans = 0;
        for (int i = 0 ; i + 8 <= n ; i++)
        {
            branco^= 1;
            ans+= (m - 8 - branco + 1) / 2 + (m - 8 - branco + 1) % 2;
        }
        cout << ans << '\n';
         
    }
}
