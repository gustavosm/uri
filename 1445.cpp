#include <bits/stdc++.h>


using namespace std;

vector<int> pset;

void init()
{
	pset.assign(1005, 0);
	
	for (int i = 0; i < 1005; ++i) pset[i] = i;
}

int findset(int i)
{
	return (pset[i] == i? i : pset[i] = findset(pset[i]));
}

bool same(int i, int j)
{
	return findset(i) == findset(j);
}

void une(int i, int j)
{
	pset[findset(i)] = findset(j);
}

int main()
{
	int u, v;
	
	int n;
	int ans;
	while (1)
	{
		cin >> n;
		if (!n) return 0;
		
		ans = 1;
		
		init();
		getchar();
		while (n--)
		{
			scanf("(%d,%d)", &u, &v);		
			getchar();	
			
			--u; --v;
			
			if (!same(u, v)) une(u, v);
		}
		int set = findset(0);
		for (int i = 1 ; i < 1005; ++i)
		{
			if (set == findset(i))
				++ans;
		}
		
		cout << ans << '\n';
		
		pset.clear();
	}
}

