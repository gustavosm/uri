#include <bits/stdc++.h>

using namespace std;
typedef struct no
{
	int info;
	struct no* left;
	struct no* right;
}No;

No *h;

No* insert(No* h1, int info)
{
	if (!h1)
	{
		h1 = (No*) malloc(sizeof(No));
		h1->info = info;
		h1->left = NULL;
		h1->right = NULL;
	}
	else if (h1->info > info)
		h1->left = insert(h1->left, info);
	else
		h1->right = insert(h1->right, info);
	return h1;
}
void bfs(No *h1)
{
	No *v;
	queue<No* > q;
	
	cout << h1->info;
	
	q.push(h1->left);
	q.push(h1->right);
	
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		if (!v) continue;
		
		cout << ' ' << v->info;
		q.push(v->left);
		q.push(v->right);
	}
}
No* libera(No *h1)
{
	if (!h1) return NULL;
	h1->left = libera(h1->left);
	h1->right = libera(h1->right);
	free(h1);
	return NULL;
}
int main()
{
	int cases;
	int n;
	int x;
	int caso = 1;
	
	cin >> cases;
	while(cases--)
	{
		h = NULL;
		cin >> n;
		
		for (int i = 0 ; i < n ; i++)
		{
			cin >> x;
			h = insert(h, x);
		}
		cout << "Case " << caso << ":\n";
		caso++;
		
		bfs(h);
		
		cout << "\n\n";
		h = libera(h);
	}	
}

