#include <bits/stdc++.h>

using namespace std;
int main ()
{
	int n;
	int ans;
	int corrida;
	
	while(1)
	{
		cin >> n;
		if (!n) return 0;
		ans = 0;
		while (n > 1)
		{
			corrida = 0;
			while (n % 3 != 0)
			{
				n-= 2;
				ans++;
				corrida++;
			}
			ans+= n / 3;
			n = n / 3 + corrida;
		}
		cout << ans << '\n';
		
	}
}
