#include <bits/stdc++.h>


using namespace std;

string base(unsigned long long n)
{
	string ans;
	if (!n) return "0";
	
	while (n)
	{
		int resto = n % 32;
		
		if (resto < 10) ans.push_back(resto + '0');
		else ans.push_back(resto - 10 + 'A');
		
		n /= 32;
	}
	
	reverse(ans.begin(), ans.end());
	
	return ans;
}

int main()
{
	unsigned long long n;
	
	while (cin >> n)
	{
		
		cout << base(n) << '\n';
		
		if (!n) return 0;
		
	}
}
