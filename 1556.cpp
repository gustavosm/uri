#include <bits/stdc++.h>
 
using namespace std;
 
 
set <string> memo;
 
void dp (string argumento)
{
 
    if (memo.find(argumento) != memo.end()) return;
    if (argumento.size() == 1)
    {
        memo.insert(argumento);
        return;
    }
 
    memo.insert(argumento);
 
    for (int i=0; i<argumento.size(); i++)
    {
        string aux = argumento;
 
        aux.erase(aux.begin()+i);
 
        dp(aux);
    }
    return;
}
 
int main ()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    string palavra;
 
    while (getline(cin, palavra))
    {
        dp(palavra);
        for (set<string>::iterator it = memo.begin(); it != memo.end(); ++it)
            cout << *it << '\n';
        cout << '\n';
        memo.clear();
    }
}
