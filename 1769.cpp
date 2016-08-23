#include <iostream>
#include <cctype>
#include <cstdio>

using namespace std;

int primdig(char *cpf)
{
	int soma = 0;
	int k = 0;
	for (int i = 0; i <= 10; ++i)
	{
		if (isdigit(cpf[i]))
		{
			k++;
			soma+=(cpf[i] - '0')*k;
		}
	}
	return (soma%11)%10;
}

int secdig(char *cpf)
{
	int soma = 0;
	int k = 10;
	for (int i = 10; i >= 0; --i)
	{
		if (isdigit(cpf[i]))
		{
			soma+=(cpf[i] - '0')*(11 - k);
			k--;
		}
	}
	return (soma%11)%10;
}

int main()
{
	char cpf[15];
	while (scanf("%s", cpf) != EOF)
	{
		if (primdig(cpf) == cpf[12] - '0' && secdig(cpf) == cpf[13] - '0') cout << "CPF valido\n";
		else cout << "CPF invalido\n";
	}
	return 0;
}
