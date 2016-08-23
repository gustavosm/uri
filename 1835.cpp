#include <bits/stdc++.h>
 
using namespace std;
#define MAX 1000
 
int visitados[MAX], sucessor[MAX];
vector < vector <int> > g;
int cont = 0;
 
void bfs (int ini)
{
    queue <int> f;
 
    visitados[ini] =  true;
    f.push (ini);
 
    while (!f.empty())
    {
        int a = f.front();
        f.pop ();
 
        for (int i=0; i < (int) g[a].size(); i++)
            if (!visitados[g[a][i]])
            {
                visitados[g[a][i]] = true;
                f.push (g[a][i]);
            }
    }
}
 
 
int main()
{
    //freopen("entrada.txt","r",stdin);
    int Numero_ponto_Cidade, Numero_Estradas_Feitas;
    int Numero_Casos, Vertice_X, Vertice_Y;
 
    scanf ("%d", &Numero_Casos);
 
    for (int k=1; k <= Numero_Casos; k++)
    {
        scanf ("%d %d", &Numero_ponto_Cidade, &Numero_Estradas_Feitas);
 
        g.assign(Numero_ponto_Cidade + 1, vector<int>());
 
        for (int i=0; i < Numero_Estradas_Feitas; i++)
        {
            scanf ("%d %d", &Vertice_X, &Vertice_Y);
 
            g[Vertice_X].push_back (Vertice_Y);
            g[Vertice_Y].push_back (Vertice_X);
 
        }
 
        cont = 0;
 
        for (int i=0; i < MAX; i++) visitados[i] = false;
 
        bfs(1);
 
        for (int i=1; i <= Numero_ponto_Cidade; i++)
        {
            if (visitados[i] == false)
            {
                bfs(i);
                cont++;
            }
        }
 
        if (cont == 0) printf ("Caso #%d: a promessa foi cumprida\n", k);
        else printf ("Caso #%d: ainda falta(m) %d estrada(s)\n", k, cont);
 
        for (int i=1; i < Numero_ponto_Cidade+1; i++) g[i].clear();
    }
}
