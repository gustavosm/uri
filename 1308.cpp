#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main ()
{
	ll n;
	int cases;
	cin >> cases;
	while(cases--)
	{
		cin >> n;
		
		cout << (ll)((-1.0 + sqrt(1 + 8*n))/2.0) << '\n';
	}
}
