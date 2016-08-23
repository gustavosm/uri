#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main()
{

	ll ans;
	
	int n, x;
	
	cin >> n;
	
	while (n--)
	{
		cin >> x;
		x -= 5;
		if (x < 0) cout << "0 kg\n";
		else
		{
			ans = 1;
			ans <<= x;
			ans /= (3 * 125);
			cout << ans << " kg\n";
		}
	}
}
