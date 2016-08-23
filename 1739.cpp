#include <bits/stdc++.h>

using namespace std;

int valido(int n)
{
	while(n > 0)
	{
		if (n % 10 == 3) return 1;
		n/= 10;
	}
	return 0;
}

int main()
{
	int n;
	int num;
	long long fibo[1020];
	int i;
	
	fibo[0] = 0;
	fibo[1] = 1;
	
	for (i = 2; i <= 1000; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		
	while(cin >> n)
	{
		for (i = 2; i <= 1000; i++)
		{
			if (valido(fibo[i]) || fibo[i] % 3 == 0)
				n--;	
			if (!n) break;
		}
		cout << fibo[i] << '\n';
	}
}
