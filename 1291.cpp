#include<bits/stdc++.h>


using namespace std;

int main()
{
	double a;
	double a1;
	double a2;
	double a3;

	while(scanf("%lf", &a) != EOF)
	{
		a3 = (-a) * a * (3 * (sqrt(3) - 4) + 2 * M_PI)/3.0;
		a2 = 4 * (a * a * (1 - M_PI/4) - (a3) / 2);
		a1 = a * a - a2 - a3;
		printf("%.3lf %.3lf %.3lf\n",a1,a2,a3);
	}
	return 0;
}
