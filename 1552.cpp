#include <bits/stdc++.h>
 
using namespace std;
typedef pair<double, double> dd;
typedef pair<double, pair<int, int > > dii;
vector< dii > EdgeList;
vector< dd > coordPessoas;
vector<int> pset;
 
void initSet(int N) 
{
        pset.assign(N,0);
        for (int i=0;i<N;i++) pset[i] = i;
}
 
int findSet(int i) 
{
        return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}
 
bool isSameSet(int i, int j) 
{
        return findSet(i) == findSet(j);
}
 
void unionSet(int i, int j) 
{
        pset[findSet(i)] = findSet(j);
}
 
int main () 
{
		ios_base :: sync_with_stdio(0);
		
        int n, t;
        scanf ("%d",&t);
        while (t--) 
        {
                double minDist=0;
               
                scanf("%d",&n);
                for (int k=0;k<n;k++) 
                {
                        double a, b;
                        scanf ("%lf %lf",&a,&b);
                        coordPessoas.push_back(dd(a,b));
                }
                for (int i=0; i<n;i++) 
                {
                        pair<double,double> p1 = coordPessoas[i];
                        for (int j=0;j<n;j++) 
                        {
                                if (j!=i) 
                                {
                                        pair<double,double> p2 = coordPessoas[j];
                                        double dist = sqrt((p2.first - p1.first)*(p2.first - p1.first) + (p2.second - p1.second)*(p2.second - p1.second));
                                        EdgeList.push_back(dii(dist / 100.0, pair<int,int>(i,j)));         
                                }              
                        }
                }
               
                sort(EdgeList.begin(), EdgeList.end());
                initSet(n);
                for (int i=0;i<(int)EdgeList.size();i++) 
                {
                        pair<double, pair<int,int> > topo = EdgeList[i];
                       
                        if (!isSameSet(topo.second.first, topo.second.second)) 
                        {
                                unionSet(topo.second.first, topo.second.second);
                                minDist+=topo.first;
                        }
                }
                printf("%.8lf\n", minDist);
                
                int d = (int) minDist;
                minDist -= d;
                int d1 = (int)(minDist * 100);
                if (d1 < 10)
                	printf("%d,0%d\n", d, d1);
                else
                	printf("%d,%d\n", d, d1);
               
                EdgeList.clear();
                coordPessoas.clear();
                pset.clear();
        }       
}
