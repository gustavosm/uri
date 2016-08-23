#include <bits/stdc++.h>


using namespace std;


string decide(string &s1, string &s2)
{
	if (s1 == s2) return "empate\n";
	
	if (s1 == "tesoura" && s2 == "papel") return "rajesh\n";
	else if (s2 == "tesoura" && s1 == "papel") return "sheldon\n";
	
	if (s1 == "papel" && s2 == "pedra") return "rajesh\n";
	else if (s2 == "papel" && s1 == "pedra") return "sheldon\n";
	
	if (s1 == "pedra" && s2 == "lagarto") return "rajesh\n";
	else if (s1 == "lagarto" && s2 == "pedra") return "sheldon\n";
	
	if (s1 == "lagarto" && s2 == "spock") return "rajesh\n";
	else if (s1 == "spock" && s2 == "lagarto") return "sheldon\n";
	
	if (s1 == "spock" && s2 == "tesoura") return "rajesh\n";
	else if (s2 == "spock" && s1 == "tesoura") return "sheldon\n";
	
	if (s1 == "tesoura" && s2 == "lagarto") return "rajesh\n";
	else if (s2 == "tesoura" && s1 == "lagarto") return "sheldon\n";
	
	if (s1 == "lagarto" && s2 == "papel") return "rajesh\n";
	else if (s1 == "papel" && s2 == "lagarto") return "sheldon\n";
	
	if (s1 == "papel" && s2 == "spock") return "rajesh\n";
	else if (s1 == "spock" && s2 == "papel") return "sheldon\n";
	
	if (s1 == "spock" && s2 == "pedra") return "rajesh\n";
	else if (s1 == "pedra" && s2 == "spock") return "sheldon\n";
	
	if (s1 == "pedra" && s2 == "tesoura") return "rajesh\n";
	return "sheldon\n";
}

int main()
{
	string s1, s2;
	
	int cases;
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> s1 >> s2;
		
		cout << decide(s1, s2);
	}
}
