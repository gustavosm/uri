#include <bits/stdc++.h>



using namespace std;


int main()
{
	string s;
	
	while (cin >> s)
	{
		int temx = 0;
		int qtde = 0;
		int mx = INT_MIN;
		
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] != 'x')
				++qtde;
			else
			{
				if (temx == 0)
				{
					mx = max(mx, qtde);
					temx = 1;
				}
				else mx = max(mx, qtde / 2);
				qtde = 0;
			}
		}
		mx = max(mx, qtde);
		cout << mx << '\n';
	}
}
