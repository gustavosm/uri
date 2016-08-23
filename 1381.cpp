#include<bits/stdc++.h>
  
#define MOD 1300031LL
using namespace std;
typedef long long ll;
ll fat[2000005];
 
void calc()
{
    fat[0] = 1;
    fat[1] = 1;
     
    for (int i = 2; i <= 2000000; ++i)
        fat[i] = ((fat[i - 1] % MOD) * (i % MOD)) % MOD;
}
 
ll mul_inv(ll a, ll b)
{
  //  for (int i = 0; i < MOD; ++i)
     //   if ((a * i) % MOD == 1) return i;
    
    ll b0 = b , t , q ;
    ll x0 = 0 , x1 = 1 ;
    if ( b == 1 ) return 1 ;
    
    while ( a > 1 ) 
    {
        q = a / b;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
        
        t = b;
        b = a % b;
        a = t ;
         
    }
    if ( x1 < 0 ) x1 += b0 ;
    return x1 ;
}
 
int main()
{
	ios_base :: sync_with_stdio(0);

    calc();
     
    ll n, c;
     
    int cases;
    scanf("%d", &cases);
     
    while(cases--)
    {
    	scanf("%lld %lld", &n, &c);
         
        ll ret = mul_inv(fat[n - 1] * fat[c], MOD);
        printf("%lld\n", (fat[n + c - 1] * ret) % MOD);
    }
}
