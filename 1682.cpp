#include <bits/stdc++.h>

using namespace std;


char s[] = "NONPNOPNPONOPNONPNOPNPONON";

int main()
{
	int n = strlen(s);
	
	int m;
	
	while (1)
	{
		cin >> m;
		
		if (!m) return 0;
		int i = 0 ;
		while (m--)
		{
			cout << s[i];
			i = (i + 1) % n;
		}
		cout << '\n';
	}
}