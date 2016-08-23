#include <bits/stdc++.h>


using namespace std;


int soma(int n)
{
	int ret = 0;
	
	while (n)
	{
		ret += (n % 10);
		n /= 10;
	}
	return ret;
}

int main()
{
	string s;
	
	int cases;
	
	while (1)
	{
		cin >> cases;
		if (!cases) return 0;
		while (cases--)
		{
			cin >> s;
		
			int uns = 0;
			int zeros = 0;
			for (int i = 0 ; i < s.size(); i += 2)
				zeros += (s[i] - '0');
			for (int i = 1 ; i < s.size(); i += 2)
				uns += (s[i] - '0');
		
			zeros = soma(zeros);
			uns = soma(uns);
		
			cout << zeros + uns << '\n';
		}
	}
}
