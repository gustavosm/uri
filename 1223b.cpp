#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
using namespace std;

typedef struct {
	double yi, xf, yf;
}aleta;

double distanciaPontoReta (double x, double y, double x1, double y1, double x2, double y2);

int main() 
{

	int n, i;
	double l, h, distancia, maior;

	aleta atual, proximo;

	while (cin >> n) 
	{

		cin >> l >> h;

		maior = l;

		cin >> atual.yi >> atual.xf >> atual.yf;

		for (i=1; i<=n; i++) 
		{
			if (i!=n)
				cin >> proximo.yi >> proximo.xf >> proximo.yf;

			if (i%2 != 0) 
			{
				distancia = l - atual.xf;

				if (distancia < maior)
					maior = distancia;
					
				if (i!=n) 
				{
					distancia = distanciaPontoReta (atual.xf, atual.yf, proximo.xf, proximo.yf, l, proximo.yi);

					if (distancia < maior)
						maior = distancia;
				}
			} 
			else 
			{
				distancia = atual.xf;

				if (distancia < maior)
					maior = distancia;
					
				if (i!=n) 
				{
					distancia = distanciaPontoReta (atual.xf, atual.yf, proximo.xf,	proximo.yf, 0, proximo.yi);

					if (distancia < maior)
						maior = distancia;
				}
			}

			atual.yi = proximo.yi;
			atual.xf = proximo.xf;
			atual.yf = proximo.yf;
		}

		cout << setprecision(2) << fixed << maior << endl;

	}
	return 0;
}

double distanciaPontoReta (double x, double y, double x1, double y1, double x2, double y2) 
{
	return fabs((y1 - y2) * x + (x2 - x1) * y + x1 * y2 - x2 * y1) / sqrt((y1 - y2) * (y1 - y2) + (x2 - x1) * (x2 - x1));
}
