#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define getcx getchar_unlocked

inline void inp( ll &n ) 
{
    n = 0;
    ll ch = getcx();
    ll sign = 1;
    while( ch < '0' || ch > '9' )
    {
    	if(ch == '-')
    		sign = -1; 
    	ch = getcx();
    }
    while(  ch > 47 && ch < 58 )
            n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
    n = n * sign;
}

int main()
{
	ios :: sync_with_stdio(0);
	
    ll n;
    ll res;
    int ans;
    while(1)
    {
    	inp(n);
        ans = 0;
        ll x;
        if (!n) return 0;
        int i = 0;
        while(i < n)
        {
        	inp(x);
        	res = (ll)sqrt(x);
        	if (res * res == x) ++ans;
        	else ans += 2;
        	++i;
        }
        
        if (ans & 1) cout << "Annie\n";
        else  cout << "Garen\n";
    }
}
