#include <bits/stdc++.h>

using namespace std;
typedef struct plano
{
	int a;
	int b;
	int c;
	int d;
}Plano;
struct planeta
{
	int id;
	int quantos;
	
	planeta(){id = 0; quantos = 0;}
	planeta(int _id, int _quantos) : id(_id), quantos(_quantos){}
	
	bool operator < (const planeta &other) const
	{
		return quantos < other.quantos;
	}
};
vector<planeta> p;

void add(int new_id)
{
	for (int i = 0 ; i < p.size(); ++i)
	{
		if (p[i].id == new_id)
		{
			++p[i].quantos;
			return;
		}
	}
	p.push_back(planeta(new_id, 1));
}
int main()
{
	Plano v[505];
	
	vector<int> ids;
	int a;
	int b;
	int c;
	int d;
	int m;
	int n;
	
	while (cin >> n >> m)
	{
		for (int i = 0 ; i < n  ; i++)
		{
			cin >> v[i].a >> v[i].b >> v[i].c >> v[i].d;
			p.push_back(planeta(i + 1, 0));
		}
		for (int i = 0 ; i < m ; i++)
		{
			cin >> a >> b >> c;
			ids.clear();
			for (int j = 0; j < n ; j++)
			{
				if (v[j].a * a + v[j].b * b + v[j].c * c == v[j].d)
					ids.push_back(j);
			}
			sort(ids.begin(), ids.end());
			int new_id = 0;
			for (int k = 0 ; k < ids.size(); ++k)
			{
				new_id *= 10;
				new_id += ids[k];
			}
			cout << "planeta " << i << " no id " << new_id << '\n';
			add(new_id);
		}
		cout << (*max_element(p.begin(), p.end())).quantos << '\n';
		p.clear();
		
	}
	return 0;
}
