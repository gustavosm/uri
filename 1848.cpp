#include <bits/stdc++.h>


using namespace std;


int main()
{
	string aux;
	long long ans = 0;
	long long bin;
	while (getline(cin, aux))
	{
		if (aux[0] == 'c') 
		{
			cout << ans << '\n';
			ans = 0;
		}
		else
		{
			int tam = aux.size();
			bin = 0;
			for (int i = 0 ; i < tam; ++i)
			{
				if (aux[i] == '*')
					bin += pow(2, tam - i - 1);
			}
			ans += bin;
		}
	}
}
