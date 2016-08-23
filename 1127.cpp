#include <bits/stdc++.h>

using namespace std;
typedef pair<string,string> ss;
map<string, ss > m1;
vector<ss > v;
vector<ss > v2;

int main ()
{
	string nota;
	string plagio;
	string aux;
	
	stringstream buf;
	
	int flag;
	int n;
	int t;
	int lb;
	int ub;
	
	m1["C#"] = ss("C#", "Db");
	m1["D#"] = ss("D#", "Eb");
	m1["F#"] = ss("F#", "Gb");
	m1["G#"] = ss("G#", "Ab");
	m1["A#"] = ss("A#", "Bb");
	
	m1["Db"] = ss("C#", "Db");
	m1["Eb"] = ss("D#", "Eb");
	m1["Gb"] = ss("F#", "Gb");
	m1["Ab"] = ss("G#", "Ab");
	m1["Bb"] = ss("A#", "Bb");
	
	m1["D"] = ss ("D", "D");
	
	m1["B#"] = ss("C", "B#");
	m1["E"] = ss("E", "Fb");
	m1["E#"] = ss("E#", "F");
	m1["B"] = ss("B", "Cb");
	
	m1["C"] = ss("C", "B#");
	m1["Fb"] = ss("E", "Fb");
	m1["F"] = ss("E#", "F");
	m1["Cb"] = ss("B", "Cb");
	
	
	m1["A"] = ss("A", "A");
	m1["G"] = ss("G", "G");
	
	while(1)
	{
		cin >> n >> t;
		if (!n && !t) return 0;
		
		getchar();
		getline(cin, nota);
		buf << nota;
		while(buf >> aux)
			v.push_back(m1[aux]);
		buf.clear();
		
		getline(cin, plagio);
		buf << plagio;
		while(buf >> aux)
			v2.push_back(m1[aux]);
			
		buf.clear();
		
		flag = 0;
		for (int i = 0, k = 0 ; i < t && k < n;)
		{
			ub = k;
			flag = 0;
			while(v[k].first == v2[i].first || v[k].second == v2[i].second)
			{
				i++;
				k++;
				if (i >= t)
				{
					flag = 1;	
					break;
				}
				if (k >= n)
				{
					flag = 1;	
					break;
				}
			}
			if (flag) break;
			k = ub + 1;
			i = 0;
		}	
		if (flag) cout << "S\n";
		else cout << "N\n";
		
		v.clear();
		v2.clear();
	}
}
