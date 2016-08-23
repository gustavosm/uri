#include <bits/stdc++.h>


using namespace std;


int main()
{
	string s;

	int m, k;
	int n, q;
	int i;
	int cont;
	
	while (1)
	{
		cin >> n >> q;
		
		if (!n &&  !q) return 0;
		
		cin >> s;
		
		string aux = s;
		
		while (q--)
		{
			cin >> k >> m;
			
			i = k;
			
			cont = 1;
	
			s = aux;
			
			s[0] = (s[0] == 'x'? 'o' : 'x');
	
			while (s != aux)
			{
				s[i] = (s[i] == 'x'? 'o' : 'x');
		
				i = (i + k) % n;
		
				cont++;
			}
			
			m %= cont;
			
			s = aux;
	
			while (m--)
			{
				s[i] = (s[i] == 'x'? 'o' : 'x');
		
				i = (i + k) % n;
			}
			cout << s << '\n';
		}
	}
	
	cout << cont << '\n';
}
