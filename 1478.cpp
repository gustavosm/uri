#include <bits/stdc++.h>

using namespace std;
int main ()
{
	int n;
	
	while(1)
	{
		cin >> n;
		
		if (!n) return 0;
		
		for (int i = 1 ; i <= n; i++)
		{
			for (int j = 1 ; j <= n; j++)
			{
				printf("%3d", abs(i-j) + 1);
				if (j != n) printf(" ");
			}
			printf("\n");
		}
		printf("\n");
	}
}
