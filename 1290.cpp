#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);
	
    vector< pair<int, vector<int> > > v;
    vector<int> caixa;
    int n, m;
    int x,y,z, i, j, k, v1, flag, cont;
    
    while (1)
    {
        cin>>n>>m;
        if (!n && !m) return 0;
        cin>>x>>y>>z;
        caixa.push_back(x);
        caixa.push_back(y);
        caixa.push_back(z);
        sort(caixa.begin(), caixa.end());
        v1 = x*y*z;
        while (m--)
        {
            cin>>i>>j>>k;
            if ((i*j*k) - v1 >=0)
            {
                v.push_back(make_pair(i*j*k, vector<int> ()));
                v[v.size()-1].second.push_back(i);
                v[v.size()-1].second.push_back(j);
                v[v.size()-1].second.push_back(k);
                sort(v[v.size()-1].second.begin(), v[v.size()-1].second.end());
            }
        }
 
        flag=0;
        sort(v.begin(),v.end());
        int ans = 141241;
        cont=0;
        for (i=0; i<v.size(); i++)
        {
            cont=1;
            if (v[i].second[0] >= caixa[0] && 
				v[i].second[1] >= caixa[1] &&
				v[i].second[2] >= caixa[2] &&
				v[i].first >= v1)
			{
				for (j=i+1; j<v.size(); j++)
				{
					if(v[i].second[0] == v[j].second[0])
						if(v[i].second[1] == v[j].second[1])
						    if(v[i].second[2] == v[j].second[2])
						        cont++;
					if(cont==n) break;
				}
				if (cont==n)
				{
					ans = v[i].first - v1;
					flag=1;
					break;
				}
			}
        }
        if (!flag) cout<<"impossible"<<'\n';
        else cout << ans << '\n';
 
        v.clear();
        caixa.clear();
    }
}
