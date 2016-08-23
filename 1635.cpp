#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int m1;
	
	int percent1, percent2;
	char c;
	int prc;
	int result;
	
	map<string,int> m;
	
	string s;
	string s2;
	
	stringstream ss;
	
	while(cin >> n >> m1)
	{
		for (int i = 0; i < n ;i++)
		{
			cin >> s;
			cin >> percent1 >> c >> percent2;
			m[s] = percent1*10 + percent2;
		}
		getchar();
		for (int i = 1; i <= m1; i++)
		{
			getline(cin, s);
			ss << s;
			ss >> s2;
			prc = m[s2];
			
			while(ss >> s2)
			{
				if (s2 == ">=" || s2 == ">" || s2 == "<=" || s2 == "<" || s2 == "=")
				{	
					ss >> result;
					result*= 10;
					if (s2 == ">=")
						cout << "Guess #" << i << (prc >= result? " was correct." : " was incorrect.") << '\n';
			
					else if (s2 == "<=") 
						cout << "Guess #" << i << (prc <= result? " was correct." : " was incorrect.") << '\n';
				
					else if (s2 == ">")
						cout << "Guess #" << i << (prc > result? " was correct." : " was incorrect.") << '\n';
		
					else if (s2 == "<")
						cout << "Guess #" << i << (prc < result? " was correct." : " was incorrect.") << '\n';
				
					else if (s2 == "=")
						cout << "Guess #" << i << (prc == result? " was correct.": " was incorrect.") << '\n';
				}
				if (s2 == "+") continue;
				prc+=m[s2];
			}
			ss.clear();
		} 
		m.clear();
	}
}
