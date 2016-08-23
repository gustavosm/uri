#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
int main()
{
	string x;
	ll teste;
	ll ans;
	map<char, ll> freq;
	map<char, ll> :: iterator it;
	ll f[1003];
	f[0] = 1;
	f[1] = 1;
	f[2] = 2;
	f[3] = 6;
	for (int i = 4; i < 1003; i++)
	{
		f[i] = (i * f[i - 1]);
		f[i] %= 1000000007;
	}
		
	while(getline(cin, x))
	{
		int tam = x.size();
		for (int i = 0 ; i < tam; i++)
			freq[x[i]]++;
		ans = 1;
		for (it = freq.begin(); it != freq.end(); it++)
		{
			teste = it->second;
			if (teste > 1)
				ans = (ans * f[teste]) % 1000000007;
		}
		cout << f[tam] / ans << '\n';
		
		freq.clear();
	}
}
