#include <bits/stdc++.h>

using namespace std;

int n;

int binarysearch(int v[], int chave)
{
	int inf = 0;
	int sup = n - 1;
	int meio;
	 
	while (inf <= sup)
    {
        meio = inf + (sup-inf)/2;
        if (chave == v[meio])
            return meio;
        else if (chave < v[meio])
            sup = meio-1;
        else
            inf = meio+1;
    }
    return -1;
}

int main ()
{
	int ans[100010];
	
	int acc;
	int medida;
	
	int qtde;
	
	while(cin >> n)
	{
		acc = 0;
		qtde = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> medida;
			acc+=medida;
			ans[i] = acc;
		}
		if (acc % 3 != 0) cout << "0\n";
		else
		{
			acc/=3;
			for (int i = 0 ; i < n; i++)
			{
				if (binarysearch(ans, ans[i]+acc) != -1)
					if (binarysearch(ans, ans[i]+2*acc) != -1) qtde++;
			}
			cout << qtde << '\n';
		}
	}
}

