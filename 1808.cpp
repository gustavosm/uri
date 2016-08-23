#include <bits/stdc++.h>


using namespace std;


int main()
{
	string in;
	
	double media;
	int notas;
	cout.precision(2);
	
	while(cin >> in)
	{
		media = 0.0;
		notas = 0;
		for (int i = 0 ; i < in.size(); i++)
		{
			if (in[i] == '1')
			{
				if (i == in.size() - 1) media += 1., ++notas;
				else if (in[i + 1] == '0') media += 10., ++notas, ++i;
				else media += 1., ++notas;
			}
			else media += (double)(in[i] - '0'), ++notas;
		}
		
		cout << fixed << media / (double) notas << '\n';
	}
}
