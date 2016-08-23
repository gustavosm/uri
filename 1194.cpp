#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;
map<char, int> m;

struct arv
{
	char info;
	struct arv* r;
	struct arv* l;
};
typedef struct arv Arv;
void pos(Arv* h)
{
	if (!h) return;
	pos(h->l);
	pos(h->r);
	printf("%c",h->info);
}

Arv* insert(Arv *h, char info)
{
	if (!h)
	{
		h = (Arv*) malloc(sizeof(Arv));
		h->info = info;
		h->r = NULL;
		h->l = NULL;
	}
	else
	{
		if (m[h->info] < m[info])
			h->r = insert(h->r, info);
		else h->l = insert(h->l, info);
	}
}

Arv* libera(Arv* h)
{
	if (!h) return NULL;
	libera(h->l);
	libera(h->r);
	free(h);
	h = NULL;
}

int main ()
{
	char s1[55];
	char s2[55];
	Arv* h;
	int n;
	int cases;
	scanf("%d", &cases);
	getchar();
	while (cases--)
	{
		h = NULL;
		scanf("%d %s %s\n", &n, s1 ,s2);
		
		for (int i = 0 ; i < n; i++)
			m[s2[i]]=i;
		for (int i = 0 ; i < n; i++)
		{
			h = insert(h,s1[i]);
		}
		pos(h);
		cout << '\n';
		libera(h);
		m.clear();
		h = NULL;
	}
}
