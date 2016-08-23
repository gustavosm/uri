#include <bits/stdc++.h>


using namespace std;


map<string, int> m;
vector<pair<int , string> > v;


int compare(pair<int, string> a, pair<int, string> b)
{
	if (a.first != b.first) return a.first < b.first;
	return a.second > b.second;
}
int main()
{
	int n;
	string s;
	string aux;
	
	//ios :: sync_with_stdio(0);
	cin.tie(0);
	
	while (1)
	{
		cin >> n;
		
		if (!n) return 0;
		getchar();
		s.clear();
		for (int i = 0 ; i < n ; ++i)
		{
			getline(cin, aux);
			s += aux;
		}		
		int tot = 0;
		for (int j = 0 ; j < s.size() - 1; ++j)
		{
			aux.clear();
			aux.push_back((s[j]));
			aux.push_back((s[j + 1]));
			++tot;
			++m[aux];
		}
		
		
		for (map<string, int> :: iterator it = m.begin(); it != m.end(); ++it)
			v.push_back(make_pair(it->second, it->first));
			
		sort(v.begin(), v.end(), compare);
		
		for (int i = v.size() - 1; i >= v.size() - 5; --i)
			cout << v[i].second << ' ' << v[i].first << ' ' << setprecision(6) << fixed << (double)(v[i].first) / (double)tot << '\n';
		cout << '\n';
		m.clear();
		v.clear();
	}
}

