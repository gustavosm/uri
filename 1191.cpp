#include <bits/stdc++.h>
  
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
    return h;
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
    
    while (scanf("%s %s\n", s1, s2) != EOF)
    {
        h = NULL;
        
        for (int i = 0 ; i < strlen(s2); i++)
            m[s2[i]]=i;
        for (int i = 0 ; i < strlen(s1); i++)
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
