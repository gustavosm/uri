#include <bits/stdc++.h>


using namespace std;

#define MOD 100000007

typedef long long ll;


ll fat[10005];

void calc()
{
	fat[0] = fat[1] = 1;
	
	for (int i = 2; i <= 10000; ++i)
		fat[i] = ((i % MOD) * (fat[i - 1] % MOD)) % MOD;
}


int main()
{
	string s;
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int freq[26];
	calc();
	while (1)
	{
		cin >> s;
		
		if (s == "0") return 0;
		
		memset(freq, 0, sizeof freq);
		
		for (int i = 0 ; i < s.size(); ++i)
			++freq[s[i] - 'a'];
		
		ll sobre = 1;
		
		for (int i = 0 ; i < 26; ++i)
			sobre = ((sobre % MOD) * (fat[freq[i]] % MOD)) % MOD;
		
		cout << (fat[s.size()] / sobre + MOD) % MOD << '\n';
	}
}
