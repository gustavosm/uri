#include <bits/stdc++.h>

using namespace std;
int main()
{
	int a;
	int b;
	int c;
	while (cin >> a >> b >> c)
	{
		if (a == b && b == c) cout << "*\n";
		else
		{
			if (a != b && b == c) cout << "A\n";
			else if (b != a && a == c) cout << "B\n";
			else if (c != a && a == b) cout << "C\n";
		}
	}
}
