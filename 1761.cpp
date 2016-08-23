#include <bits/stdc++.h>

#define PI 3.141592654

using namespace std;
int main ()
{
	double a;
	double b;
	double c;
	
	while (scanf("%lf %lf %lf", &a, &b, &c) != EOF)
	{
		printf("%.2lf\n", 5*(tan(PI*a/180)*b + c));
	}
	return 0;
}
