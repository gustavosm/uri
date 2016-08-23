#include <bits/stdc++.h>


using namespace std;
vector<string> v;
int n;

int mindist(string y)
{
	int min = INT_MAX;
	int pos = -1;
	int i, j;
	for (int z = 0; z < n; ++z)
	{
		string x = v[z];
		int match = 0;
		if ((int)x.size() - (int)y.size() <= 0)
		{
			for (i = 0; i < x.size(); ++i)
			{
				for (j = i; j < y.size(); ++j)
				{
					if (x[i] == y[j]) break;
				}
				if (i > (int)y.size()) break;
				if (j == (int)y.size()) ++match;
			}
			if (min > match && match < x.size() && match < y.size())
			{
				min = match;
				pos = z;
			}
		}
	}
	if (pos == -1) return pos;
	if ((int)v[pos].size() - (int)y.size() > 1) return -1;
	return pos;
}

int main()
{
	string y;
	int q;
	v.reserve(10005);
	while(cin >> n)
	{
		v.clear();
		for (int i = 0 ; i < n ; ++i)
		{
			cin >> y;
			v.push_back(y);
		}
		cin >> q;
		
		while (q--)
		{
			cin >> y;
			
			int r = mindist(y);
			
			if (r == -1) cout << y << " is unknown\n";
			else if (v[r] == y) cout << y << " is correct\n";
			else cout << y << " is a misspelling of " << v[r] << '\n';
		}
	}
}
