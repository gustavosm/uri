#include <bits/stdc++.h>

using namespace std;

int main() 
{
	int x;
	int n;
	int A[64], m = 0;
	int freq[24];
	while (cin >> n) 
	{
		m = 0;
		memset(freq, 0, sizeof freq);
		int ret = 0x3f3f3f3f;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			++freq[x + 11];
		}
		for (int i = 0  ; i < 24 ; ++i)
		{
			freq[i] = freq[i] & 1;
			if (freq[i]) A[m++] = i;
		}
		for (int i = 0; i < m; i++)
			A[i + m] = A[i] + 24;
		
		if (m == 0)	ret = 0;
		
		for (int i = 0; i < m; ++i) 
		{
			int c = 0;
			for (int j = 0; j < m; j += 2)
				c += A[i+j+1] - A[i+j];
			ret = min(ret, c);
		}
		cout << ret << '\n';
	}

	return 0;
}
