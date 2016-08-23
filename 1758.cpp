#include <bits/stdc++.h>

using namespace std;


int main()
{
	int cases;
	int p;
	int n;
	double soma;
	double maior;
	double nota;
	
	double v[8];
	
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cout.precision(2);
	cin >> cases;
	
	while (cases--)
	{
		cin >> p >> n;
		for (int i = 0; i < n ; ++i)
		{
			soma = 0.0;
			
			for (int j = 0; j < p ; ++j)
			{
				cin >> nota;
				v[j] = nota;
				soma += nota;
			}	
			soma /= p;
			sort(v, v + p);
			
			if (soma >= 4.0)
			{
				int pos = p - 1;
				maior = v[pos];
				if (soma >= 4.0 && soma < 7.0)
				{	
					while (pos >= 0 && maior >= 7.0)
						maior = v[pos--];
					cout << fixed << max(maior, soma) << '\n';
					
				}
				else cout << fixed << max(maior, soma) << '\n';
			}
			else
				cout << fixed << soma << '\n';
				
		}
	}
}
