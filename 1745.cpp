#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1000005;
int modsum[MAXN];
ll seen[3][MAXN];

ll solve(string &s) 
{
	ll ans = 0LL;
	int n = s.size();
	modsum[0] = 0;
	for (int i = 0; i < n; ++i) 
	{
		int val = s[i] - '0';
		modsum[i + 1] = (modsum[i] + val) % 3;
	}
	seen[0][0] = 1LL;
	seen[1][0] = seen[2][0] = 0LL;
	
	for (int i = 0; i < n; ++i) 
	{
		for (int k = 0; k < 3; ++k) 
		{
			int val = modsum[i + 1];
			seen[k][i + 1] = seen[k][i] + (val == k);
			ans += (val == k) ? seen[k][i] : 0;
		}
	}
	return ans;
}

int main() 
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	string s;
	while (cin >> s) 
	{
		int n = s.size();
		int ind = 0;
		string num = "";
		ll ans = 0LL;
		while (ind < n) 
		{
			if (isdigit(s[ind])) num += s[ind];
			else 
			{
				if (num != "") ans += solve(num);
				num = "";
			}
			ind++;
		}
		if (num != "") ans += solve(num); 
		cout << ans << '\n';
	}
	return 0;   
}
