#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;
  
bitset<30000020LL> isprime;
ll prime[30000020LL];
ll lim = 30000010LL;
  
void primo(ll *p) 
{
	ll prime_cont = 0;
	
	prime[prime_cont] = 2;
	prime_cont++;
	
    isprime.set();
    for(ll i=3; i<=lim; i+=2) 
    {
        if(isprime[i]) 
        {
            prime[prime_cont++] = i;
          
            for(ll j = i * i; j <= lim; j+= i) 
                isprime.reset(j);
        }
    }
    
    *p = prime_cont;
    
}
int fatora(ll n, ll prime_cont)
{
    ll i = 0;
    int ans = 1;
    int div;
    while (n > 1 && i < prime_cont)
    {
        div = 0;
        while(n > 1 && n % prime[i] == 0)
        {
            n/= prime[i];
            div++;
        }
        i++;
        if (i > 1) ans*= (div + 1);
    }
    if (n > 1) ans *= 2;
    return ans;
}
  
int main()
{
    ll n;
    ll qtde = 0;
    primo(&qtde);
    
    while(cin >> n)
    {
        if (n == 0) cout << "0\n";
        else
        	cout << fatora(n, qtde) << '\n';
    }
}
