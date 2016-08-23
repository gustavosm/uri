#include <bits/stdc++.h>


using namespace std;
int xc;
int yc;
int r1;
int r2;

int dist(int x, int y)
{
	return (x - xc) * (x - xc) + (y - yc) * (y - yc);
}

int main()
{
	int n;
	int chiqx, chiqy;
	int popx, popy;
	
	int chiqdentro, chiqborda;
	int popdentro, popborda;
	
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while (cin >> n)
	{
		if (!n) return 0;
		
		cin >> xc >> yc >> r1 >> r2;
		
		r1 *= r1;
		r2 *= r2;
		
		chiqdentro = chiqborda = popdentro = popborda = 0;
		
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> chiqx >> chiqy >> popx >> popy;
			
			int d1 = dist(chiqx, chiqy);
			int d2 = dist(popx, popy);
			
			if (d1 < r1) ++chiqdentro;
			else if (r1 <= d1 && d1 <= r2) ++chiqborda;
			
			if (d2 < r1) ++popdentro;
			else if (r1 <= d2 && d2 <= r2) ++popborda;
		}
		
		if (chiqdentro != popdentro)
		{
			if (chiqdentro > popdentro) cout << "C > P\n";
			else cout << "P > C\n";
		}
		else
		{
			if (chiqborda != popborda)
			{
				if (chiqborda > popborda) cout << "C > P\n";
				else cout << "P > C\n";
			}
			else cout << "C = P\n";
		}
	}
}
