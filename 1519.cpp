#include <bits/stdc++.h>

using namespace std;


map<string, int> m;
set<string> st;

vector<string> v[26];

string word[26];
int freq[26];

int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	string s, s2;
	
	stringstream ss;
	
	while (getline(cin, s))
	{
		if (s[0] == '.') return 0;
		
		string aux = s;
		
		ss << s;
		int i = 0;
		while (ss >> s2)
			++m[s2];
		
		memset(freq, 0, sizeof freq);
		for (int j = 0 ; j < 26; ++j) word[j] = "";
		
		for (map<string, int> :: iterator it = m.begin(); it != m.end(); ++it)
		{
			int t = (it->first).size();
			int f = (it->second) * (t - 2);
			int c = it->first[0] - 'a';
			if (f > freq[c] && t > 2)
			{
				freq[c] = f;
				word[c] = it->first;
			}
		}
		ss.clear();
		
		ss << aux;
		
		int flag = 0;
		while (ss >> s2)
		{
			if (flag) cout << ' ';
			if (word[s2[0] - 'a'] == s2)
				cout << s2[0] << '.', st.insert(s2);
			else cout << s2;
			
			flag = 1;
		}
		ss.clear();
		cout << '\n' << st.size() << '\n';
		for (set<string> :: iterator it = st.begin(); it != st.end(); ++it)
		{
			string aux2 = (*it);
			cout << aux2[0] << ". = " << aux2 << '\n';
		}
		m.clear();
		st.clear();
		for (int i = 0 ; i < 26; ++i)
			v[i].clear();
	}
}
