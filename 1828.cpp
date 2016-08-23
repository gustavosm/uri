#include <bits/stdc++.h>

using namespace std;


int main()
{
	string s1, s2;
	
	int caso = 1;	
	int n;
	
	cin >> n;
	
	while (n--)
	{
		cin >> s1 >> s2;
		cout << "Caso #" << caso++ << ": ";
		if (s1 == s2) cout << "De novo!\n";
		else if (s1 == "tesoura" && s2 == "papel") cout << "Bazinga!\n";
		else if (s2 == "tesoura" && s1 == "papel") cout << "Raj trapaceou!\n";
		else if (s1 == "papel" && s2 == "pedra") cout << "Bazinga!\n";
		else if (s2 == "papel" && s1 == "pedra") cout << "Raj trapaceou!\n";
		else if (s1 == "pedra" && s2 == "lagarto") cout << "Bazinga!\n";
		else if (s2 == "pedra" && s1 == "lagarto") cout << "Raj trapaceou!\n";
		else if (s1 == "lagarto" && s2 == "Spock") cout << "Bazinga!\n";
		else if (s2 == "lagarto" && s1 == "Spock") cout << "Raj trapaceou!\n";
		else if (s1 == "Spock" && s2 == "tesoura") cout << "Bazinga!\n";
		else if (s2 == "Spock" && s1 == "tesoura") cout << "Raj trapaceou!\n";
		else if (s1 == "tesoura" && s2 == "lagarto") cout << "Bazinga!\n";
		else if (s2 == "tesoura" && s1 == "lagarto") cout << "Raj trapaceou!\n";
		else if (s1 == "lagarto" && s2 == "papel") cout << "Bazinga!\n";
		else if (s2 == "lagarto" && s1 == "papel") cout << "Raj trapaceou!\n";
		else if (s1 == "papel" && s2 == "Spock") cout << "Bazinga!\n";
		else if (s2 == "papel" && s1 == "Spock") cout << "Raj trapaceou!\n";
		else if (s1 == "Spock" && s2 == "pedra") cout << "Bazinga!\n";
		else if (s2 == "Spock" && s1 == "pedra") cout << "Raj trapaceou!\n";
		else if (s1 == "pedra" && s2 == "tesoura") cout << "Bazinga!\n";
		else if (s2 == "pedra" && s1 == "tesoura") cout << "Raj trapaceou!\n";
	}
}
