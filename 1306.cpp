#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n, r;
	int caso = 1;
	int flag;
	
	while(1)
	{
		cin >> r >> n;
		if (!n && !r) return 0;
		
		if (n >= r) 
			cout << "Case " << caso << ": 0\n";
		else
		{
			flag = 0;
			for (int i = 1; i <= 26; i++)
				if (n * (i + 1) >= r) // usando i letras + o caso de nao usar letra entao i + 1
				{
					cout << "Case " << caso << ": " << i << '\n';
					flag = 1;
					break;
				}
			if (!flag) cout << "Case " << caso << ": impossible\n";
		}
		caso++;
	}
}
