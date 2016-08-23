#include <bits/stdc++.h>


using namespace std;


int main()
{
	int cases;
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> n >> c >> f;
		
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> v[i];
			sum[i] = v[i];
			if (i) sum[i] += sum[i - 1];
		
			s += v[i];
		}
		int low = 0;
		int sup = 0;
		int qtde = 1;
		while (sup >= low)
		{
			int mid = (sup + low) / 2;
			
			if ((sum[mid] - (low == 0? 0 : sum[low - 1])) * (qtde + 1) < s)
			{
				s = (sum[mid] - (low == 0? 0 : sum[low - 1]));
				flag = 1;
			}
			if ((sum[sup] - sum[mid]) * (qtde + 1)) < s)
			{
				s = sum[sup] - sum[mid];
				flag = 1;	
			}
			
		}
	}
}
