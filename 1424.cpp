#include <bits/stdc++.h>

using namespace std;
int main ()
{
	int n;
	int m;
	map<int, vector<int> > ans;
	int ocr;
	int val;
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while(cin >> n >> m)
	{
		for (int i = 1 ; i <= n; i++)
		{
			cin >> val;
			ans[val].push_back(i);
		}
		for (int i = 0; i < m; i++)
		{
			cin >> ocr >> val;
			
			if (ocr > ans[val].size()) cout << "0\n";
			else cout << ans[val][ocr-1] << '\n';
		}
		ans.clear();
	}
}
