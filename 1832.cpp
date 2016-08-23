#include <bits/stdc++.h>

using namespace std;

int oct(string x)
{
	int ans = 0;
	
	int sz = x.size();
	
	for (int i = 0; i < sz; ++i)
		ans += (x[i] - '0') * (int)pow(8, sz - i - 1);
	return ans;
}

int main()
{
	string in, s2;
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	while (getline(cin, in))
	{
		stringstream ss;
		ss << in;
		
		while (ss >> s2)
		{
			int o = oct(s2);
			
			switch(o)
			{
				case 64: cout << ' '; break;
				case 129: cout << 'a'; break;
				case 130: cout << 'b'; break;
				case 131: cout << 'c'; break;
				case 132: cout << 'd'; break;
				case 133: cout << 'e'; break;
				case 134: cout << 'f'; break;
				case 135: cout << 'g'; break;
				case 136: cout << 'h'; break;
				case 137: cout << 'i'; break;
				case 145: cout << 'j'; break;
				case 146: cout << 'k'; break;
				case 147: cout << 'l'; break;
				case 148: cout << 'm'; break;
				case 149: cout << 'n'; break;
				case 150: cout << 'o'; break;
				case 151: cout << 'p'; break;
				case 152: cout << 'q'; break;
				case 153: cout << 'r'; break;
				case 162: cout << 's'; break;
				case 163: cout << 't'; break;
				case 164: cout << 'u'; break;
				case 165: cout << 'v'; break;
				case 166: cout << 'w'; break;
				case 167: cout << 'x'; break;
				case 168: cout << 'y'; break;
				case 169: cout << 'z'; break;
				case 193: cout << 'A'; break;
				case 194: cout << 'B'; break;
				case 195: cout << 'C'; break;
				case 196: cout << 'D'; break;
				case 197: cout << 'E'; break;
				case 198: cout << 'F'; break;
				case 199: cout << 'G'; break;
				case 200: cout << 'H'; break;
				case 201: cout << 'I'; break;
				case 209: cout << 'J'; break;
				case 210: cout << 'K'; break;
				case 211: cout << 'L'; break;
				case 212: cout << 'M'; break;
				case 213: cout << 'N'; break;
				case 214: cout << 'O'; break;
				case 215: cout << 'P'; break;
				case 216: cout << 'Q'; break;
				case 217: cout << 'R'; break;
				case 226: cout << 'S'; break;
				case 227: cout << 'T'; break;
				case 228: cout << 'U'; break;
				case 229: cout << 'V'; break;
				case 230: cout << 'W'; break;
				case 231: cout << 'X'; break;
				case 232: cout << 'Y'; break;
				case 233: cout << 'Z'; break;
				default: cout << (char)((o - 240) + '0');
			}
		}
		cout << '\n';
	}
}
