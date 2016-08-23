#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstdio>
  
using namespace std;
void itoa(int n, char *num, int base)
{
    int i = 0;
    int t;
    while(n>0)
    {
        num[i] = n%base+'0';
        i++;
        n/=base;
    }
    num[i] = '\0';
    t = i;
    for (i = 0; i <= t/2; i++)
    {
        char aux = num[i];
        num[i] = num[t-i-1];
        num[t-i-1] = aux;
    }
    num[t] = '\0';
}
int valido(int x)
{
    int v[10] = {0,0,0,0,0,0,0,0,0,0};
    if (x == 0) return 0;
    if (x < 1000) return 1;
    int cont = 0;
    while(x>0)
    {
        v[x%10]++;
        x/=10;
    }
    for (int i = 0 ; i < 10 ; i++)
    {
        if (v[i] >= 1) cont++;
    }
    return cont >= 2;
}
int cmp(const void *a, const void *b)
{
    return (*(char *)a - (*(char *)b));
}
  
int maior_numero_com_digitos_de(char num[])
{
    int n;
      
    n = strlen(num);
    if (n < 4)
    {
        for (n = n; n < 4; n++)
        {
            num[n] = '0';
        }
        num[n] = '\0';
    }
    qsort(num,n,sizeof(char),cmp);
      
    for (int i = 0; i < n/2; i++)
    {
        char aux = num[i];
        num[i] = num[n-i-1];
        num[n-1-i] = aux;
    }
    return atoi(num);
}
int menor_numero_com_digitos_de(char num[])
{
    qsort(num,strlen(num),sizeof(char),cmp);
    return atoi(num);
}
int krapekar(int X) {
  
   int cnt = 0;
   char num[60];
  
   while (X != 6174) {
          
        itoa(X,num,10);
        int maior = maior_numero_com_digitos_de(num);
  
        int menor = menor_numero_com_digitos_de(num);
  
        X = maior - menor;
  
        cnt = cnt + 1;
   }
  
   return cnt;
  
}
int main ()
{
      
    int num;
    int cases;
    cin >> cases;
    for (int i = 1 ; i <= cases; i++)
    {
        cin >> num; 
        cout << "Caso #" << i << ": ";
        if (valido(num))
            cout << krapekar(num) << '\n';
        else cout << "-1\n";
    }
}
