#include <bits/stdc++.h>
 
 
using namespace std;
 
int main()
{
    int a, b;
     
    while(cin >> a >> b)
    {
        if (b <= 2) cout << "nova\n";
        else if (b <= 96 && a <= b) cout << "crescente\n";
        else if (3 <= b && b <= 96 && a > b) cout << "minguante\n";
        else if (b <= 100) cout << "cheia\n";
    }
    return 0;
}
