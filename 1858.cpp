#include <bits/stdc++.h>


using namespace std;


int main()
{
	int n;
	int x, pos;
	int mn;
	
	while (cin >> n)
	{
		mn = INT_MAX;
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> x;
			if (x < mn)
			{
				mn = x;
				pos = i + 1;
			}
		}
		cout << pos << '\n';
	}
}
