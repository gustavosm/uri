#include <bits/stdc++.h>


using namespace std;


stack<string> v;

int main()
{
	int n;
	
	char c;
	string aux;
	
	int ans;
	
	while (cin >> n)
	{
		ans = 0;
		v.push("FACE");
		for (int i = 0 ; i < n ; ++i)
		{
			aux.clear();
			for (int j = 0 ; j < 4  ; ++j)
			{
				cin >> c;
				aux.push_back(c);
			}
			string aux2 = aux;
			reverse(aux2.begin(), aux2.end());
			
			if (v.top() == aux2)
			{
				++ans;
				v.pop();
				if (v.size() == 0) v.push("FACE");
			}
			else
				v.push(aux);
		}
		cout << ans << '\n';
		while (!v.empty()) v.pop();
	}
}
