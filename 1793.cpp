#include <bits/stdc++.h>


using namespace std;

int main()
{
	int n;
	int v[105];
	
	while (1)
	{
		cin >> n;
		if (!n) return 0;
		
		int ans = 10;
		
		for (int i = 0 ; i < n ; i++)
		{
			cin >> v[i];
		}
		
		for (int i = 1; i < n; i++)
		{
			ans += min(10, v[i] - v[i - 1]);
		}
		cout << ans << '\n';
	}
}
