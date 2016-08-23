#include <bits/stdc++.h>


using namespace std;

int main()
{
	vector<vector<int> > v;
	
	while (1)
	{
		cin >> g >> p;
		
		for (int i = 0 ; i < g; ++i)
		{
			v.push_back(vector<int> ());
			for (int j = 0 ; j < p ; ++j)
			{
				cin >> x;
				v[i].push_back(x);
			}
		}
		
		cin >> S;
		
		for (int i = 0 ; i < S; ++i)
		{
			cin >> k;
			
			for (int j = 0 ; j < k; ++j)
			{
				cin >> x;
				
			}
		}
		
	}
}
