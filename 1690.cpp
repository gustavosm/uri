#include <bits/stdc++.h>


using namespace std;
typedef long long ll;



int main()
{
	ll v[10005];
	ios_base :: sync_with_stdio(false); 
	cin.tie(0);
	
	ll sum;
	int n;
	
	int cases;
	bool ok;
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> n;
		ok = false;
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> v[i];
			
			if (v[i] == 1) ok = true;
		}
		
		if (!ok) cout << "1\n";
		else
		{
			sum = 1;
			
			sort(v, v + n);
			for (int i = 0 ; i < n ; ++i)
			{
				if (v[i] > sum) break;
				sum += v[i];
			}
			cout << sum << '\n';
		}
	}
}
