#include <bits/stdc++.h>



using namespace std;


int main()
{
	string str, str2;
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	while (getline(cin, str))
	{
		getline(cin, str2);
		int n = str.size();
		int m = str2.size();
		
		int ans = 0;
		for (int i1 = 0 ; i1 < n; ++i1)
		{
			for (int j1 = 0; j1 < m; ++j1)
			{
				int tam = 0;
				int i = i1;
				int j = j1;
				
				while (i < n && j < m && str[i] == str2[j])
				{
					++i;
					++j;
					++tam;
				}
				ans = max(ans, tam);
			}
		}
		cout << ans << '\n';
		
	}
}
