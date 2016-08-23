#include <bits/stdc++.h>
 
 
using namespace std;
 
 
int main()
{
    int cases;
     
    int n;
    double d, price;
     
    cin >> cases;
     
    while (cases--)
    {
        cin >> d >> n;
         
        double maior = -1.0;
        for (int i = 0 ; i < n ; ++i)
        {
            cin >> price;
            int qtde = 0;
             
            while (price * qtde <= d) ++qtde;
            --qtde;
             
            double x = d - qtde * price;
            if (x > maior && qtde >= 1)
                maior = x;
        }
         
        cout << setprecision(2) << fixed << maior << '\n';
    }
}
