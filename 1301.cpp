#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <sstream>
#include <map>
#include <set>

using namespace std;
#define AVN 400003
#define VTN 100002
int st[AVN];
int v[VTN];

int valor(int a)
{
	return (a > 0? 1 : (a < 0 ? -1 : 0));
}

void init(int index, int a, int b)
{
	if (a == b)
		st[index] = valor(v[a - 1]);
	else
	{
		int m = (b + a) / 2;
		init(2 * index, a, m);
		init(2 * index + 1, m + 1, b);
		
		st[index] = st[index * 2] * st[index * 2 + 1];
	}
}

void update(int index, int a, int b, int i, int x)
{
	if (i > b || i < a) return;
	
	if (a == b && b == i)
	{
		st[index] = valor(x);
		return;
	}
	int m = (a + b) / 2;
	update(2 * index, a, m, i, x);
	update(2 * index + 1, m + 1, b, i , x);
	
	st[index] = st[index * 2] * st[index * 2 + 1];
}

int query(int index, int a, int b, int i, int j)
{
	if (i > b || j < a) return 1;
	
	if (a >= i && b <= j) return st[index];
	int m = (a + b) / 2;
	int x0 = query(index * 2, a, m, i, j);
	int x1 = query(index * 2 + 1, m + 1, b, i, j);
	
	return x1 * x0;
	
}

int main()
{
	string c;
	int a;
	int b;
	int n;
	int q;
	
	while(cin >> n >> q)
	{
		for (int i = 0 ; i < n; i++)
			cin >> v[i];
			
		init(1, 1, n);
		for (int i = 0 ; i < q; i++)
		{
			cin >> c >> a >> b;
			
			if (c[0] == 'P')
			{
				int answer = query(1, 1, n, a, b);
				cout << (answer == 1? '+' : (answer == 0? '0' : '-'));
			}
			else if (c[0] == 'C')
				update(1, 1, n, a, b);
		}
		cout << '\n';
	}
}

