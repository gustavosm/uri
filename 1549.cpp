#include <bits/stdc++.h>

#define PI M_PI

using namespace std;


int main()
{
	int cases;
	
	double pessoas, qtde, b, B, H;
	
	cin >> cases;
	
	while (cases--)
	{
		cin >> pessoas >> qtde >> b >> B >> H;
		
		double novov = (qtde / pessoas); 
		
		double r2t = pow(novov * 3.0 * (B - b)/ (PI  * H) + b * b * b, 1.0 / 3.0);
		
		double novoH = novov * 3.0 / (PI *(r2t * r2t + r2t * b + b * b));
		
		cout << setprecision(2) << fixed << novoH << '\n';
	}
}
