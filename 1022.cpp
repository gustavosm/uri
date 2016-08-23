#include <iostream>
#include <cctype>
#include <stdlib.h>
using namespace std;
int mdc(int a, int b)
{
	return (b ? mdc(b, a % b) : a);
}
int main ()
{
    int i,t, aux1, aux2, aux3, aux4,aux5, aux6,aux7;
    char barra1, barra2, op;
    
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    cin>>t;
    while (t>0)
    {
        cin>>aux1>>barra1>>aux2>>op>>aux3>>barra2>>aux4;
        if (op=='+')
        {
            aux5=aux1*aux4+aux2*aux3;
            aux6=aux2*aux4;
            aux7=mdc(abs(aux5),abs(aux6));
           cout<<aux5<<"/"<<aux6<<" = "<<aux5/aux7<<"/"<<aux6/aux7<<endl;
        }
        if (op=='-')
        {
            aux5=aux1*aux4-aux2*aux3;
            aux6=aux2*aux4;
            aux7=mdc(abs(aux5),abs(aux6));
           cout<<aux5<<"/"<<aux6<<" = "<<aux5/aux7<<"/"<<aux6/aux7<<endl;
        }
        if (op=='*')
        {
            aux5=aux1*aux3;
            aux6=aux2*aux4;
            aux7=mdc(abs(aux5),abs(aux6));
           cout<<aux5<<"/"<<aux6<<" = "<<aux5/aux7<<"/"<<aux6/aux7<<endl;
        }
        if (op=='/')
        {
            aux5=aux1*aux4;
            aux6=aux2*aux3;
            aux7=mdc(abs(aux5),abs(aux6));
           cout<<aux5<<"/"<<aux6<<" = "<<aux5/aux7<<"/"<<aux6/aux7<<endl;
        }
        t--;
    }
    return 0;
}
