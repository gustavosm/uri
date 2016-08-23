#include <bits/stdc++.h>
 
using namespace std;
int mdc (int a, int b)
{
    if (b == 0) return a;
    if (a > b) return mdc(b, a%b);
    else return mdc(a, b%a);
}
int alpha(string x)
{
    for (int i = 0  ; i < x.size(); i++)
        if (!isalpha(x[i])) return 0;
    return 1;
}
void trata(string &x)
{
	for (int i = 0 ; i < x.size(); i++)
	{
		if (!isalpha(x[i])) x[i] = ' ';
	}
}
void up(string &x)
{
	for (int i = 0 ; i < x.size(); i++)
		x[i] = toupper(x[i]);
}
int main ()
{
	ios_base :: sync_with_stdio(0);
    string x, x1;
    int w = 0;
    int b = 0;
    int auxw=0;
    map<string,int>m;
    while (cin >> x1)
    {
		trata(x1);
		stringstream ss;
		ss << x1;
		while (ss >> x)
		{
		    if (x == "BULLSHIT") 
		   	{
		   		b++;
		   		auxw = w;
		   		m.clear();
		   	}
		    else
		    {
		    	up(x);
		    	if (!m[x])
		    	{
					w++;
					m[x]++;
		    	}
		    }
        }
    }
    w = auxw;
    if (w == 0) cout << "0 / " << b << '\n';
    else if (b == 0) cout << "0 / 0\n";
    else
    {
   		int md = mdc(w,b);
    	cout << w/md << " / " << b/md << endl;
    }
}
