#include <bits/stdc++.h>

using namespace std;
int main ()
{
	vector<int> largada;
	vector<int> chegada;
	vector<int> val;
	
	int x;
	int n;
	int ans;
	
	while(cin >> n)
	{
		for(int i = 0 ; i < n; i++)
		{
			cin >> x;
			largada.push_back(x);
		}
		for(int i = 0 ; i < n; i++)
		{
			cin >> x;
			chegada.push_back(x);
		}
		
		val.assign(n,0);
		
		for(int i = 0 ; i < n; i++)
		{
			val[chegada[i] - 1] = i;
		}
		ans = 0;
		for (int i = 0 ; i < n; i++)
		{
			for (int j = 0 ; j < n - i - 1; j++)
			{
				if (val[largada[j] - 1] > val[largada[j+1] - 1])
				{
					ans++;
					int aux = largada[j+1];
					largada[j+1] = largada[j];
					largada[j] = aux;
				}
			}
		}
		cout << ans << '\n';
		largada.clear();
		chegada.clear();
		val.clear();
	}
}
