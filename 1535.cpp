#include <bits/stdc++.h>

using namespace std;

int mimq(double sqr)
{
	return (int)sqr + 1;
}

int main()
{
	string s;
	stringstream ss;
	double n1;
	double n2;
	
	while(getline(cin, s))
	{		
		ss << s;
		
		ss >> n1;
		n2 = -1.0;
		while(ss >> n2);
		
		if (n2 == -1.0)
		{
			int ans1 = mimq(sqrt(n1));
			double t = sqrt(ans1*ans1 - n1);
			if (t == (int) t) cout << max(ans1, (int) t) << ' ' << min(ans1, (int) t) << '\n';
			else
			{
				ans1 = (int)n1;
				if (ans1 & 1) cout << "Spinster Number.\n";
				else cout << "Bachelor Number.\n";
			}
		}
		else
		{
			int ans = 0;
			for (int i = n1; i <= n2; i++)
			{				
				int ans1 = mimq(sqrt(n1));
				double t = sqrt(ans1*ans1 - n1);
				if (t != (int) t) 
				{
					ans1 = (int)n1;
					if (!(ans1 & 1)) ans++;
				}
			}
			cout << ans << '\n';
		}
		ss.clear();
	}
}
