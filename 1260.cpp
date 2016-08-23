#include <bits/stdc++.h>

using namespace std;
int main ()
{
	map <string, double> m;
	map <string, double> ::iterator it;
	
	int cases;
	double qtde;
	
	string s;
	
	cin >> cases;
	getchar();
	getchar();
	int pl = 0;
	
	while (cases--)
	{
		if (pl == 1) cout << '\n';
		pl = 1;
		qtde = 0.0;
		while(getline(cin , s))
		{
			if (s.size() == 0) break;
			m[s]++;
			qtde++;
		}
		for (it = m.begin(); it != m.end(); it++)
		{
			cout << it->first << " ";
			printf("%.4lf\n", it->second/qtde * 100);
		}
		m.clear();
	}
}
