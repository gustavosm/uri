#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int main ()
{
	vector<ii> v;
	vector<int> v2;
	
	int n;
	int piloto;
	int posicao;
	int flag;
	
	while(1)
	{
		cin >> n;
		if (!n) return 0;
		
		v2.assign(n,0);
		for (int i = 0 ; i  < n  ; i++)
		{
			cin >> piloto >> posicao;
			v.push_back(ii(piloto,posicao));
		}
		flag = 0;
		for (int i = 0 ; i < n ; i++)
		{
			if (v[i].second + i < 0 || v[i].second + i >= n)
			{
				flag = 1;
				break;
			}
			else
			{
				if (!v2[i + v[i].second])
					v2[i + v[i].second] = v[i].first;
				else
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag) cout << "-1\n";
		else 
		{
			for (int i = 0 ; i < n ; i++)
			{
				cout << v2[i];
				if (i < n - 1) cout << ' ';
			}
			cout << '\n';
		}
		v.clear();
		v2.clear();
	}
}
