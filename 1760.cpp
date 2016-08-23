#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	double qtde = 3;
	double area;
	double aux;
	int cont;
	while(cin >> n)
	{
		area = (double)(n*n)*sqrt(3)/4;
		
		qtde = 3;
		cont = 0;
		for (double i=(double)n/3;cont <= 30;)
		{			
			area+=qtde*(i*i*sqrt(3)/4);
			i/=3;
			qtde*=4;
			cont++;
		}
		printf("%.2lf\n", area);
	}
}
