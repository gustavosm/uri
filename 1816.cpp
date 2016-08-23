#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	int x;
	int inst = 1;
	
	string s;
	string aux;
	
	while (cin >> n)
	{
		if (!n) break;
		s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		aux = "";
		cout << "Instancia " << inst++ << '\n';
		for (int i = 0; i < n ; i++)
		{			
			cin >> x;
			--x;
			cout << s[x];
			aux.push_back(s[x]);
			
			s.erase(s.begin() + x);
			aux += s;
			
			s = aux;
			
			aux = "";
		}
		cout << "\n\n";
		
		s.clear();
	}
}
