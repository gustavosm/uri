#include <bits/stdc++.h>
 
 
using namespace std;

int eh_vogal(char c)
{
    return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
}
int main()
{
    ios_base :: sync_with_stdio(0);
     
    int qle[10005];
     
    char vogal[10005];
    char consoante[10005];
    char aux[10005];
     
    int cases; 
    int c = 1;
    int op;
    int avanca_v, avanca_c, qtde_v, qtde_c;
    int query;
    int mudou;
    int qtde;
    int v, cn;
    int n, i;
     
    scanf("%d", &cases);
    getchar_unlocked();
    while (cases--)
    {
    	scanf("%s", aux);
    	scanf("%d", &query);
    	getchar_unlocked();
        avanca_c = 0;
        avanca_v = 0;
        qtde_v = 0;
        qtde_c = 0;
         
        n = strlen(aux);
        for (i = 0 ; i < n; ++i)
        {
            if (eh_vogal(aux[i]))
            {
                vogal[qtde_v] = (aux[i]);
                ++qtde_v;
                qle[i] = 0;
            }
            else
            {
                consoante[qtde_c] = (aux[i]);
                ++qtde_c;
                qle[i] = 1;
            }
        }
        
        mudou = 0;
        printf("Caso #%d:\n", c);
        ++c;
        while (query--)
        {
        	scanf("%d", &op); getchar_unlocked();
             
            if (op == 2)
            {
                v = avanca_v;
                cn = avanca_c;
                for (i = 0 ; i < n; ++i)
                {
                    if (qle[i])
                    {
                        putchar_unlocked(consoante[cn]); 
                        cn = (cn + 1);
                        if (cn == qtde_c) cn = 0;
                    }
                    else
                    {
                        putchar_unlocked(vogal[v]);
                        v = ( v + 1 );
                        if (v == qtde_v) v = 0;
                    }
                }
                putchar_unlocked('\n');
            }
            else if (op == 1)
            {
            	scanf("%d", &qtde); getchar_unlocked();
                if (qtde_c)
                	avanca_c = (avanca_c + qtde_c - qtde % qtde_c) % qtde_c;
            }
            else if (op == 0)
            {
            	scanf("%d", &qtde); getchar_unlocked();
                if (qtde_v)
                	avanca_v = (avanca_v + qtde_v - qtde % qtde_v) % qtde_v;
            }           
        }
    }
}
