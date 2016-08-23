#include <bits/stdc++.h>

using namespace std;
int main()
{
	int maior;
	int n;
	int x;
	
	while(cin >> n)
	{
		maior = -1;
		
		for (int i = 0 ; i < n ; i++)
		{
			cin >> x;
			if (x > maior) maior = x;
		}
		
		maior/= 10;
		switch(maior)
		{
			case 0:
			cout << "1\n";
			break;
			case 1:
			cout << "2\n";
			break;
			default:
			cout << "3\n";
			break;
		}		
	}
}
