#include <bits/stdc++.h>

using namespace std;
int main ()
{
	int n;
	int espacos;
	int nasterisco;
	while (cin >> n)
	{
		espacos = n/2;
		nasterisco = 1;
		while(nasterisco <= n)
		{
			for (int i = 0 ; i < espacos; i++)
				cout << ' ';
			for (int i = 0; i < nasterisco; i++)
				cout << '*';
			cout << '\n';
			nasterisco+=2;
			espacos--;
		}
		espacos = n/2 + n%2;
		for (int i = 0 ; i < espacos-1; i++)
			cout << ' ';
		cout << "*\n";
		espacos--;
		for (int i = 0 ; i < espacos-1; i++)
			cout << ' ';
		cout << "***\n\n";
	}
}
