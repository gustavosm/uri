#include <bits/stdc++.h>

using namespace std;
int main()
{
	long long x;
	long long y;
	long long ans;
	int cases;
	
	cin >> cases;
	while(cases--)
	{
		cin >> x >> y;
		
		if (y > x) 
			cout << "2\n";
		else
			cout << x/y + (x % y == 0? 0 : 1 ) << '\n';
	}
}
