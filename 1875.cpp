#include <bits/stdc++.h>


using namespace std;

int main()
{
	int v[3];
	
	char M, S;
	int cases;
	int gols;
	
	cin >> cases;
	while(cases--)
	{
		v[0] = v[1] = v[2] = 0;
		
		cin >> gols;
		while (gols--)
		{
			cin >> M >> S;
			if (M == 'G')
			{
				if (S == 'R') ++v[0];
				else v[0] += 2;
			}
			if (M == 'B')
			{
				if (S == 'G') ++v[1];
				else v[1] += 2;
			}
			if (M == 'R')
			{
				if (S == 'B') ++v[2];
				else v[2] += 2;
			}
		}
		
		int mx = *max_element(v, v + 3);
		if (v[0] == v[1] && v[0] == v[2]) cout << "trempate\n";
		else if ((mx == v[0] && mx == v[1]) || (mx == v[0] && mx == v[2]) || (mx == v[1] && mx == v[2])) cout << "empate\n";
		else
		{			
			if (mx == v[0]) cout << "green\n";
			else if (mx == v[1]) cout << "blue\n";
			else if (mx == v[2]) cout << "red\n";
		}	
	}
}
