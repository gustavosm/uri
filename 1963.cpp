#include <bits/stdc++.h>



using namespace std;


int main()
{
	double a, b;
	
	ios :: sync_with_stdio(0); cin.tie(0);
	
	cout.precision(2);
	while (cin >> a >> b)
	{
		b -= a;
		
		cout << fixed << (b * 100.00) / a << "%" << '\n';
	}
}
