#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int li;
li tonum(char *n)
{
	li num = 0;
	for (int i = 0 ; i < strlen(n); i++)
	{
		num*=10;
		num+=n[i] - '0';
	}
	return num;
}
int main()
{
	char num[100];
	
	int i;
	
	li n;
	
	while (1)
	{
		cin >> num;
		if (num[2] == 'e')
		{
			if (num[4] == '\0')
			{
				int lim = num[3] - '0';
				for(i = 2; i <= lim; i++) 
					num[i] = '0';
				num[i] = '\0';
			}
			else
			{
				if (num[5] == '\0')
				{
					int lim = num[3] - '0';
					int lim2 = num[4] - '0';
					for(i = 2; i <= lim*10 + lim2 ; i++)
						num[i] = '0';
					num[i] = '\0';
				}
			}
			
		}
		if (strcmp(num, "0") == 0 ) return 0;
		if (strlen(num) > 5) cout << "1.000000\n";
		else
		{
			n = tonum(num);
			
			printf("%lf\n", (double)(1 - 3.0/(double)n));
		}
		
	}
}
