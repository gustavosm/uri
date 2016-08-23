x#include <bits/stdc++.h>

using namespace std;
typedef struct no
{
	int info;
	struct no* left;
	struct no* right;
}No;

No *h;
bool found;


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
No* rmv(No* h1, int info)
{
	if (!h1) return NULL;
	No* aux;
	No* ant;
	if (h1->info == info)
	{
		if (!h1->left && !h1->right)
		{
			free(h1);
			return NULL;
		}
		else
		{
			if (h1->left && !h1->right)
			{
				aux = h1->left;
				free(h1);
				h1 = NULL;
				return aux;
			}
			else
			{	
				if (h1->right && !h1->left)
				{
					aux = h1->right;
					free(h1);
					h1 = NULL;
					return aux;
				}
				else
				{
					aux = h1->left;
					ant = NULL;
					while(aux->right) 
					{
						ant = aux;
						aux = aux->right;
					}
					
					if (ant) ant->right = aux->left;
					
					aux->right = h1->right;
					if (aux == h1->left)
					aux->left = h1->left->left;
					else aux->left = h1->left;
					
					free(h1);
					h1 = NULL;
					return aux;
				}
			}
		}
	}
	else if (h1->info > info)
		h1->left = rmv(h1->left, info);
	else
		h1->right = rmv(h1->right, info);
	return h1;
}
int passos;
int n;
void pre(No* h1)
{
	if (h1)
	{
		if (passos > 0) cout << ' ';
		passos++;
		cout << h1->info;
		pre(h1->left);
		pre(h1->right);
	}
}
void inf(No* h1)
{
	if (h1)
	{
		inf(h1->left);
		if (passos > 0) cout << ' ';
		passos++;
		cout << h1->info;
		inf(h1->right);
	}
}
void pos(No* h1)
{
	if (h1)
	{
		pos(h1->left);
		pos(h1->right);
		if (passos > 0) cout << ' ';
		passos++;
		cout << h1->info;
	}
}

void search(No* h1, int info)
{
	if (h1)
	{
		if (h1->info == info)
		{
			found = true;
		}		
		else if (h1->info > info)
			search(h1->left, info);
	
		else
			search(h1->right, info);
	}
}
int main()
{
	char c;
	char s[50];
	int info;
	h = NULL;
	n = 0;
	while((scanf("%c", &c) != EOF))
	{
		if (c == 'I')
		{
			c = getchar();
			if (c == ' ')
			{
				scanf("%d", &info);
				h = insert(h, info);
				n++;
			}
			else
			{
				scanf("%s", s);
				passos = 0;
				inf(h);	
				cout << '\n';
			}
		}
		else if (c == 'P')
		{
			c = getchar();
			if (c == ' ')
			{
				scanf("%d", &info);
				cout << info << ' ';
				found = false;
				search(h, info);
				if (!found) cout << "nao ";
				cout << "existe\n";
			}
			else
			{				
				scanf("%s", s);
				passos = 0;
				if (strcmp(s, "EFIXA") == 0) pre(h);
				else pos(h);
				cout << '\n';
			}
		}
		else
		{
			scanf("%d", &info);
			h = rmv(h, info);
			n--;
		}	
		getchar();
	}	
}

