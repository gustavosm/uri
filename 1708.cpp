#include <bits/stdc++.h>

using namespace std;
int main()
{
	int ans;
	int tmax, tmin;
	
	while(cin >> tmin >> tmax)
	{
		ans = 1;
		tmax = tmax - tmin;
		
		while(tmin > 0)
		{
			tmin-= tmax;
			ans++;
		}
		cout << ans << '\n';
	}
}
