#include <bits/stdc++.h>
  
using namespace std;
  
int main()
{
    int n;
      
    int sqt;
    int flag;
      
    while(cin >> n)
    {
        flag = 0;
        if (n < 0) 
        {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i <= (int)sqrt(n) + 1; i++)
        {
            sqt = (int)sqrt(n - i*i);
              
            if (sqt * sqt == n - i * i)
            {
                flag = 1;
                cout << "YES\n";
                break;
            }
        }
        if (!flag) cout << "NO\n";
    }
}
