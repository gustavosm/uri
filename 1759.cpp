#include <iostream>
  
using namespace std;
  
int main() {
  
    int i;
    while (cin >> i)
    {
        while (i--)
        {
            if (i >= 1) cout << "Ho ";
            else cout << "Ho!\n";
        }
    }
  
    return 0;
}
