#include <bits/stdc++.h>


using namespace std;
typedef long long ll;


int main()
{
	int c, d;
	int cases;
	cin >> cases;
	while (cases--)
	{
		cin >> c >> d;
		
		if (c == 0 && d == 0) cout << 0 << '\n';
		else
		{
			ll ans = 1;
			while (c) {ans *= 26; --c;}
			while (d) {ans *= 10; --d;}
			
			cout << ans << '\n';
		}
	}
}
