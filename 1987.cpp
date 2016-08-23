#include <bits/stdc++.h>


using namespace std;


int main()
{
	int n;
	
	long long c;
	
	int sum = 0;
	while (cin >> n >> c)
	{
		sum = 0;
		while (c)
		{
			sum += (c % 10);
			c /= 10;
		}
		cout << sum << ' ' << (sum % 3 == 0 ? "sim\n" : "nao\n");
	}
}
