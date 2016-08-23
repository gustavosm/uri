#include <bits/stdc++.h>



using namespace std;


int main()
{
	int p, n;
	
	int x;
	int pr;
	
	
	while (cin >> p >> n)
	{	
		cin >> pr;
		int gameover = 0;
		for (int i = 1 ; i < n ; ++i)
		{
			cin >> x;
			if (abs(pr - x) > p) gameover = 1;
			pr = x;
		}
		if (gameover) cout << "GAME OVER\n";
		else cout << "YOU WIN\n";
	}
}
