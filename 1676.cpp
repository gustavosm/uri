#include <bits/stdc++.h>


using namespace std;


int main()
{	
	vector<int> v;
	int aux;
	
	v.assign(40004, 0);
	
	for (int i = 2; i <= 40000; ++i)
		v[i] = i;
		
	for (int i = 2; i < v.size(); ++i)
	{
		while (i < v.size() && v[i] == -1) ++i;
		aux = 0;
		for (int j = i + 1; j < v.size(); ++j)
		{
			if (v[j] != -1)
			{
				++aux;
				if (aux == v[i]) 
				{
					v[j] = -1;
					aux = 0;
				}
			}
		}
	}
	
	int n;
	int j;
	while (1)
	{
		scanf("%d" , &n);
		if (!n) return 0;
		
		for (int i = 2; i < v.size(); ++i)
		{
			if (v[i] != -1) --n;
			
			if (!n)
			{
				cout << v[i] << '\n';
				break;
			}
		}
	}
}
