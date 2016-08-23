#include <bits/stdc++.h>

#define MAXN 2000001
using namespace std;

bitset<MAXN> prime;
int divr[MAXN], ans[MAXN];

void calc()
{
	prime.set();
	memset(divr, 0 , sizeof(divr));
	
	for (int i = 2; i < MAXN; i++)
	{
		if (prime[i])
		{
			divr[i] = 2;
			for (int j = i + i; j < MAXN; j+= i)
			{
				prime.reset(j);
				
				int divs = 0;
				int tam = j;
				
				while ( tam % i == 0) tam/= i, divs++;
				
				if (divr[j] == 0) divr[j] = divs + 1;
				else divr[j]*= (divs + 1);
			}
		}
	}
	
	ans[1] = 0;
	for (int i = 2; i <= MAXN; i++)
	{
		ans[i] = ans[i - 1];
		if (prime[divr[i]]) ans[i]++;
	}	
}

int main()
{
	int n;
	
	calc();
	while(cin >> n)
	{
		cout << ans[n] << '\n';
	}
}
