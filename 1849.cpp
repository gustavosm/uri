#include <bits/stdc++.h>


using namespace std;


int main()
{
	int a, b, c, d;
	
	while (cin >> a >> b >> c >> d)
	{
		int e = min(a, b);
		int f = min(c, d);
		
		e += f;
		int g = min(max(a, b), max(c, d));
		
		int h = min(e, g);
		
		cout << h * h << '\n';
	}
}
