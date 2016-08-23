#include <bits/stdc++.h>

using namespace std;

int main()
{
	int in[1002];
	
	int x;
	int y;
	double sum;
	
	int n;
	
	while(1)
	{
		cin >> n;
		if (!n) return 0;
		
		sum = 0.0;
		for (int i = 0 ; i < n ; i++)
		{
			scanf("%d.%d", &x, &y);
			in[i] = x*100 + y;
			
			sum+= (double)in[i];
		}
		
		sum/= (double) n;
		
		double sumM = 0.0;
		double summ = 0.0;
		
		for (int i = 0 ; i < n; i++)
		{
			if (sum < (double)in[i]) sumM+= (int)(in[i] - sum) / 100.0;
			else summ+= (int)(sum - in[i]) / 100.0;
		}
		
		printf("$%.2lf\n", max(sumM, summ));
	}
}
