#include <bits/stdc++.h>


using namespace std;

int tipo[40][2];
int qtde[10];
bool found;
int m;

void calc(int p)
{
	if (p == m + 1)
	{
		found = true;
		return;
	}
	if (found) return;
	
	if (qtde[tipo[p][0]])
	{
		--qtde[tipo[p][0]];
		calc(p + 1);
		++qtde[tipo[p][0]];
	}
	if (qtde[tipo[p][1]])
	{
		--qtde[tipo[p][1]];
		calc(p + 1);
		++qtde[tipo[p][1]];
	}
}
int val(string s)
{
	if (s == "XS") return 1;
	if (s == "S") return 2;
	if (s == "M") return 3;
	if (s == "L") return 4;
	if (s == "XL") return 5;
	return 6;
}
int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	int cases;
	int n;
	string s1, s2; 
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> n >> m;
		for (int i = 0 ; i < 10; ++i) qtde[i] = n / 6;
		
		for (int i = 1 ; i <= m; ++i)
		{
			cin >> s1 >> s2;
			
			tipo[i][0] = val(s1);
			tipo[i][1] = val(s2);
		}
		
		found = false;
		calc(1);
		
	
		if (found) cout << "YES\n";
		else cout << "NO\n";
	}
}
