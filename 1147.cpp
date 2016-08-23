#include <bits/stdc++.h>


using namespace std;


int dr[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dr2[] = {1, 1};
int dc2[] = {-1, 1};

int val(int i, int j)
{
	return i >= 0 && i < 8 && j >= 0 && j < 8;
}

int getx(string &in)
{
	return in[0] - '1';
}
int gety(string &in)
{
	return in[1] - 'a';
}

int main()
{
	int tab[8][8];
	int c = 1;
	
	string in;
	
	while (1)
	{
		cin >> in;
		if (in == "0") return 0;
		
		int x = getx(in);
		int y = gety(in);
		memset(tab, 0, sizeof tab);
		for (int i = 0 ; i < 8 ; ++i)
		{
			cin >> in;
			tab[getx(in)][gety(in)] = 1;
		}
		int ans = 0;
		for (int i = 0 ; i < 8 ; ++i)
		{
			if (val(x + dr[i], y + dc[i]))
			{
				int flag = 0;
				for (int j = 0 ; j < 2; ++j)
				{
					if (val(x + dr[i] + dr2[j], y + dc[i] + dc2[j]))
					{
						if (tab[x + dr[i] + dr2[j]][y + dc[i] + dc2[j]])
						{
							flag = 1;
							break;
						}
					}
				}
				if (!flag) ++ans;
			}
		}
		cout << "Caso de Teste #" << c++ << ": " << ans << " movimento(s).\n";
	}
}
