#include <bits/stdc++.h>

using namespace std;
int main()
{
	map<int,int> mp;
	
	int m;
	int k;
	vector<int> v;
	int ans;
	int q;
	
	while(cin >> m >> k)
	{
		v.assign(m,0);
		for (int i = 0 ; i < m ; i++)
		{
			cin >> v[i];
		}
		ans = 0;
		for (int i = 0 ; i < k; i++)
		{
			cin >> q;
			--q;
			
			if (mp.size() < m) ans+= v[q];
			mp[q]++;
		}
		if (mp.size() < m) cout << "-1\n";
		else cout << ans << '\n';
		
		mp.clear();
		v.clear();
	}
}
