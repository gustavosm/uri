#include <bits/stdc++.h>


using namespace std;
typedef long long ll;


/*
(a + b) % m = ((a % m) + (b % m)) % m
(a x b) % m = ((a % m) * (b % m)) % m
*/
int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(false);
	
	ll ans;
	
	int n;
	
	int tam;
	
	while (cin >> n)
	{
		ans = 1;
		tam = 1;
		while (ans % n != 0)
		{
			ans = ((ans % n) * (10 % n)) % n;
			ans = ((ans % n) + (1 % n)) % n;
			++tam;
		}
		cout << tam << '\n';
	}	
	
}
