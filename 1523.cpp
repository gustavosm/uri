#include <bits/stdc++.h>

using namespace std;

int main()
{
	int s[10010];
	int n;
	int k;
	int c;
	int f;
	int flag;
	int pos;
	
	while(1)
	{
		cin >> n >> k;
		
		if (!n && !k) return 0;

		flag = 0;
		pos = -1;

		for (int i = 0 ; i < n ; i++)
		{
			cin >> c >> f;
			if (!flag)
			{ 
				if (pos == -1)
				{
					pos++;
					s[pos] = f;
				}
				else
				{
					int ultimo = s[pos];
					if (c >= ultimo)
					{
						while(pos >= 0 && c >= ultimo)
						{
							pos--;
							if (pos < 0) break;
							ultimo = s[pos];
						}
					}					
					if (pos >= k)
						flag = 1;
					else 
					{
						if (pos >= 0  && f > s[pos])
							flag = 1;
						else
						{
							pos++;
							s[pos] = f;
						}
					}
				}
			}
		}
		if (!flag) cout << "Sim\n";
		else cout << "Nao\n";		
	}
}
