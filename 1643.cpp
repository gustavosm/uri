#include <bits/stdc++.h>


using namespace std;

int fib[25];
int sz;

void calc()
{
	sz = 0;
	fib[sz++] = 1;
	
	fib[sz++] = 2;
	
	int soma = 0;
	for (int i = 2; soma < 25000; ++i)
	{
		soma = fib[i - 1] + fib[i - 2];
		if (soma >= 25000) break;
		fib[sz++] = soma;
	}
}

int lowerbound(int val)
{
	int b = 0;
	int e = sz - 1;
	
	while (b <= e)
	{
		if (fib[b] == val) return b;
		if (fib[e] == val) return e;
		
		int mid = (b + e) / 2;
		
		if (fib[mid] <= val && val < fib[mid + 1]) return mid;
		
		if (fib[mid] > val) e = mid - 1;
		else b = mid + 1;		
	}
	return e;
}

int main()
{		
	int cases;
	int x;
	
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	calc();
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> x;
		
		int it = lowerbound(x);
		
		int val = (1 << it);
		x -= fib[it];
		
		for (; it >= 0 && x; --it)
		{
			if (x >= fib[it])
			{
				x -= fib[it];
				val |= (1 << it);
			}
		}		
		
		val >>= 1;
		int sub;
		int bit;
		int conversor = 0;
		while (val)
		{
			sub = (val & (-val));
			bit = 0;
		
			val -= sub;
			while (sub > 1)
			{
				++bit;
				sub >>= 1;
			}
			conversor += fib[bit];
		}
		
		cout << conversor << '\n';
	}
}
