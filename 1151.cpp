#include <bits/stdc++.h>

using namespace std;
int main ()
{
	int first = 0;
	int second = 1;
	int fibonacci;
	int n;
	cin >> n;
	cout << "0";
	n--;
	while (n--)
	{
		cout << " " << second;
		fibonacci = second;
		second+= first;
		first = fibonacci;
	}
	cout << '\n';
	return 0;
}
