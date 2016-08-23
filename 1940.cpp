#include <bits/stdc++.h>


using namespace std;


int main()
{
	int v[506];
	int x;	
	int n, k;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while (cin >> n >> k)
	{
		for (int i = 0 ; i < n ; ++i) v[i] = 0;
		
		for (int i = 0 ; i < n * k ; ++i)
		{
			cin >> x;
			v[i % n] += x;
		}
		int maior = v[0];
		int pos = 0;
		for (int i = 1 ; i < n ; ++i)
		{
			if (v[i] >= maior)
			{
				maior = v[i];
				pos = i;
			}
		}
		cout << pos + 1 << '\n';
	}
}
