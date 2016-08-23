#include <bits/stdc++.h>

using namespace std;
long converte(string s)
{
	long ans = 0;
	int tam = s.size();
	int pos;
	
	for (int i = 0 ; i < tam; i++)
	{
		pos =  (s[i] - '0');
		if (pos)
			ans+= pos * pow(2, tam - 1 - i);
	}
	return ans;
}
long mdc(long a, long b)
{
	if (b == 0) return a;
	return mdc(b, a%b);
}
int main()
{
	string s1, s2;
	
	int pair = 1;
	
	int cases;
	long num1;
	long num2;
	
	cin >> cases;
	getchar();
	
	while(cases--)
	{
		getline(cin, s1);
		getline(cin, s2);
		
		num1 = converte(s1);
		num2 = converte(s2);
		
		cout << "Pair #" << pair << ": ";
		pair++;
		if (mdc(num1, num2) > 1) cout << "All you need is love!\n";
		else cout << "Love is not all you need!\n";
	}
}
