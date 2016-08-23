#include <bits/stdc++.h>

using namespace std;
int main()
{
	int h, m, s;
	int tempo;
	int v;
	
	char c;
	
	double dist = 0.0;
	
	tempo = 0;
	
	while (cin >> h >> c >> m >> c >> s)
	{
		c = getchar();
		if (c == ' ')
		{
			if (tempo != 0) dist+= (double)(((3600 * h + 60 * m + s) - tempo) * v) / 3600;
			cin >> v;
			tempo = 3600 * h + 60 * m + s;
		}
		else
		{
			dist+= (double)(((3600 * h + 60 * m + s) - tempo) * v) / 3600;
			printf("%02d:%02d:%02d %.2lf km\n", h, m, s, dist);
			tempo = h * 3600 + 60 * m + s;
		}
	}
}
