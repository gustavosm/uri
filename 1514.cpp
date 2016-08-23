#include <bits/stdc++.h>

using namespace std;
int main ()
{
	vector<vector<int> > v;
	
	int n;
	int m;
	int x;
	int ans;
	int flag;
	
	while(1)
	{
		cin >> n >> m;
		if (!n && !m) return 0;
		
		for (int i = 0; i < n ; i++)
		{
			v.push_back(vector<int>());
			for (int j = 0 ; j < m ; j++)
			{
				cin >> x;
				v[i].push_back(x);
			}
		}
		ans = 0;
		//ninguem resolveu tudo
		flag = 0;
		for (int i = 0 ; i < n ; i++)
		{
			int min = *min_element(v[i].begin(), v[i].end());
			if (min == 1) 
			{
				flag = 1;
				break;
			}
		}
		if (!flag) ans++;
		flag = 0;
		//todos resolveram pelo menos um
		for (int i = 0 ; i < n ; i++)
		{
			int max = *max_element(v[i].begin(), v[i].end());
			if (max == 0) 
			{
				flag = 1;
				break;
			}
		}
		if (!flag) ans++;
		
		//todo problema resolvido por pelo menos um
		flag = 0;
		for (int i = 0; i < m ; i++)
		{
			int max = -1;
			for (int j = 0 ; j < n ; j++)
			{
				if (v[j][i] > max)
				{
					max = v[j][i];
				}				
			}
			if (max == 0)
			{
				flag = 1;
				break;
			}
		}
		if (!flag) ans++;
		
		//nao existe nenhum problema resolvido por todos
		flag = 0;
		for (int i = 0; i < m ; i++)
		{
			int min = 3;
			for (int j = 0 ; j < n ; j++)
			{
				if (v[j][i] < min)
				{
					min = v[j][i];
				}				
			}
			if (min == 1)
			{
				flag = 1;
				break;
			}
		}
		if (!flag) ans++;
		
		
		cout << ans << '\n';
		v.clear();
	}
}
