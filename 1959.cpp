#include <bits/stdc++.h>


using namespace std;

#define getcx getchar_unlocked

typedef long long ll;

inline int inp( ll &n ) 
{
    n = 0;
    ll ch = getcx();
    if (ch == -1) return 0;
    
    while (ch < '0' || ch > '9') ch = getcx();
    
    while(  ch >= '0' && ch <= '9' )
            n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
    return 1;
}

int main()
{
	ll n, p;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while (inp(n) && inp(p))
	{
		cout << n * p << '\n';
	}
}
	
