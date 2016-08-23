#include <bits/stdc++.h>


using namespace std;


int main()
{
	string a, b, c, d;
	
	
	int cases;
	
	cin >> cases;
	
	while (cases--)
	{
		int x, y;
		
		cin >> a >> b >> c >> d;
		
		cin >> x >> y;
		
		x += y;
		
		if (x & 1)
		{
			if (b == "PAR") cout << c << '\n';
			else cout << a << '\n';	
		}
		else 
		{
			if (b == "PAR") cout << a << '\n'; 
			else cout << c << '\n';
		}
	}
}
