#include <bits/stdc++.h>


using namespace std;


int main()
{
	int card;
	int card2;	
	int limite;
	int pA, pB;
	
	int n;
	
	
	while (cin >> n >> card >> limite)
	{
		pA = pB = 0;
		int vez = 0;
		for (int i = 1; i < n ; ++i)
		{
			cin >> card2;
			if (abs(card - card2) <= limite)
			{
				if (vez) pB += (abs(card - card2));
				else pA += (abs(card - card2));
				card = card2;
			}
			
			vez ^= 1;
		}
		
		cout << pA << ' ' << pB << '\n';
	}
}
