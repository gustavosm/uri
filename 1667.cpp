#include <bits/stdc++.h>

using namespace std;
int main ()
{
	vector< pair<string, string> > m;
	string aux;
	string aux2;
	while(getline(cin,aux))
	{
		stringstream ss;
		ss << aux;
		while (ss >> aux2)
		{
			if (aux2 == "<br>" || aux2 == "<hr>")
				m.push_back(make_pair(aux2, "\n"));
			else m.push_back(make_pair(aux2, aux2));
		}		
	}
	aux2 = "";
	int taml = 0;
	for (int i = 0 ; i < m.size(); i++)
	{
		aux = m[i].first;
		if (aux == "<hr>")
		{
			if (aux2 != "<br>" && aux2 != "<hr>") cout << '\n';
			for (int i = 0 ; i < 80 ; i++) cout << '-';
			cout << '\n';
			aux2 = "<br>";
			taml = 0;
			continue;
		}
		else
		{
			if (aux.size() > 80)
			{
				taml = 0;
				for (int i = 0 ; i < aux.size(); i++)
					cout << aux[i];
				cout << '\n';
				aux2 = aux;
				continue;
			}
			if (taml+aux.size() > 80)
			{
				cout << '\n';
				taml = 0;
			}
		 	cout << m[i].second;
			if (aux != "<br>") taml+=aux.size();
			if (i < m.size() - 1 && m[i].second != "\n" && m[i+1].second != "\n" && taml+m[i+1].second.size() <= 80) 
			{
				cout << " "; taml++;
			}
		}
		aux2 = aux;
	}
	cout << '\n';
	m.clear();
}

