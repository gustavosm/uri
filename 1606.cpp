#include <bits/stdc++.h>
 
using namespace std;
int main ()
{
    int n, k, i;
    int x;
    vector<int> ocorrencia;
    int flag;
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while (scanf("%d %d", &n, &k) != EOF)
    {
        ocorrencia.assign(k+1,0);
        flag = 0;
        while (n--)
        {
        	scanf("%d", &x);
            if (ocorrencia[x] == 0)
            {
                if (flag == 1) cout<<" "<<x;
                else cout<<x;
            }
            ocorrencia[x] = 1;
            flag = 1;
        }
        cout<<'\n';
        ocorrencia.clear();
    }
}
