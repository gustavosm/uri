#include <bits/stdc++.h>


using namespace std;
double todouble(string s)
{
	double ans = 0.0;
	int ponto = -1;
	
	for (int i = 0 ; i < s.size(); ++i)
	{
		if (s[i] == '.')
		{
			ponto = i;
			continue;
		}
		
		if (ponto > -1)
		{
			ans += (s[i] - '0') * pow(10, ponto - i);
		}
		else
		{
			ans *= 10;
			ans += (double)(s[i] - '0');
		}
	}
	return ans;
}
int main()
{
	string s1;
	string cpf;
	string num;
	
	string ans[2];
	for (int c = 0 ; c < 2; ++c)
	{
		int jaachei = 0;
		getline(cin, s1);
		for (int i = 0 ; i < s1.size(); ++i)
		{
			if (isdigit(s1[i]))
			{
				if (cpf.size() < 11) cpf.push_back(s1[i]);
			
				else
					num.push_back(s1[i]);
			}
			else if (s1[i] == '.')
			{
				++i;
				num.push_back('.');
				int cont = 0;
				while (i < s1.size())
				{
					if (isdigit(s1[i]))
					{
						while (cont < 2 && i < s1.size() && isdigit(s1[i]))
						{
							++cont;
							num.push_back(s1[i]);
							++i;
						}
				
						ans[c] += num;
						num.clear();
					}
					if (s1[i] == '.' || cont == 2)
					{
						i = s1.size();
						break;
					}
					++i;
				}
			}
			else
			{
				if (num.size() > 0)
				{
					ans[c] += num;
					num.clear();
				}
			}
		}
		if (!jaachei)
			if (num.size() > 0)
				ans[c] += num;
		num.clear();
	}
	cout << "cpf " << cpf << '\n';
	cout << setprecision(2) << fixed << (todouble(ans[0]) + todouble(ans[1])) << '\n';

}
