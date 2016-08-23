#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int ans;
     
    int metros;
    int zero;
    int x;
    int um;
    int n;
    vector<int> v;
     
    while(1)
    {
        cin >> n;
        if (!n) return 0;
        um = -1;
        
        ans = 0;
        for (int i = 0 ; i < n ; i++)
        {
            cin >> x;
            v.push_back(x);
            if (x == 1) um = i;
        }
        if (um == -1)
        	cout << n % 2 + n / 2 << '\n';
        else
        {
        	zero = 0;
        	for (int i = um + 1, j = 0; j < n; i++, j++)
        	{
        		i%= n;
        		if (v[i] == 0)
        		{
        			zero++;
        		}
        		else zero = 0;
        		if (zero == 2)
        		{
        			ans++;
        			zero = 0;
        		}
        	}	
        	cout << ans << '\n';
        }
        v.clear();
    }
}
