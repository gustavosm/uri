#include <bits/stdc++.h>

using namespace std;
int mdc(int a, int b)
{
	if (!b) return a;
	return mdc(b, a%b);
}
int main()
{
	long long n, a, b;
	int ans;
	
	while(1)
	{
		cin >> n >> a >> b;
		if (!n && !a && !b) return 0;
		
		
		cout << n/a + n/b - n/((a*b)/mdc(a,b)) << '\n';
	}
}
