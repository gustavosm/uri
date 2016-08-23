#include <bits/stdc++.h>

using namespace std;

int m;
char a[100010], b[200];
int proxima[55][110010];
int val(char c)
{
	return (c == tolower(c) ? c - 'a' : c - 'A' + 26);
}
int process()
{
	int num = proxima[val(b[0])][0];
	for (int idx = 1; idx < m; ++idx)
	{
		if (num == -1) return 0;
		num = proxima[val(b[idx])][num + 1];
	}
	if (num == -1) return 0;
	
	return 1;
}
int main() 
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	
	int t;
	
	scanf("%d", &t);
	int q;
	getchar();
	while (t--) 
	{
		scanf("%s", a);
		getchar();
		memset(proxima, -1, sizeof proxima);
		int n = strlen(a);
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = 0 ; j < 55; ++j)
			{
				if (j == val(a[i]))
					proxima[j][i] = i;
				else
					proxima[j][i] = proxima[j][i + 1];
			}
		}
		
		scanf("%d", &q);
		getchar();
		while (q--)
		{
			scanf("%s", b); getchar();
			m = strlen(b);
			if (process()) printf("Yes\n");
			else printf("No\n");
		}
		
	}

}
