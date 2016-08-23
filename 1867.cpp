#include <bits/stdc++.h>


using namespace std;

int val(long long x)
{
	while (x >= 10)
	{
		long long aux = x;
		long long s = 0;
		
		while (aux)
		{
			s += aux % 10;
			aux /= 10;
		}
		x = s;
	}
	return x;
}
int compare(long long a, long long b)
{
	return (a > b ? 1 : a < b ? 2 : 0);
}
int main()
{
	string a, b;
	
	long long a1, b1;
	
	while (1)
	{
		cin >> a >> b;
		if (a == "0" && b == "0") return 0;
		a1 = b1 = 0;
		
		for (int i = 0 ; i < a.size(); ++i) a1 += a[i] - '0';
		for (int i = 0 ; i < b.size(); ++i) b1 += b[i] - '0';
		
		cout << compare(val(a1), val(b1)) << '\n';
	}
}
