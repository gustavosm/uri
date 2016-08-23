#include <bits/stdc++.h>


using namespace std;


map<string, long long> m;

long long toint(string &a)
{
	long long ret = 0;
	for (int i = 0 ; i < a.size(); ++i)
	{
		ret *= 10LL;
		ret += (long long)(a[i] - '0');
	}
	return ret;
}
int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	string in;
	string salva;
	stringstream ss;
	
	string aux, aux2, aux3, op1, op2;
	
	while (getline(cin, in))
	{
		salva = in;
		ss << in;
		
		ss >> aux;
		ss >> op1;
		ss >> aux2;
		
		if (ss >> op2)
		{
			ss >> aux3;
			
			if (isdigit(aux2[0]))
			{
				if (isdigit(aux3[0]))
				{
					long long a = toint(aux2), b = toint(aux3);
					m[aux] = a + b;
				}
				else
				{
					long long a = toint(aux2);
					m[aux] = a + m[aux3];
				}
			}
			else
			{
				if (isdigit(aux3[0]))
				{
					long long b = toint(aux3);
					m[aux] = m[aux2] + b;
				}
				else
					m[aux] = m[aux2] + m[aux3];
			}
		}
		else
			m[aux] = toint(aux2);
		ss.clear();
	}
	ss << salva;
	ss >> aux;
	cout << m[aux] << '\n';
	m.clear();
	ss.clear();
	
}
