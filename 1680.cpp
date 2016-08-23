#include <bits/stdc++.h>

using namespace std;
int main ()
{
	string s1;
	int x;
	int y;
	while(getline(cin,s1))
	{
		cout << "300 420 moveto\n310 420 lineto\n";
		x = 310;
		y = 420;
		for (int i = 0 ; i < s1.size(); i++)
		{
			if (i == 0)
			{
				if (s1[i] == 'V') y+=10;
				else y-=10;
			}
			else
			{
				if (s1[i] == 'V')
				{
					if (s1[i-1] == 'A')
					{
						x+=10;
					}
					else
					{
						y+=10;
					}
				}
				else
				{
					if (s1[i-1] == 'A')
					{
						y-=10;
					}
					else
					{
						x-=10;
					}
				}
			}
			cout << x << " " << y << " lineto\n";
		}
		cout << "stroke\nshowpage\n";
	}
}
