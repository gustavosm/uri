#include <bits/stdc++.h>


using namespace std;


int v[4];

int main()
{
	while (cin >> v[0])
	{
		for (int i = 1; i < 4; ++i)
			cin >> v[i];
			
		sort(v, v + 4);
		int flag = 0;
		do
		{
			int a = v[0], b = v[1], c = v[2];
			
			if (a < b + c && abs(b - c) < a)
			{
				if (b < a + c && abs(a - c) < b)
				{
					if (c < a + b && abs(a - b) < c)
					{
						cout << "S\n";
						flag = 1;
						break;
					}
				}
			}
		}while(next_permutation(v, v + 4));
		
		if (!flag) cout << "N\n";
	}
}
