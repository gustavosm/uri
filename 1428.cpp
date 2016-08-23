#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	int m;
	
	int cases;
	
	cin >> cases;
	while(cases--)
	{
		cin >> n >> m;
		cout << (n/3) * (m/3) << '\n';
	}
	return 0;
}
