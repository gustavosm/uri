#include <bits/stdc++.h>

using namespace std;
int main ()
{
	int n;
	int m;
	int ans;
	int flag;
	int aux;
	int i;
	
	int v[] = {0,0,0,0,0,0,0,0,0,0};
	
	while(cin >> n >> m)
	{
		ans = 0;
		for (n = n; n <= m; n++)
		{
			aux = n;
			while(aux > 0)
			{
				v[aux%10]++;
				aux/=10;
			}
			flag = 0;
			for (i = 0; i < 10; i++)
			{	
				if (v[i] > 1)
				{
					flag = 1;
					break;
				}
				v[i] = 0;
			}
			if (!flag) ans++;
			else
			{
				for (i = i; i < 10; i++)
					v[i] = 0;
			}
		}
		cout << ans << '\n';
	}
}
