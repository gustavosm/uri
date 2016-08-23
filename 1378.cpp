#include <bits/stdc++.h>

#define MAX 1010

using namespace std;

int X[MAX], Y[MAX];
long T[MAX][MAX];

long sqr(long v) { return v*v; }

int main()
{
    int n;
    while(1) 
    {
    	scanf("%d", &n);
    	if (!n) return 0;
    	
        for(int i = 0; i < n; ++i)
            scanf("%d %d", &X[i], &Y[i]);
        
        int sum = 0;
        for(int i = 0; i < n; ++i) 
        {
        	int aux = 0;
            for(int j = 0; j < n; ++j)
                T[i][aux++] = sqr(X[i] - X[j]) + sqr(Y[i] - Y[j]);
                
            sort(T[i], T[i] + aux);
            long last = -1L;
            int cnt = 0;
            
            for(int j = 0; j < aux; ++j) 
            {
                if (T[i][j] != last) 
                {
                    sum += (cnt * (cnt - 1)) / 2;
                    cnt = 0;
                }
                last = T[i][j];
                cnt++;
            }
            sum += (cnt * (cnt - 1)) / 2;
        }

        printf("%d\n", sum);
    }
    
}
