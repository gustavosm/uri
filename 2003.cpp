#include <bits/stdc++.h>


using namespace std;


int main()
{
	
	char a, b;
	int c;
	
	while (cin >> a >> b >> c)
	{
		int a1 = a - '0';
	
		int resto = (c + 60) / 60;
		c = (c + 60) % 60;
		a1 += resto;
	
		if (a1 < 8)
			cout << "Atraso maximo: 0\n";
		else
		{
			a1 -= 8;
			c += a1 * 60;
			cout << "Atraso maximo: " << c << "\n";		
		}
	}
}
