#include <bits/stdc++.h>

using namespace std;

int main () 
{
	int numero;
    char romanos[15][3] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int arabicos[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    while(cin >> numero) 
    {
        int indice = (sizeof(arabicos) / sizeof(arabicos[0])) - 1;
        while (numero > 0) 
        {
            if (numero >= arabicos[indice]) 
            {
                printf("%s", romanos[indice]);
                numero -= arabicos[indice];
            } 
            else 
                --indice;
        }
        printf("\n");
    }
    return 0;
}
