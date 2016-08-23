#include <bits/stdc++.h>
 
using namespace std;
long double fibo[1000];

int main ()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	 
	long double a, b;
	int ans;
	int i;

	fibo[0] = 1.0;
	fibo[1] = 2.0;
	for (int i = 2 ; i < 1000; i++)
			fibo[i] = fibo[i - 1] + fibo[i - 2];
	   
		 
	while(1)
	{
		cin >> a >> b;
		if (!a && !b) return 0;
		cout << (a < b) << '\n';
		for (i = 0; i < 1000; i++)
		{
			if (a <= fibo[i]) break;
		}
		ans = 0;
		while(fibo[i] <= b)
		{
			ans++;
			i++;
		}
		cout << ans << '\n';
	}
}
