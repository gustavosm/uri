#include <bits/stdc++.h>

using namespace std;


map<string, int> m;

int n;

int pilha[3][102];

bool funcao(int a, int b, int c) 
{
	string s;
	s.push_back(a + '0');
	s.push_back(b + '0');
	s.push_back(c + '0');
	
	if(a == b && b == c && c == n)
		{m[s] = 1; return true;}
	
	int x = m[s];
	
	if (x > 0) return (x == 1? true : false);
	
	if(a < n && pilha[0][a]%3 == 0 && funcao(a+1, b, c)) {m[s] = 1; return true;}
	if(b < n && pilha[1][b]%3 == 0 && funcao(a, b+1, c)) {m[s] = 1; return true;}
	if(c < n && pilha[2][c]%3 == 0 && funcao(a, b, c+1)) {m[s] = 1; return true;}
	if(a < n && b < n && (pilha[0][a]+pilha[1][b])%3 == 0 && funcao(a+1, b+1, c)) {m[s] = 1; return true;}
	if(a < n && c < n && (pilha[0][a]+pilha[2][c])%3 == 0 && funcao(a+1, b, c+1)) {m[s] = 1; return true;}
	if(b < n && c < n && (pilha[1][b]+pilha[2][c])%3 == 0 && funcao(a, b+1, c+1)) {m[s] = 1; return true;}
	if(a < n && b < n && c < n && (pilha[0][a]+pilha[1][b]+pilha[2][c])%3 == 0 && funcao(a+1, b+1, c+1)) {m[s] = 1; return true;}
	
	m[s] = 2;
	return false;
}

int main()
{
	while(1)
	{
		cin >> n;
		if (!n) return 0;
		
		for (int i = 0 ; i < n; i++)
		{
			for (int j = 0 ; j < 3; j++)
			{
				cin >> pilha[j][i];
			}
		}
		
		if (funcao(0,0,0)) cout << "1\n";
		else cout << "0\n";
		m.clear();
	}
}
