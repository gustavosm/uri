#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

vector<ll> v;
int n;

ll forca(string& s, ll pos)
{
	ll ans = 0;
	
	for (int i = 0 ; i < s.size(); ++i)
		ans += (ll)s[i];
		
	return ans * pos;
}
ll calc(int b, int e, int avanco)
{
	ll ans = 0;
	int p = 1;
	if (avanco == 1)
		for (int i = b; i <= e; ++i)
			ans += v[i] * p, ++p;
	else
		for (int i = e; i >= b; --i)
			ans += v[i] * p, ++p;
					
	return ans;
}
int bs(int b, int e)
{
	int mid;
	
	while (b <= e)
	{
		mid = (b + e) / 2;
		
		ll forcaA = calc(0, mid, -1);
		ll forcaB = calc(mid + 1, n - 1, 1);
		
		if (forcaA == forcaB) return mid;
		
		else if (forcaA > forcaB)
			e = mid - 1;
		else b = mid + 1;
	}
	return -1;
}

int main()
{
	string s;
	vector<string> v2;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	while (1)
	{
		cin >> n;
		
		if (!n) return 0;
		
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> s;
			v.push_back(forca(s, 1));
			v2.push_back(s);
		}
		
		int idx = bs(0, n - 1);
		
		if (idx == -1) cout << "Impossibilidade de empate.\n";
		else cout << v2[idx] << '\n';
		
		v2.clear();
		v.clear();
	}
}
