#include <bits/stdc++.h>


using namespace std;



typedef long long ll;

string filtro(ll n)
{
	string ans;
	
	while (n)
	{
		int resto = n % 10;
		
		if (resto) 
		{
			ans.push_back(resto + '0');
		}
		n /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	ll n, m;
	
	while (1)
	{
		cin >> n >> m;
		
		if (!n && !m) return 0;
		
		cout << filtro(n + m) << '\n';
	}
}
