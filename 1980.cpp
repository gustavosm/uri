#include <bits/stdc++.h>


using namespace std;


typedef long long ll;


ll fat[16];

void calc()
{
	fat[0] = fat[1] = 1;
	
	for (int i = 2; i <= 15; ++i)
		fat[i] = i * fat[i - 1];
}

ll solve(int n)
{
	return fat[n];
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
		
		cout << solve(s.size()) << '\n';
	}
}
