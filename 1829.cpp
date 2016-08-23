#include <bits/stdc++.h>

#define E 2.71828182846

using namespace std;



int main()
{
	long long a, b, c;
	
	
	char aux;
	
	
	int cases;
	int lucas = 0;
	int pedro = 0;
	
	string ans;
	
	cin >> cases;
	
	while(cases--)
	{
		cin >> a >> aux >> b;
		cin >> c >> aux;
		
		if ((double)c/E > a && c > b) ++pedro, ans.push_back('p');
		else
		{
			if (b*log(a) < log(2*M_PI)/2.0 + (c + 1/2.0) * log(c) - c) ++pedro, ans.push_back('p');
			else ++lucas, ans.push_back('l');
		}
	}
	if (lucas > pedro) cout << "Campeao: Lucas!\n";
	else if (pedro > lucas) cout << "Campeao: Pedro!\n";
	else cout << "A competicao terminou empatada!\n";
	
	int n = ans.size();
	for (int i = 0 ; i < n ; ++i)
	{
		cout << "Rodada #" << (i + 1) << ": ";
		if (ans[i] == 'p') cout << "Pedro ";
		else cout << "Lucas ";
		cout << "foi o vencedor\n";
	}
}
