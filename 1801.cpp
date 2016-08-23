#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

ll v[10000005];

void calc()
{
	for (int i = 1; i <= 10000000; ++i)
		v[i] = i * i;
}
int cdig(ll x)
{
	int ans = 0;
	
	while (x)
	{
		x /= 10;
		++ans;
	}
	return ans;
}
int main()
{
	ll x, y;
	int ans;
	calc();
	
	cin >> x;
	
	int dig = cdig(x);
	
	
}
