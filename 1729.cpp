#include <bits/stdc++.h>


using namespace std;

int contains(string s, char c)
{
	for (int i = 0 ; i < s.size()  ; i++)
		if (s[i] == c) return 1;
		
	return 0;
}
double returntime(string s)
{
	int i = 0;
	int h = 0;
	int m = 0;
	int seg = 0;
	double ans;
	
	while(s[i] != ':')
	{
		h*= 10;
		h+= (int)(s[i] - '0');
		i++;
	}
	i++;
	while(s[i] != ':')
	{
		m*= 10;
		m+= (int)(s[i] - '0');
		i++;
	}
	i++;
	while(i < s.size())
	{
		seg*= 10;
		seg+= (int)(s[i] - '0');
		i++;
	}
	m+= h * 60;
	
	ans = (double)m;
	
	ans+= (double)seg / 60.;
	
	return ans;
	
}
int main()
{
	string x;
	string s2;
	double n;
	double d;
	int time;
	stringstream ss;
	double ans;
	
	
	
	cin >> n >> d;
	d/= (double) n;
	
	while(cin >> time)
	{
		getchar();
		getline(cin, x);
		
		if (contains(x, '-')) printf("%3d: -\n", time);
		else
		{
			ss << x;
			ans = 0.0;
			while(ss >> s2)
				ans+= returntime(s2) / d;
				
				
			ans/= (double) n;
			
			int min = (int) ans;
			
			ans-= min;
			
			int seg;
			
			double a = ans * 60.;
			
			seg = (int) a;
			a-= seg;
			if (a >= 0.5) seg++;
			if (seg == 60)
			{
				seg = 0;
				min++;
			}
			if (seg < 10) printf("%3d: %d:0%d min/km\n", time, min, seg);
			else printf("%3d: %d:%d min/km\n", time, min, seg);
			ss.clear();
		}
	}
}
