#include <bits/stdc++.h>

#define EPS 0.0000001
using namespace std;
struct pto
{
	double x;
	double y;
	bool operator < (const pto &other) const
	{
		if (fabs(y - other.y) > EPS) return y < other.y;
		else return x < other.x;
	}
};

int main()
{
	pto v[10010];
	
	int n;
	double diff1;
	double diff2;
	int pos1;
	int pos2;
	
	double mind;
	
	while(1)
	{
		cin >> n;
		if (!n) return 0;
		
		for (int i = 0 ; i < n ; i++)
		{
			cin >> v[i].x >> v[i].y;
		}
		if (n <= 1) cout << "INFINITY\n";
		else
		{
			sort(v, v + n);
			
			mind = (double)INT_MAX;
						
			for (int i = 0 ; i < n - 1; i++)
			{
				double aux = hypot(v[i].x - v[i + 1].x, v[i].y - v[i + 1].y);
				
				for (int j = i + 2; j < n ; ++j)
				{
					double x = hypot(v[i].x - v[j].x, v[i].y - v[j].y);
					if (aux > x)
						aux = x;
					else break;
				}
				mind = min(mind, aux);
			}
			if (mind >= 10000.0) cout << "INFINITY\n";
			else printf("%.4lf\n", mind);
		}
		
	}
}
