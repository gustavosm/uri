#include <bits/stdc++.h>

#define INCR 1
#define DECR 2
#define EQ 3
#define NONE 4
using namespace std;

int **v;

int seq(int x, int y)
{
	
	if (y - x <= 3)
	{
		int incr, decr, equal;
		incr = decr = equal = 0;
		int tot = 0;
		for (int i = x; i <= y - 1; ++i, ++tot)
		{
			if (v[i][0] >= v[i + 1][0]) ++decr;
			if (v[i][0] <= v[i + 1][0]) ++incr;
			if (v[i][0] == v[i + 1][0]) ++equal;
		}
		
		if (equal == tot) return EQ;
		if (decr == tot) return DECR;
		if (incr == tot) return INCR;
		return NONE;
	}
	int mid = (x + y) / 2;
	int rec1 = seq(x, mid);
	int rec2 = seq(mid + 1, y);
	
	if (rec1 == rec2)
	{
		if (v[mid][0] == v[mid + 1][0])
			return rec1;
		if (v[mid][0] < v[mid + 1][0])
			if (rec1 == INCR) return rec1;
			else return NONE;
		if (v[mid][0] > v[mid + 1][0])
			if (rec1 == DECR) return rec1;
			else return NONE;
	}
	if (rec1 == EQ) return rec2;
	if (rec2 == EQ) return rec1;
	
	return NONE;
}
int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	int n;
	int x, y;
	int query, op;
	int ans;
	int temp;
	while (cin >> n)
	{
		v = (int **) malloc(n * sizeof(int *));
		for (int i = 0 ; i < n ; ++i)
			v[i] = malloc(sizeof(int));
		for (int i = 0 ; i < n ; ++i)
			cin >> v[i][0];
		cin >> query;
		
		while (query--)
		{
			cin >> op;
			switch(op)
			{
				case 0:
					cin >> x >> y;
					--x; --y;
					temp = v[x];
					v[x] = v[y];
					v[y] = temp;
					break;
				case 1:
					cin >> x >> y;
					--x;
					v[x] = y;
					break;
				case 2:
					cin >> x >> y;
					--x;
					v[x] = v[x + n];
					v[x + n] 
					break;
				case 3:
					cin >> x;
					--x;
					v[x] = &(*v[x + 1]);
					break;
				case 4:
					cin >> x >> y;
					--x; --y;
					
					ans = seq(x, y);
					if (ans == INCR) cout << "NON DECREASING\n";
					else if (ans == DECR) cout << "NON INCREASING\n";
					else if (ans == EQ) cout << "ALL EQUAL\n";
					else cout << "NONE\n";
					break;
			}
			
			//exibe();
		}
	}
}
