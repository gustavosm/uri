#include <bits/stdc++.h>
 
#define DIR 0
#define UP 1
#define ESQ 2
#define DOWN 3
 
using namespace std;
 
 
char m[30][30];
int n;
void print()
{
    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j < n ; ++j)
            cout << (m[i][j] != 'X'? 'O' : 'X');
        cout << '\n';
    }
    cout << "@\n";
}
 
int main()
{
    int lin, col;
    int i, j;
    ios_base :: sync_with_stdio(0); cin.tie(0);
    while (1)
    {
        cin >> n;
         
        if (!n) return 0;
        
        
     
        lin = col = n / 2; ++col;
         
        i = j = n / 2;
        int go = DIR;
        int k = 1;
        while (1)
        {
            m[i][j] = 'X';
             
            print();
            if (i == n - 1 && j == n - 1) break;
             
            m[i][j] = 'O';
             
            switch(go)
            {
                case ESQ:
                    --j;
                    break;
                case DIR:
                    ++j;
                    break;
                case UP:
                    --i;
                    break;
                case DOWN:
                    ++i;
                    break;
            }
             
            if (j == col && i == lin)
            {
                if (go == DIR)
                {
                    lin -= k;
                    go = UP;
                }
                else if (go == UP)
                {
                    ++k;
                    col -= k;
                    go = ESQ;
                }
                else if (go == ESQ)
                {
                    lin += k;
                    go = DOWN;
                }
                else
                {
                    ++k;
                    col += k;
                    go = DIR;
                }
            }
        }
        m[i][j] = 'O';
         
    }
}
