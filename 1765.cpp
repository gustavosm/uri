#include <iostream>
#include <cstdio>

#define HIGH 5

using namespace std;
int main ()
{
	int qtde;
	int T;
	double b;
	double B;
	int size;
	
	while (1)
	{
		cin >> T;
		if (!T) break;
		size = 1;
		while (T--)
		{
			cin >> qtde;
			cin >> b >> B;
			printf("Size #%d:\nIce Cream Used: %.2lf cm2\n",size, ((double)qtde * ((b+B)*HIGH)/2));
			size++;
		}
		cout << '\n';
	}
}

