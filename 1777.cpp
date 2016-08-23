#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int cmp(const void *a, const void *b)
{
	return (*(int *) a ) - (*(int *) b);
}
int main()
{
	ios_base :: sync_with_stdio(0);
	
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	int v[10005];
	
	int cases;
	int n;
	int c;
	int x;
	int y;
	int e;
	int caso = 1;
	scanf("%d", &cases);
	
	while(cases--)
	{
		scanf("%d %d", &n, &c);
		int aux2 = c;
		while(c--)
		{
			scanf("%d %d", &x, &y);
			
			pq.push(ii(x,y));
		}
		scanf("%d", &e);
		int aux = e;
		while(aux--)
		{
			scanf("%d", &v[e - aux - 1]);
		}
		qsort(v, e, sizeof(int), cmp);
		int ans = 0;
		for (int i = 0; i < e && !pq.empty(); )
		{
			ii u = pq.top();
			if (u.first <= v[i] && v[i] <= u.second)
			{
				ans++;
				i++;
			}
			else if (v[i] > u.second) pq.pop();
			else i++;
		}
		printf("Caso #%d: %d\n", caso, ans);
		caso++;
		while(!pq.empty()) pq.pop();
	}
}
