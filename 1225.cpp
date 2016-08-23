#include <bits/stdc++.h>

using namespace std;
int solve(vector<int> coral, int tot, int qtde)
{
	if (tot % qtde) return -1;
	
	tot/= qtde;
	int ans = 0;
	
	for (int i = 0 ; i < coral.size(); i++)
		if (tot < coral[i]) ans+= coral[i] - tot;
	
	return ans + 1;
}

int main()
{
	vector<int> v;
	
	int n;
	int x;
	int tot;
	
	while (cin >> n)
	{
		tot = 0;
		for (int i = 0 ; i < n ; i++)
		{
			cin >> x;
			tot+= x;
			v.push_back(x);
		}
		cout << solve(v, tot, n) << '\n';
		v.clear();
	}
}
