#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

ll n;
vector<int> v1;

ll v[5000];

ll tobin(int i)
{
    ll ans;
    string s;
     
    while(i > 0)
    {
        s.push_back(i % 2 + '0');
         
        i/= 2;
    }
    reverse(s.begin(), s.end());
    ans = 0;
    for (int j = 0 ; j < s.size(); j++)
    {
        ans*= 10;
        ans+= s[j] - '0';
    } 
    return ans;
}
 
int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
    srand(time(NULL));
    
    int flag;
    int i;
     
    for (i = 1; i <= 4096; i++)
    {
        v[i] = tobin(i);
    }
     
     
    while (cin >> n)
    {
    	if (binary_search(v, v + 4096, n))
    		cout << n << '\n';
    	else
    	{
    		ll mn = (1LL << 62);
    		flag = 0;
    		for (int i = 0 ; i < 500; ++i)
    		{
    			int r = rand() % 4096 + 1;
    			if (v[r] % n == 0)
    			{
    				flag = 1 ;
    				mn = min(mn, v[r]);
    			}
    		}
    		if (!flag) cout << -1 << '\n';
    		else cout << mn << '\n';
    	}
    }
}
