#include <bits/stdc++.h>


using namespace std;


int main()
{
	map<string, int> m;
	map<string, int> m2;
	
	map<string, int> :: iterator it;
	
	string s1, s2;
	
	while (cin >> s1 >> s2)
	{
		++m[s1];
		++m2[s2];
	}
	cout << "HALL OF MURDERERS\n";
	for (it = m.begin(); it != m.end(); ++it)
	{
		int aux = m2[it->first];
		
		if (!aux)
		{
			cout << it->first << ' ' << it->second << '\n';
		}
	}
	m.clear();
	m2.clear();
}


