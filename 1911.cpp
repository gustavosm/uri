#include <bits/stdc++.h>


using namespace std;


map<string ,string > m;


int diff(string &a, string &b)
{
	int dif = 0;
	for (int i = 0 ; i < min(a.size(), b.size()); ++i)
	{
		if (a[i] != b[i]) ++dif;
	}
	return dif + abs(a.size() - b.size());
}
int main()
{
	int n, m1;
	string s1, s2;
	int roubou;
	while (cin >> n, n)
	{
		roubou = 0;
		
		for (int i = 0 ; i < n; ++i)
		{
			cin >> s1 >> s2;
			
			m[s1] = s2;
		}
		
		cin >> m1;
		
		for (int i = 0 ; i < m1; ++i)
		{
			cin >> s1 >> s2;
			
			if (diff(s2, m[s1]) > 1) ++roubou;
		}
		
		cout << roubou << '\n';
	}
}
