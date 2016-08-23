#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< ii > vii;
  
const int N = 1000011;
  
int p[N];
int prime_cont;

#define getcx getchar_unlocked
  
bitset<15486045> isp;
  
unordered_map<int,int>v;
 
inline void inp( int &n ) 
{
    n = 0;
    ll ch = getcx();
    while(  ch >= '0' && ch <= '9' )
            n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
}
void calc()
{
    isp.set();
    p[0] = 1;
    p[1] = 2;
    prime_cont = 2;
    for (ll i = 4; i <=15486043; i+= 2) isp.reset(i);
    ll i;
    for(i=3;prime_cont < N && i <=15486043;i+=2)
    {
        if( isp[i] )
        {
            p[prime_cont++] = i;
       
            for(ll j=i*i;j<=15486043;j+=i) isp.reset(j);
        }
    }
}
int main()
{    
    int cases;
    int x;
    
    int n;
    int flag;
    prime_cont = 0;
    
    ios_base :: sync_with_stdio(0); cin.tie(0);
    
    calc();
    
    cin >> cases;
      
    for (int c = 1; c <= cases; ++c)
    {
    	cin >> n;
    	v.clear();
        for (int i = 0 ; i < n ; ++i)
        {
        	cin >> x;
            v[x] = 1;
        }
        
        for (int i = 0 ; i < prime_cont; ++i)
        {
    		if (!v[p[i]])
        	{
        		cout << (p[i] - 1) << '\n';
        		break;
        	}
        }
    }
}
