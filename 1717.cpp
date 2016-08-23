#include <bits/stdc++.h>
 
 
using namespace std;
 
int n;
vector<pair<double, double> > v;
double dp[206][206];
double d[206][206];
int usei[206][206];
 
 
double dist(int i, int j)
{
    return hypot((v[i].first - v[j].first), (v[i].second - v[j].second));
}
double calc(int v1, int v2)
{
    if (v2 - v1 <= 3) return 0.00;
     
    double &ans = dp[v1][v2];
    if (!usei[v1][v2])
    {
        usei[v1][v2] = 1;
        double ret = 1e+30;
         
        for (int i = v1 + 1; i < v2; i += 2)
        {
            for (int j = i + 1; j < v2; j += 2)
            {
                ret = min(ret, calc(v1, i) + calc(i, j) + calc(j, v2) + d[v1][i] + d[i][j] + d[j][v2]);
            }
        }
         
        ans = ret;
    }
    return ans;
}
int main()
{
    double x, y;    
    cout.precision(4);
     
    while (cin >> n)
    {
        n *= 2;
         
        for (int i = 0 ; i < n ; ++i)
        {
            cin >> x >> y;
             
            v.push_back(make_pair(x, y));
        }
        for (int i = 0 ; i < n; ++i)
        {
            for (int j = 0 ; j < n ; ++j)
            {
                d[i][j] = dist(i, j);
                dp[i][j] = -1.0;
                usei[i][j] = 0;
                 
            }
            d[i][i + 1] = 0.0;
        }
         
         
        cout << fixed << calc(0, n - 1) << '\n';
    }
}
