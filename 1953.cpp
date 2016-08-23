#include <bits/stdc++.h>



using namespace std;

#define getcx getchar_unlocked
typedef long long ll;


int m;
int intruso;
int ehd;
int epr;
char s[5];
 
inline int inp( int &n ) 
{
    n = 0;
    ll ch = getcx();
    if (ch == -1) return 0;
    
    while (ch < '0' || ch > '9') ch = getcx();
    
    while(  ch >= '0' && ch <= '9' )
            n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
    return 1;
}
inline void inp2() 
{
	int n = 0;
    ll ch = getcx();
    while (ch < 'A' || ch > 'Z') ch = getcx();
    while(  ch >= 'A' && ch <= 'Z' )
    	s[n++] = ch, ch = getcx();
    s[n] = '\0';
}
int main()
{
	int n;
	//ios_base :: sync_with_stdio(0); cin.tie(0);
	
	while (inp(n))
	{
		ehd = 0;
		epr = 0;
		intruso = 0;
		
		for (int i = 0 ; i < n ; ++i)
		{
			inp(m);
			inp2();
			if (strcmp(s, "EHD") == 0) ++ehd;
			else if (strcmp(s, "EPR") == 0) ++epr;
			else ++intruso;
		}
		
		cout << "EPR: " << epr << "\nEHD: " << ehd << "\nINTRUSOS: " << intruso << '\n';
	}
}
