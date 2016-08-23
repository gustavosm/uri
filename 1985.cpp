#include <bits/stdc++.h>


using namespace std;


int main()
{

	int n;
	
	int pedido, qtde;
	cout.precision(2);
	while (cin >> n)
	{
		double ans = 0.0;
		while (n--)
		{
			cin >> pedido >> qtde;
			
			ans += ((double)(pedido % 1000) + .5) * qtde;
		}
		cout << fixed << ans << '\n';
	}
}
