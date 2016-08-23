#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll d[100005];

int main ()
{
    ll a, c, v, t;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    while (cin >> a, a)
    {
        for (c = 0; c < a; ++c)
          cin >> d[c];
          
        t = 0;
        for (c = 1; c < a; ++c)
        {
            if (d[c - 1] < 0)
                t= t + -1 * d[c - 1];
            else
                t += d[c - 1];
                
            d[c] += d[c - 1];
        }
        cout << t << '\n';
    }
}
