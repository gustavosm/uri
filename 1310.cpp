#include <bits/stdc++.h>

using namespace std;

int n;
int a[55];

int solve()
{
	int endh;
	int endm;
	endh = endm = 0;
	for (int i = 0 ; i < n ; i++)
	{
		endh = max(0, endh + a[i]);
		endm = max(endm, endh);
	}
	return endm;
}

int main()
{
	int cost;
	while(cin >> n)
	{
		cin >> cost;
		for (int i = 0 ; i < n ; i++)
		{
			cin >> a[i];
			
			a[i]-= cost;
		}
		cout << solve() << '\n';
	}
}
