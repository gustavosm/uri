#include <bits/stdc++.h>

using namespace std;
int main()
{
	long long a;
	int vet[10003];
	
	
	while(1)
	{
		scanf("%lld", &a);
		if (!a) return 0;
		
		memset(vet, 0, sizeof(vet));
		int ans = 0;
		while(!vet[a])
		{
			vet[a] = true;
			
			a*= a;
			a/= 100;
			a%= 10000;
			++ans;
		}
		printf("%d\n", ans);
		
	}
}
