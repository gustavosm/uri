#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll>v;
ll possibilidades(ll x)
{
	if (x < 0) return 0;
	if (v[x]) return v[x];
	if (x == 0) return 1;
	else return possibilidades(x-1) + possibilidades(x-2);
	
}
void solve()
{
	for (ll i = 1; i <= 40; i++)
		v[i] = possibilidades(i);
}
int main ()
{
	v.assign(45, 0);
	int i;
	solve();
	while(1)
	{
		cin >> i;
		if (!i) return 0;
		printf("%u\n",v[i]);
	}
	return 0;
	
}
