#include <bits/stdc++.h>


#define EPS 1e-4
using namespace std;


int v[100006];

int n;
int area;

double calc(double v2)
{
	double ans = 0.0;
	for (int i = n - 1; i >= 0; --i)
	{
		if (v2 >= v[i]) return ans;
		
		ans += (double)v[i] - v2;
	}
	return ans;
}

double bs()
{
	double b = 0.;
	double e = (double)v[n - 1];
	double mid;
	
	while (b <= e)
	{
		mid = (b + e) / 2.0;
		double c = calc(mid);
		
		if (fabs(c - (double)area) < EPS) return mid;
		
		if (c < area) e = mid;
		else b = mid;
		
	}
	return -1;
}
int main()
{
	char buf[100];
	while (scanf("%d %d", &n, &area))
	{
		if (!n && !area) return 0;
		int sum = 0;
		for (int i = 0 ; i < n ; ++i) scanf("%d", &v[i]), sum += v[i];
		
		
		if (sum < area) puts("-.-");
		else if (sum == area) puts(":D");
		else
		{
			sort(v, v + n);
			sprintf(buf, "%.4lf", bs());
			puts(buf);
		}
	}
}
