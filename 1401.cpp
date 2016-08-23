#include <bits/stdc++.h>

using namespace std;
int main ()
{
	string s;
	int n;
	
	cin >> n;
	getchar();
	
	while(n--)
	{
		getline(cin, s);
		sort(s.begin(), s.end());
		
		do
		{
			cout << s << '\n';
		}while(next_permutation(s.begin(), s.end()));
		cout << '\n';
	}
}
