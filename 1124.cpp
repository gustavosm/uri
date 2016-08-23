#include <bits/stdc++.h>

#define PI 3.14159265
using namespace std;
int cabemdiagonal(int l, int c, int r1, int r2)
{
	if (min(l, c) >= 2*r1 + 2*r2) return 1;
	if (min(l, c) >= 2*max(r1, r2) && max(l, c) >= 2*r1 + 2*r2) return 1;
	
	if (c <= 2*r1 || c <= 2*r2 || l <= 2*r1 || l <= 2*r2) return 0;
	if (sqrt(l*l + c*c) < 2*r1 + 2*r2) return 0;
	if (c > l)
	{
		l = l ^ c;
		c = l ^ c;
		l = l ^ c;
	}
	
	double xcr1 = r1;
	double xcr2 = c - r2;
	double ycr1 = r1;
	double ycr2 = l - r2;
	
	if (sqrt((xcr1 - xcr2) * (xcr1 - xcr2) + (ycr1 - ycr2) * (ycr1 - ycr2)) < r1 + r2) return 0;
	
	return 1;
}
int main()
{
	int l, c, r1, r2;
	int dim;
	
	while(1)
	{
		cin >> l >> c >> r1 >> r2;
		
		if (!l && !c && !r1 && !r2) return 0;
		
			
		if (cabemdiagonal(l, c, r1, r2)) cout << "S\n";
		else cout << "N\n";
	}
}
