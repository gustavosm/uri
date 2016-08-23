#include <bits/stdc++.h>


using namespace std;


string toString(double obj)
{
	string s;
	stringstream o;
	o << obj;
	o >> s;
	return s;
}

int palindrome(string& a)
{
	for (int i = 0, j = a.size() - 1; i < j; ++i, --j)
		if (a[i] != a[j]) return 0;
	return 1;
}
int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	
	int cases;
	
	double a;
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> a;
		for (double i = 0.0; ; i += 0.000001)
		{
			string s = toString(a + i);
			cout << "String  = " << s << '\n';
			if (palindrome(s))
			{
				cout << i << '\n';
				break;
			}
		}
	}
}
