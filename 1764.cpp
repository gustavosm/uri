#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
vector <int> pset;
void initSet(int N)
{
    pset.assign(N, 0);
    for (int i=0; i<N; i++) pset[i]=i;
}
int findSet (int i)
{
    return ((pset[i]==i)?i:pset[i]=findSet(pset[i]));
}
bool isSameSet (int i, int j)
{
    return findSet(i)==findSet(j);
}
void unionSet(int i, int j)
{
    pset[findSet(i)]=findSet(j);
}
int main ()
{
    int i, mst_cost, m, n, a, b, weight, mst_cost2;
    pair<int, pair<int,int> > f;
    vector<pair<int, pair<int,int> > > EdgeList;
    while (1)
    {
        cin>>m>>n;
        if (!m&&!n) return 0;
        for (i =0; i<n; i++)
        {
            scanf("%d %d %d", &a, &b, &weight);
            EdgeList.push_back(make_pair(weight, pair<int, int>(a,b)));
        }
        sort(EdgeList.begin(), EdgeList.end());
        mst_cost2=0;
        initSet(m);
        for (i=0; i<n; i++)
        {
            f = EdgeList[i];
            if (!isSameSet(f.second.first, f.second.second))
            {
                unionSet(f.second.first, f.second.second);
            	mst_cost2+=f.first;
            }
        }
        cout<<mst_cost2<<endl;
        EdgeList.clear();
    }
}
