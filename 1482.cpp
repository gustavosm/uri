#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int mat[20][20], cost[20];
int N, M;
#define REP(i, N) for(int (i) = 0;  (i) < (N) ; (i) ++ )
int res;
bool flag;
void back(int last, int remain,int mask, int ans){
        res = max(ans, res);
        if( res == M){
        	flag = true;
        	return;
        }
        REP(i, N){
                if(!( mask & ( 1 << i ) )){
                        if( remain >= cost[i]+mat[last][i])
                                back(i, remain-cost[i]-mat[last][i], mask|(1<<i), ans+1);
                }
                if (flag) return;
        }
}
int main(){
        int i,j ,k;
        while(1){
                scanf("%i", &N); if(!N) return 0;
                REP(i, N) scanf("%i", &cost[i]);
                int aux[20]; REP(i, N) aux[i] = cost[i];
                sort(aux, aux+N);
                int co = 420;M=0;
                while(M < N && aux[M] <= co ){M++, co-=aux[M];}

                REP(i, N)REP(j, N) scanf("%i", &mat[i][j]);
                REP(k, N)REP(i, N)REP(j, N) mat[i][j] = min(mat[i][k]+mat[k][j], mat[i][j]);
                res = 0;
                flag = false;
                REP(i, N){
                        if( 420 >= cost[i] ){
                                back(i, 420-cost[i], 1<<i, 1);
                        }
                        if (flag) break;
                }
                printf("%i\n", res);
        }
        return 0;
}
