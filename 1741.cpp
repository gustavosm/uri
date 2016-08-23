#include <bits/stdc++.h>

using namespace std;
#define TAM 101

#define INF INT_MAX
typedef int ll;
bool iszerodivision(char op, ll b)
{
	return (op == '/') && (b == 0);
}
ll eval(char op, ll a, ll b)
{
	if (op == '+')
	return b + a;
	else if (op == '-')
	return b - a;
	else if (op == '/')
	return b / a;
	else
	return b * a;
}
int main()
{
	string prefix;

	int tam;
	while (getline(cin, prefix))
	{
		tam = prefix.size();
		stack<int> opstack;
		int flag = 1;
		int res = 0;
		if (tam & 1)
		{
			for (int i = tam - 1; i >= 0; --i)
			{
				char ch = prefix[i];
				if (ch != ' ')
				{
					if (isdigit(ch))
						opstack.push(ch - '0');
					else
					{
						int a = 0, b = 0;
						bool invalid_operator = (ch != '+' && ch != '-' && ch != '*' && ch != '/');
						if ((int)opstack.size() < 2 || invalid_operator)
						{
							flag = 0;
							break;
						}
						else
						{
							res = 0;
							a = opstack.top();
							opstack.pop();
							b = opstack.top();
							opstack.pop();
							if (!iszerodivision(ch, a))
							{
								res = eval(ch, a, b);
								if (res == INF)
								{
									flag = 0;
									break;
								}
							}
							else
							{
								res = 0;
								flag = 2;
							}
							opstack.push(res);
						}
					}
				}
			}
			if (!flag) 
				printf("Invalid expression.\n");
			else
			{
				if (flag == 1)
				{
					if (opstack.size() == 1)
					{
						res = opstack.top();
						printf("The answer is %d.\n", res);
					}
					else
						printf("Invalid expression.\n");
				}
				else cout << "Division by zero.\n";
			}
		}
		else cout << "Invalid expression.\n";
		prefix.clear();
	}

	return 0;
}
