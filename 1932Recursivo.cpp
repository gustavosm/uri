#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

const int N = 200005;
ll val[N];
ll dp[N][2];
int n;
int C;
ll calc(int dia, int tem) 
{
    
    if (dia == n) 
        return 0;
    
    
    ll& ans = dp[dia][tem];
    
    if (ans == -1) 
    {
        if (tem) 
            ans = max(calc(dia + 1, 1), val[dia] + calc(dia + 1, 0));
        else 
            ans = max(calc(dia + 1, 0), -(val[dia] + C) + calc(dia + 1, 1));
        
    }
    return ans;
}
int main() 
{
    cin >> n >> C;
   
    for (int i = 0; i < n; ++i) 
         cin >> val[i];
     
     
    memset(dp, -1, sizeof dp);
   
    cout << max(calc(0, 0), -(val[0] + C) + calc(0, 1)) << '\n';
   
    return 0;
}
