	#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> aux;
	vector<int> aux2;
	vector<int> v;	
	
	int cases;
	int k;
	int ans;
	int n;
	int qtde;
	
	cin >> cases;
	
	while(cases--)
	{
		cin >> n >> k;
		
		v.assign(n, 0);
		ans = -1;
		for (int i = 0 ; i < n ; i++)
			cin >> v[i];
			
		ans = 0;
		
		for (int j = 30	; j >= 0; --j)
		{
			qtde = 0;
		
			int bit = 1 << j;
			for (int i = v.size() - 1; i >= 0; --i)
			{
				if (bit & v[i])
				{
					++qtde;
					aux.push_back(i);
				}
				else aux2.push_back(i);
			}
			if (qtde >= k) 
			{	
				int aux_ans = v[aux[0]];			
				for (int i = 1 ; i < qtde; ++i)
				{
					aux_ans &= v[aux[i]];	
				}
			
				ans = max(ans, aux_ans);
				
				for (int i = 0 ; i < aux2.size(); ++i)
					v.erase(v.begin() + aux2[i]);
			}
			
			aux.clear();
			aux2.clear();
		}
		printf("%d\n", ans);
		v.clear();
	}
}
