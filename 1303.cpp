#include <bits/stdc++.h>

using namespace std;
typedef struct team
{
	int id;
	int ptos;
	int pto_marcado;
	int pto_recebido;
}Team;

int cmp(const void *a, const void *b)
{
	Team t = (*(Team *) a);
	Team t2 = (*(Team *) b);
	
	double ct_avg1;
	double ct_avg2;
	
	if (t.ptos != t2.ptos)
		return t.ptos - t2.ptos;
	else
	{
		ct_avg1 = (t.pto_recebido == 0? (double)t.ptos : (double)t.pto_marcado / (double)t.pto_recebido);
		ct_avg2 = (t2.pto_recebido == 0? (double)t2.ptos : (double)t2.pto_marcado / (double)t2.pto_recebido);
		
		if (ct_avg1 != ct_avg2)
		{
			if (ct_avg1 > ct_avg2) return 1;
			else return -1;
		}
		else
		{
			if (t.pto_marcado != t2.pto_marcado) return t.pto_marcado - t2.pto_marcado;
			else
				return t.id - t2.id;
		}
	}
}
int main ()
{
	int time1;
	int time2;
	int pt1;
	int pt2;
	int n;
	int jogo;
	int inst = 1;
	int pl = 0;
	
	Team v[105];
	
	while(1)
	{
		cin >> n;
		if (!n) return 0;
		if (pl) cout << '\n';
		pl = 1;
		
		for (int i = 0 ; i < n ; i++)
		{
			v[i].id = i + 1;
			v[i].ptos = 0;
			v[i].pto_marcado = 0;
			v[i].pto_recebido = 0;
		}
		jogo = n*(n - 1) / 2;
		
		for (int i = 0 ; i < jogo; i++)
		{
			cin >> time1 >> pt1 >> time2 >> pt2;
			--time1;
			--time2;
			if (pt1 > pt2)
			{
				v[time1].ptos+= 2;
				v[time1].pto_marcado+= pt1;
				v[time1].pto_recebido+= pt2;
				v[time2].ptos++;
				v[time2].pto_marcado+= pt2;
				v[time2].pto_recebido+= pt1;
			}
			else
			{
				v[time2].ptos+= 2;
				
				v[time1].pto_marcado+= pt1;
				v[time1].pto_recebido+= pt2;
				
				v[time1].ptos++;
				
				v[time2].pto_marcado+= pt2;
				v[time2].pto_recebido+= pt1;
			}
		}
		qsort(v, n, sizeof(Team), cmp);
		
		cout << "Instancia " << inst << '\n';
		inst++;
		for (int i = n - 1 ; i >= 0 ; i--)
		{
			cout << v[i].id;
			if ( i > 0) cout << ' ';
		}
		cout << '\n';
	}
}
