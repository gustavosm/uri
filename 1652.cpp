#include <bits/stdc++.h>

using namespace std;
int consoante(char c)
{
	c = tolower(c);
	return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}
int main ()
{
	map<string, string> m;
	
	string s1, s2;
	int n;
	int t;
	
	while(cin >> n >> t)
	{
		getchar();
		for (int i = 0 ; i < n ;  i++)
		{
			cin >> s1 >> s2;
			m[s1] = s2;
		}
		for (int i = 0 ; i < t ;i++)
		{
			cin >> s1;
			int tam = s1.size();
			if (!m[s1].empty()) cout << m[s1] << '\n';
			else
			{
				if (consoante(s1[tam - 2]) && s1[tam - 1] == 'y') cout << s1.substr(0,tam-1) << "ies\n";
				else if (s1[tam - 1] == 'o' || s1[tam - 1] == 's' || s1[tam - 1] == 'x') cout << s1 << "es\n";
				else if (s1[tam - 1] == 'h' && ( s1[tam - 2] == 's' || s1[tam - 2] == 'c')) cout << s1 << "es\n";
				else cout << s1 << "s\n";
			}
		}
		m.clear();
	}
}
