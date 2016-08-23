#include <iostream>
#include <cctype>
#include <cstring>	
#include <cstdio>
 
using namespace std;
 
int primdig(char *cpf)
{
    int soma = 0;
    int k = 0;
    for (int i = 0; i <= strlen(cpf)-1; i++)
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
    for (int i = strlen(cpf)-1; i >= 0; i--)
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
    	for (int i = 0 ; i < strlen(cpf); i++)
    	{
    		if (i && i%3 == 0) cout << '.';
    		cout << cpf[i];
    	}
    	cout << '-' << primdig(cpf) << secdig(cpf) << '\n';
    }
    return 0;
}
