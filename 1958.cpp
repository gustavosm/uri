#include <bits/stdc++.h>


using namespace std;


string altera(char *str)
{
	string ret = (string)str;
	if (ret[0] != '-') ret = "+" + ret;
	return ret;
}

int main()
{
	long double s;
	char str[16];
	while (cin >> s)
	{
		sprintf(str, "%.4LE", s);
		
		cout << altera(str) << '\n';
	}
}
