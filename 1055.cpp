#include <bits/stdc++.h>

using namespace std;
int cmp(const void* a, const void* b)
{
	return (*(int *) a - (*(int *) b));
}
int main()
{
	int v[60];
	int v2[60];
	int n;
	int cases;
	int k;
	int ans;
	int teste = 1;
	
	cin >> cases;
	while(cases--)
	{
		cin >> n;
		for (int i = 0 ; i < n ; i++)
			cin >> v[i];
		qsort(v, n, sizeof(int), cmp);
		ans = 0;
		k = 0;
		for (int i = n / 2 + n & 1, j = n - 1; i >= 0; i--, j--, k++)
		{
			v2[i] = v[i];
			k++;
			v2[i + k] = v[j];
		}
		for (int i = 0; i < n - 1; i++)
		{
			cout << "Fazendo " << v2[i] << " com " << v2[ i + 1] << '\n';
			ans+= abs(v2[i] - v2[i + 1]);
		}
		cout << "Case " << teste << ": " << ans << '\n';
		teste++;
		
	}
}
