#include <bits/stdc++.h>


using namespace std;


int main()
{
	string pk;
	int n;
	int l;
	int bs, ev, iv;
	int caso = 1;
	cin >> n;
	
	while (n--)
	{
		cin >> pk >> l;
		
		cout << "Caso #" << caso++ << ": ";
		cout << pk << " nivel " << l << '\n';
		cin >> bs >> iv >> ev;
		cout << "HP: " << (int)((((iv + bs + sqrt(ev)/8. + 50) * l) / 50) + 10) << '\n';
		cin >> bs >> iv >> ev;
		cout << "AT: " << (int)((((iv + bs + sqrt(ev)/8.) * l) / 50) + 5) << '\n';
		cin >> bs >> iv >> ev;
		cout << "DF: " << (int)((((iv + bs + sqrt(ev)/8.) * l) / 50) + 5) << '\n';
		cin >> bs >> iv >> ev;
		cout << "SP: " << (int)((((iv + bs + sqrt(ev)/8.) * l) / 50) + 5) << '\n';

	}
}
