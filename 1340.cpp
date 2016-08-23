#include <bits/stdc++.h>

using namespace std;

int main()
{
	stack<int> s;
	queue<int> q;
	priority_queue <int, vector<int>, less<int> > pq;
	
	int n;
	int op;
	int result;
	int pode_pq;
	int pode_stack;
	int pode_queue;
	
	while(cin >> n)
	{
		pode_pq = 1;
		pode_stack = 1;
		pode_queue = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> op >> result;
			
			if (op == 1)
			{
				if (pode_stack) s.push(result);
				if (pode_queue) q.push(result);
				if (pode_pq) pq.push(result);
			}
			else
			{
				if (s.top() == result)
					s.pop();
				else pode_stack = 0;
				
				if (q.front() == result)
					q.pop();
				else pode_queue = 0;
				
				if (pq.top() == result)
					pq.pop();
				else pode_pq = 0;
			}
		}
		if (pode_stack && !pode_queue && !pode_pq) cout << "stack\n";
		else if (!pode_stack && pode_queue && !pode_pq) cout << "queue\n";
		else if (!pode_stack && !pode_queue && pode_pq) cout << "priority queue\n";
		else if (pode_stack || pode_queue || pode_pq) cout << "not sure\n";
		else if (!pode_stack && !pode_queue && !pode_pq) cout << "impossible\n";
		
		while(!s.empty()) s.pop();
		while(!q.empty()) q.pop();
		while(!pq.empty()) pq.pop();
	}	
}
