/*#include <bits/stdc++.h>
  
  
using namespace std;
  
  
int main()
{
    int a, b;
      
    while (cin >> a >> b)
    {
        int q = 0;int r;
        int aux = a;
        if (a < 0 && b > 0)
        {
            while (a < 0)
            {
                a += b;
                --q;
            }
            r = a;
        }
        else if (a < 0 && b < 0)
        {
            while (a < 0)
            {
                a -= b;
                ++q;
            }
            r = a;
              
        }
        else if (a > 0 && b < 0)
        {
            while (1)
            {
                if (a + b < 0) break;
                a += b;
                --q;
            }
            r = a;
        }
        else
        {
            q = a / b;  
            r = aux - b * q;
        }
        cout << q << ' ' << r << '\n';
    }
}*/


#include <bits/stdc++.h>


using namespace std;


int main()
{
	int a, b;
	
	while (cin >> a >> b)
	{
		int sign_a = (a < 0 ? -1 : 1);
		int sign_b = (b < 0 ? -1 : 1);
		
		int q = a / (abs(b)) * sign_b;
		int resto = a % (abs(b)) * sign_b;
		
		cout << q << ' ' << resto << '\n';
	}
}
