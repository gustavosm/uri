#include <bits/stdc++.h>


using namespace std;


int palindrome(int n, int b)
{
	char ret[35];
	int tam = 0;
	int auxn = n;
	int i;
	i = 0;
	while (n)
	{
		int resto = n % b;
		if (resto <= 9)
			ret[i++] = resto + '0';
		else ret[i++] = resto - 10 + 'a';
		n /= b;
		++tam;
	}
	ret[tam] =  '\0';
	
	for (int k = 0, j = tam - 1; k < j; ++k, --j)
		if (ret[j] != ret[k]) return 0;
	return 1;	
}
int main()
{
	int cases;
	int flag;
	int n;
	
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> n;
		flag = 0;
		for (int i = 2; i <= 16; ++i)
		{
			if (palindrome(n, i))
			{
				if (flag) cout << ' ' ;
				cout << i;
				flag = 1;
			}
		}
		if (!flag) cout << -1;
		cout << '\n';
	}
}
