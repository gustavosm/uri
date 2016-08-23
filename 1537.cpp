#include <bits/stdc++.h>

using namespace std;
int main()
{
	unsigned long long fat[100002];
	
	int n;
	
	fat[3] = 1;
	for (int i = 4; i <= 100000; i++)
		fat[i] = (i*fat[i - 1]) % 1000000009;
	
	while(cin >> n)
	{
		if (!n) break;
		cout << fat[n] << '\n';
	}
}
